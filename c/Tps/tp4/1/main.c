#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/*
	Ecrire un programme qui compte les signaux qu'il reçoit . A chaque réception d’un
	signal, il affiche le nombre de fois où il l’a reçu. Vous ferez attention aux signaux qui
	ne sont pas détournables.
*/

void compte(int sig);
void displayTab();
void test();

int tab[NSIG] = {0};

int main(){
	int i = 0;
	
	//displayTab();

	for(i = 0; i < NSIG; i++){
		signal(i, compte);
		//printf("%d\n", i);
	}

	test();

	while(1);
}

void compte(int sig){
	tab[sig] += 1;
	printf("Signal %d, reçut %d fois\n", sig, tab[sig]);

	if(sig == 2 || sig == 20){
		signal(sig, SIG_DFL);
		//displayTab();
		if(sig == 2)
			raise(2);
		else if(sig == 20)
			raise(20);
	}
	
}

void displayTab(){
	int j = 0;
	
	for(j = 0; j < NSIG; j++){
		printf("Signal %d : %d\n", j, tab[j]);
	}
}

void test(){
	raise(1);
	raise(3);
	raise(7);
	raise(1);
	raise(7);
	raise(1);
	raise(1);
	raise(1);
	raise(1);
	raise(13);
	raise(11);
	raise(13);
	raise(14);
	raise(14);

}
