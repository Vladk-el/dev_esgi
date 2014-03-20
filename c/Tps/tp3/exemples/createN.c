#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]){

	int i = 5, j = 0;
	if(argv[1]){
		if(strcmp(argv[1], "yes") == 0){
			printf("Saisissez i : ");
			scanf("%d", &i);
			printf("i : %d\n", i);
		}
	}

	pid_t n = 1;
	for(j = 0; j < i; j++){
		if(n > 0){ // cas du père
			n = fork();
			if(n == 0){
				printf("Je suis le fils %d de %d !\n", getpid(), getppid());
			}
		}
	}


	return 0;
}