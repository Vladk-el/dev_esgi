/*
	Vous allez écrire un client/serveur simple.
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
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

int main(){
	printf("Hello\n");

	struct sockaddr_in myaddr;
	int sockfd;
	char addrIP[16] = "127.0.0.1";
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(1234);
	inet_pton(AF_INET, addrIP, &myaddr.sin_addr);
	bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
	listen(sockfd, 20);

	int confd;
	for(;;){
		confd = accept(sockfd, NULL, NULL);
		// traitement de la connexion
		// ...
	}

}

