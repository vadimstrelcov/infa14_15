/* Client */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

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
		argv[1] - IP
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
	printf("Client: connection ... ok\n");

	char msg[]="Hello";
	printf("SENDALL = %d\n",sendall(client_sock, msg, sizeof(msg), MSG_OOB)==sizeof(msg));

	return 0;
}
