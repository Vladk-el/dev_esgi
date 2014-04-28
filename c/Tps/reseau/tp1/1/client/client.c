#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

int main(int argc, char * argv[]){

	int sockfd;
	struct sockaddr_in serv;
	char IPserv[16] = "127.0.0.1";

	serv.sin_family = AF_INET;
	serv.sin_port = htons(1234);

	inet_pton(AF_INET, IPserv, &serv.sin_addr);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(sockfd, (struct sockaddr *) &serv, sizeof(serv));

	return 0;
}