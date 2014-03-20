#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	pid_t n;
	int a, b, result, status;

	printf("Bonjour, veuillez entrer 2 entiers, le programme renverra le résultat de la division\n");
	printf("Entier 1 : ");
	scanf("%d", &a);

	while(1){
		printf("(%d)Entier 2 : ", getpid());
		scanf("%d", &b);
		n = fork();

		if(n == 0){ // fils
			if(b == 0){
				printf("(%d)Veuillez entrer un entier différent de 0 svp.\n", getpid());
				exit(1);
			}
			result = a / b;
			printf("%d)Résultat : %d\n", getpid(), result);
			exit(0);
		}
		else if(n > 0){ // père
			//wait(&status);
			//waitpid(-1, &status, 0); // attend la fin de n'importe quel processus fils
			waitpid(n, &status, 0); // attend la fin du processus fils 'n'
			if(WIFEXITED(status)){
				if(WEXITSTATUS(status) == 0){
					printf("Au revoir !\n");
					break;
				}
			}
		}
	}


	return 0;
}

/*
	SI status est non nul, wait et waitpid y stockent l'information sur la terminaison du fils.

	WIFEXITED(status) ==> non null si le fils s'est terminé normalement

	WEXITSTATUS(status) ==> donne le code de retour tel qu'il a été mentionné dans l'appel exit().
		Ne peut être évalué que si WIFEXITED est non nul.

	WIFSIGNALED(status) ==> indique que le fils s'est terminé à cause d'un signal bnon intercepté.

*/