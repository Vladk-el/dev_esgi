#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t n;
	int i = 5;
	printf("Bonjour, je suis %d \n", getpid());

	n = fork();

	if(n == 0){ //on est dans le fils
		printf("Je suis le fils : %d, et voici mon père : %d\n", getpid(), getppid());
		i += 3;
	}
	else if(n > 0){ // on est dans le père
		printf("Je suis le père : %d, et voici mon fils : %d\n", getpid(), n);
		i -= 2;
	}
	printf("Au revoir, je suis : %d et mon i vaut : %d\n", getpid(), i);

	return 0;
}