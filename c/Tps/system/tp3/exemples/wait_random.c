#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){
	pid_t fils, n = 1;
	int i;
	srand(time(NULL));
	printf("Hello, je suis %d\n", getpid());
	for(i = 0; i < 5; i++){
		if(n > 0){
			n = fork();
		}
		if(n == 0){
			printf("Je suis %d, mon père est %d, et je rentre en pause\n", getpid(), getppid());
			sleep(rand() % 10 + 1); // random entre 1 et 11
			exit(0);
		}
		else if(n > 0){
			while((fils = wait(NULL)) > 0){
				printf("Fin de %d\n", fils);
			}
		}
	}
}