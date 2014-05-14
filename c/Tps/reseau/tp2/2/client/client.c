#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <string.h>

int main(int argc, char * argv[]){

	int sockfd, n, i;
	char recu[100];
	struct sockaddr_in servaddr;

	if(argc != 3){
		printf("Usage : client Adresse Port\n");
		exit(-1);
	}

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	//transforme l'adresse IP X.X.X.X passÃ©e en parametre en adresse comprehensible
	//par le systeme (32 bits)

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Erreur de socket\n");
		exit(-1);
	}

	if(connect(sockfd, (struct sockaddr *) & servaddr, sizeof(servaddr)) < 0){
		printf("Erreur de connexion\n");
	}

		// Lecture
		if((n = read(sockfd, recu, 100)) > 0){
			recu[n] = '\0';
			printf("Connexion OK : ");
			fputs(recu, stdout);
		}

	while((n = read(fileno(stdin), recu, sizeof(recu))) > 0){
		recu[n] = '\0';
		write(sockfd, recu, strlen(recu));
		n = read(sockfd, recu, 100);
		recu[n] = '\0';	
		printf(" donnees recues : ");
		fputs(recu, stdout);
	}

	//printf("N = %d\n", n);

	if(n < 0){
		printf("Erreur de lecture\n");
	}

	exit(0);


	return 0;
}