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
	printf("Server\n");

	struct sockaddr_in myaddr;
	int sockfd;
	char addrIP[16] = "127.0.0.1";

	// 1) socket(Famille de protocol, type de socket, protocole(=0))
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// 2) bind(Descripteur de socket, structure d'adresse générique, taille de la structure)
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(1234);
	inet_pton(AF_INET, addrIP, &myaddr.sin_addr);

	bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));

	// 3) listen(descripteur de socket active, nombre maximal de connexions)
	listen(sockfd, 20);

	// 4) accept(descripteur de socket passive, structure d'adresse générique qui contiendra les coords du client, taille de cette structure)
	int confd;
	struct sockaddr_in client_addr;
	int client_size;
	printf("Server is waiting for connections . . .\n");
	for(;;){
		confd = accept(sockfd, (struct sockaddr *)&client_addr, &client_size);
		printf("New connection initialized !\n");
		printf("Port du client : %d\n", client_addr.sin_port);
		char ipAddr[16];
		inet_ntop(AF_INET, &client_addr.sin_addr, ipAddr, 16*sizeof(char));
		printf("Adresse du client : %s\n", ipAddr);
		// traitement de la connexion
		// ...
	}

}

