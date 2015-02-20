/* Client */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>

const int length_msg=100;

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

int main(int argc, char **argv) { 
	/*
		argv[1] - domain
		argv[2] - port
	*/ 
	int client_sock=socket(AF_INET, SOCK_STREAM, 0);
	if (client_sock<0) {
		printf("Client: Socket() failed : %d\n", errno);
		return 1;
	}

	struct sockaddr_in serv_addr;
	struct hostent *server;
	server=gethostbyname(argv[1]);
    if (server==NULL) {
        printf("Client: server is null\n");
        return 1;
    }
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(client_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
		printf("Client: Connect() failed : %d\n", errno);
		return 1;
	}
	int my_ID, len=2;
	char MSG[2];
	recv(client_sock, MSG, len, 0);
	printf("MSG=%s\n",MSG);
	my_ID=MSG[0]-'0';
	printf("Client: connection ... ok (ID=%d)\n",my_ID);
	
	int proc_id=fork();
	if (proc_id<0) {
		printf("Client: fork() failed\n");
	} else {
		if (proc_id==0) { //child
			while (1) {
				char MSG[length_msg];
				int q=recv(client_sock, MSG, length_msg, 0);
				if (q>0) {
					if (!strcmp(MSG,"SERVER:QUIT_USER")) {
						printf("Bye :)\n");
						kill(getppid(), 9);
						return 0;
					}
					printf("Accept MSG: \"%s\" from ID=%d\n",MSG+sizeof(char),(int)(MSG[0]-'0'));
				}
			}
		} else { //parent
			while (1) {
				char msg[length_msg];
				gets(msg);
				printf("Client: message \"%s\" send to server. ",msg);
				int result_send=sendall(client_sock, msg, sizeof(msg), MSG_OOB);
				if (result_send==sizeof(msg)) {
					printf("OK\n");
				} else {
					printf("Send only %d bytes\n",result_send);
				}
			}
		}
	}
	
	return 0;
}
