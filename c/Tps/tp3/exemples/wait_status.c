#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){

	pid_t n;
	int rep, status;
	n = fork();
	if(n == 0){
		printf("valeur : ");
		scanf("%d", &rep);
		exit(rep);
	}
	else if(n > 0){
		wait(&status);
		if(WIFEXITED(status)){
			printf("Fin normale, code de retour : %d\n", WEXITSTATUS(status));
		}
		else
			printf("Fin annormale\n");
	}


	return 0;
}