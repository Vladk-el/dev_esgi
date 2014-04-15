#include <stdlib.h>
#include <stdio.h>

/*
	Ecrire un programme C qui utilise 3 processus H, M, S qui incrémentent les 3 
	« aiguilles » d'une horloge. S reçoit un signal SIGALRM chaque seconde et émet un 
	signal à M quand son compteur passe de 59 à 0. Quand M reçoit un signal, il 
	incrémente son compteur. Quand son compteur passe de 59 à 0, M envoie un signal 
	à H. 
*/

void detourneS();
void detourneM();
void detourneH();

int LIMITE = 6;
int cpt = 0;

int main(){

	pid_t h, m, s;

	printf("Hello World\n");

	printf("Hello : %d\n", getpid());

	h = fork();

	if(h == 0){
		printf("Hello, je suis H : %d et voici mon père : %d\n", getpid(), getppid());
		signal(SIGALRM, detourneH);
		m = fork();
		if(m == 0){
			printf("Hello, je suis M : %d et voici mon père : %d\n", getpid(), getppid());
			signal(SIGALRM, detourneM);
			s = fork();
			if(s == 0){
				printf("Hello, je suis S : %d et voici mon père : %d\n", getpid(), getppid());
				signal(SIGALRM, detourneS);
				while(1){
					signal(SIGALRM, detourneS);
					sleep(1);
					kill(getpid(), SIGALRM);
				}
			}
		}
	}

	while(1);
	

}

void detourneS(){
	if(cpt == LIMITE-1){
		kill(getppid(), SIGALRM);
		cpt = 0;
	}
	else
		cpt += 1;

	printf("S : %d\n", cpt);
}

void detourneM(){
	if(cpt == LIMITE-1){
		kill(getppid(), SIGALRM);
		cpt = 0;
	}
	else
		cpt += 1;

	printf("M : %d\n", cpt);
}

void detourneH(){
	cpt += 1;
	printf("H : %d\n", cpt);
}






