#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/*
	Ecrire un programme C qui crée un processus. Le père affichera les entiers pairs
	compris entre 1 et 100, le fils affichera les entiers impairs compris dans le même
	intervalle. Synchroniser les processus à l'aide des signaux pour que l'affichage soit 1
	2 3 ... 100.
*/

void detourne(int sig);

int i = 0;
int LIMITE = 20;

int main(){
	printf("Tp 4 exo 2 :  \n");
	pid_t n;

	n = fork();

	//printf("%d\n", i);

	// fixer une tempo ou qqc pour être sur d'avoir bien initialisé le fils au démarrage

	i = (n == 0)?-1:0;

	signal(1, detourne);

	if(n == 0){
		pause();
	}else{
		sleep(0.1);
	}

	while( i < LIMITE + 1){
		if(n == 0){
			printf("fils : %d\n", i);
			if(i >= LIMITE){
				kill(getppid(), 9);
				raise(9);
			}else{
				kill(getppid(), 1);
				pause();
			}
				
		} // fils
		else if(n > 0){
			printf("père : %d\n", i);
			if(i >= LIMITE){
				kill(n, 9);
				raise(9);
			}else{
				kill(n, 1);
				pause();
			}
		} // père
	}
	return 0;
}

void detourne(int sig){
	printf("DETOURNE\n");
	i += 2;
}