#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <time.h>


char rand_();


int BEGIN_INDEX = 0, END_INDEX = 15, BUF_SIZE = 27;
char tab[] = "0123456789ABCDEF";


int main(int argc, char * args[]){
	printf("hello wpa_rand\n");

	int desc, i;
	int size = 2147483647;
	char buffer[] = "00000000000000000000000000\n\0";


	remove("dico_wpa");
	desc = open("dico_wpa_", O_WRONLY | O_CREAT | O_APPEND, 0777);
	
	/*if(desc > 0)
		return 2;

	if(argc != 2){
		write(STDERR_FILENO, "Please specify the size of solutions you need\n", 46); // sortie d'erreur
		exit(2); // fin du programme
	}

	// max size : 2 147 483 647

	size = strtoumax(args[1], NULL, 100000000000000);
	if (num == UINTMAX_MAX && errno == ERANGE){
		write(STDERR_FILENO, "Please specify a correct size\n", 31); // sortie d'erreur
		exit(2);
	}*/

	srand(time(NULL));
	for(i = 0; i < size; i++){
		//printf("%c\n", rand_());
		buffer[0] = rand_();
		buffer[1] = rand_();
		buffer[2] = rand_();
		buffer[3] = rand_();
		buffer[4] = rand_();
		buffer[5] = rand_();
		buffer[6] = rand_();
		buffer[7] = rand_();
		buffer[8] = rand_();
		buffer[9] = rand_();
		buffer[10] = rand_();
		buffer[11] = rand_();
		buffer[12] = rand_();
		buffer[13] = rand_();
		buffer[14] = rand_();
		buffer[15] = rand_();
		buffer[16] = rand_();
		buffer[17] = rand_();
		buffer[18] = rand_();
		buffer[19] = rand_();
		buffer[20] = rand_();
		buffer[21] = rand_();
		buffer[22] = rand_();
		buffer[23] = rand_();
		buffer[24] = rand_();
		buffer[25] = rand_();
		buffer[26] = '\n';
		buffer[27] = '\0';

		write(desc, buffer, BUF_SIZE);
	}

	close(desc);

	// faire une archi père / fils avec un wait pour attendre la fin des opérations

	//execl("uniq", "uniq", "dico_wpa_", "dico_wpa", NULL);

	//remove("dico_wpa_");

	//execl("wc", "wc", "dico_wpa", NULL);

	return 0;
}

char rand_(){
	return tab[rand()%(END_INDEX-BEGIN_INDEX)+BEGIN_INDEX];
}


/*
	Pour tester le nombre de lignes : wc fich
	Pour supprimer les doublons : uniq fich_src fich_dest
	Pour spliter le fichier en plusieurs parties : 
		split -b byteSize fich
		split -l nbLignes fich

	Pour compresser   : bzip2 fich
	Pour décompresser : bunzip2 fich.bz2
*/












