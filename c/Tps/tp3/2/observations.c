#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){
	pid_t n;

	n = fork();

	while(1){
		if(n == 0){ // fils
			printf("Je suis le fils : %d et voici mon père : %d\n", getpid(), getppid());
		}
		else if(n > 0){ // père
			printf("Je suis le père : %d et voici mon fils : %d\n", getpid(), n);
		}
		sleep(2);
	}
}


