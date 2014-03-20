#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	pid_t n;
	n = fork();
	if(n == 0){
		printf("Je suis le fils !\n");
	}
	else if(n > 0){
		printf("Je suis le père !\n");
	}
	else{
		printf("Erreur de fork()\n");
	}

	return 0;
}