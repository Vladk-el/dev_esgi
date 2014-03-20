#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void createDictionnary();
void readDictionnary();
void modifyDictionnary();

int main(){

	char choice[50];

	printf("What do you want to do ? (add / display / modify) ");
	scanf("%s", choice);
	if(strcmp(choice, "add") == 0)
		createDictionnary();
	else if(strcmp(choice, "display") == 0)
		readDictionnary();
	else if(strcmp(choice, "modify") == 0)
		modifyDictionnary();
}

void createDictionnary(){

	FILE * f;
	f = fopen("dico", "a");
	char fr[50], en[50];
	char again[50] = "yes";

	if(f == NULL)
		return;
	
	while(strcmp(again, "yes") == 0){
		printf("Entrez le mot en français : ");
		scanf("%s", fr);

		printf("Entrez la traduction en anglais : ");
		scanf("%s", en);

		//fwrite(fr, strlen(fr), 1, f);
		fprintf(f, "%s   %s\n", fr, en);

		printf("Continue ? (yes/no) ");
		scanf("%s", again);
	}
}

void readDictionnary(){
	FILE * f;
	f = fopen("dico", "r");
	char fr[50], en[50];
	int endPos;
	
	if(f == NULL)
		return;

	fseek(f, 0, SEEK_END);
	endPos = ftell(f);
	fseek(f, 0, SEEK_SET);

	while(ftell(f) != endPos){
		fscanf(f, "%s   %s\n", fr, en);
		printf("%s   %s\n", fr, en);
	}
}

void modifyDictionnary(){
	FILE * f;
	f = fopen("dico", "r");
	char fr[50], en[50];
	int endPos, cpt = 0, index;
	char ** tab;
	int * pos;

	if(f == NULL)
		return;
	
	fseek(f, 0, SEEK_END);
	endPos = ftell(f);
	fseek(f, 0, SEEK_SET);

	while(ftell(f) != endPos){
		fscanf(f, "%s   %s\n", fr, en);
		cpt++;
		cpt++;
	}

	fseek(f, 0, SEEK_SET);
	tab = malloc(cpt * sizeof(char[50]));
	cpt = 0;

	while(ftell(f) != endPos){
		fscanf(f, "%s   %s\n", fr, en);
		printf("%d - %s\n", cpt, fr);
		tab[cpt] = fr;
		cpt++;
		printf("%d - %s\n", cpt, en);
		tab[cpt] = en;
		cpt++;
	}

	int i = 0;
	for(i = 0; i < cpt; i++)
		printf("%s", tab[i]);

	printf("Index du mot a modifier : ");
	scanf("%d", &index);
	printf("%s\n", tab[index]);
	printf("Tapez le nouveau mot : ");
	scanf("%s", tab[index]);

	printf("Les modifications ont bien été appliquées : \n");
	for(i = 0; i < cpt; i++)
		printf("%s\n", tab[i]);

}

















