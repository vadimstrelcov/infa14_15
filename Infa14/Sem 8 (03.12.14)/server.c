/* Server */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

int sendall(int s, char *buf, int len, int flags) {
	int total=0;
	int n;
	while (total<len) {
		n=send(s, buf+total, len-total, flags);
		if (n==-1) { 
			break;
		}
		total+=n;
	}
	return (n==-1) ? -1 : total; 
}

const int length_msg=100;

int main(int argc, char **argv) {
	/*
		argv[1] - port
	*/
	int serv_sock=socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock<0) {
		printf("SERVER: Socket() failed : %d\n",errno);
		return 1;
	}
	struct sockaddr_in serv_addr;
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
		printf("SERVER: Bind() failed: %d\n", errno);
		return 1;
	}
	
	const int number_clients=3;
	listen(serv_sock, number_clients);
	struct sockaddr_in client_addr[number_clients];
	int client_len[number_clients], i;
	for (i=0;i<number_clients;i++) {
		client_len[i]=sizeof(client_addr[i]);
	}
	int new_sock[number_clients];
	for (i=0;i<number_clients;i++) {
		new_sock[i]=accept(serv_sock, (struct sockaddr *)&client_addr[i], &client_len[i]);//maybe NULL NULL
		if (new_sock[i]<0) {
			printf("SERVER: Accept() failed: %d\n",errno);
		} else {
			char msg[2];
			msg[0]=i+'0';
			msg[1]='\0';
			printf("msg=%s\n",msg);
			int result_send=sendall(new_sock[i], msg, sizeof(msg), MSG_OOB);
			printf("SEND ID to %d ... ",i);
			if (result_send==sizeof(msg)) {
				printf("OK\n");
			} else {
				printf("FAILED :(\n");
			}
		}
	}
	
	int index_proc_id;
	for (index_proc_id=0;index_proc_id<number_clients;index_proc_id++) {
		int z=fork();
		if (z<0) {
			printf("SERVER: fork() failed\n");
			return 1;
		} else {
			if (z==0) {
				while (1) {
					char MSG[length_msg];
					memset(MSG,'\0',length_msg);
					int q=recv(new_sock[index_proc_id], MSG, length_msg, 0);
					if (q>0 && (int)strlen(MSG)>0) {
						printf("Accept MSG from ID=%d: (%d) \"%s\"\n",index_proc_id,q,MSG);
						if (strcmp(MSG,"")) {
							int w=MSG[0]-'0';
							if (w<number_clients) {
								MSG[0]=index_proc_id+'0';
								int result_send=sendall(new_sock[w], MSG, sizeof(MSG), MSG_OOB);
								printf("Server: send message \"%s\" to ID=%d. ",MSG-sizeof(char),w);
								if (result_send==sizeof(MSG)) {
									printf("OK\n");
								} else {
									printf("Send only %d bytes\n",result_send);
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}
