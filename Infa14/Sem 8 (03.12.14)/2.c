/* Server */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

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
	}

	listen(serv_sock, 1); //1? maybe 2?
	struct sockaddr_in client_addr;
	int client_len=sizeof(client_addr);
	int new_sock=accept(serv_sock, (struct sockaddr *)&client_addr, &client_len);//maybe NULL NULL
	if (new_sock<0) {
		printf("SERVER: Accept() failed: %d\n",errno);
	}
	
	char MSG[10]; int len;
	recv(new_sock, MSG, 6, 0);
	printf("%s\n",MSG);
	
	return 0;
}
