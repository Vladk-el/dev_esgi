/*
	Vous allez écrire un client/serveur simple, mais qui gère plusieurs connexions simultanément.
	Une fois la connexion établie, le serveur affiche l'identité du client (Adresse 
	IP+Port).
	Il envoie au client la date et l'heure courantes.
	Le client affiche le résultat.
	Le port d'écoute du serveur devra être paramétrable sur la ligne de commande
	De même pour l'adresse IP et le port où veut se connecter le client.
	Exemples :
	$ ./client 127.0.0.1 1234
	Fri Jan 16 11:27:46 2009
	$ ./serveur 1234
	connexion de 127.0.0.1, port 43329

	Pour trouver le serveur : 
		netstat -at | grep 1234
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <string.h>


int main(int argc, char * argv[]){
	printf("Server\n");

	int listen_fd, conn_fd, port, n;
	socklen_t len;
	struct sockaddr_in serv_addr, client_addr;
	char addrIP[16], buff[50];
	time_t tempo;

	if(argc != 2){
		printf("Usage : server Port\n");
		exit(-1);
	}

	// 1) socket(Famille de protocol, type de socket, protocole(=0))
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	// 2) bind(Descripteur de socket, structure d'adresse générique, taille de la structure)
	bind(listen_fd, (struct sockaddr *) & serv_addr, sizeof(serv_addr));

	// 3) listen(descripteur de socket active, nombre maximal de connexions)
	listen(listen_fd, 10);
	// 4) accept(descripteur de socket passive, structure d'adresse générique qui contiendra les coords du client, taille de cette structure)

	for(;;){
		len = sizeof(client_addr);
		conn_fd = accept(listen_fd, (struct sockaddr *) & client_addr, (socklen_t *) &len);
		n = fork();
		if(n == 0){ // fils
			printf("Passage au fils\n");
			port = ntohs(client_addr.sin_port);
			inet_ntop(AF_INET, &client_addr.sin_addr, addrIP, sizeof(addrIP));
			printf("Connexion de %s, port %d\n", addrIP, port);

			tempo = time(NULL);
			snprintf(buff, sizeof(buff), "%.24s\n", ctime(&tempo));
			//printf("buffer : %ssize : %d\n", buff, strlen(buff));
			//printf("jhzeqhjzbhqvbhbv\n");
			write(conn_fd, buff, strlen(buff)); // strlen(buff)
			close(listen_fd);
			close(conn_fd);
			exit(0);
		}
		if(n > 0){ // père
			close(conn_fd);
		}
		
	}
}

