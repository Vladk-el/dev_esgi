Chapitre 3 : Les processus

1 - Création

#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void); // --> Renvoi l'ID du porcessus actif
pid_t getppid(void); // --> Renvoi le PID du processus parent de celui en cours


#include <unistd.h>

pid_t fork(void);

	--> fork() crée un porcessus fils qui diffère du processus parent uniquement par ses valeurs PID 
		et PPID et par le fait que toutes les statistiques d'ulisation des ressources sont remises à 0.
		Les verrouillagers de fichier et les signaux en attente ne sont pas hérités.

		EN cas de succès, le PID du fils est renvoyé au processus parent, et 0 est renvoyé au processus fils. 
		En cas d'echec, -1 est renvoyé dans le contexte du parent, aucun processus fils n'est crée et errno contient le code d'erreur.


2 - Fin de processus

#include <stdlib.h>
void exit(int status);

	--> La fonction exit() termine normalement le programme en cours.
	La valeur status est renvoyée au processus arent.
	Les flux ouverts sont vidés et fermés.		


3 - Fonctions d'attente

#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int * status, int options);

La fonction wait suspend l'exécution du processus jusqu'à ce qu'un processus fils se termine, ou jusqu'à ce qu'un signal à intercepter arrive.
Si un processus fils s'est déja terminé au moment de l'appel, la fonction revient imédiatement.
Toutes les ressources utilisées par le fils sont libérées.

La fonction waitpid suspend l'exécution du processus courrant jusqu'à ce que le processus fils numéro pid se termine, ou jusqu'à ce qu'un signal à intercepter arrive.
Si le fils mentionné par pid s'est déja terminé au moment de l'appel, la fonction revient immédiatement.
Toutes les ressources utilisés par le fils sont libérés.
La valeur de pid peut aussi être l'une des suivantes : 
	-1 : attendre la fin de n'importe quel fils. Même comportement que wait().
	> 0 : attendre la fin du processus numéro pid.
La valeur de l'argument option options est généralement la constante suivante : 
	WNOHANG : ne pas bloquer si aucun fils ne s'est terminé.
Si status est non NULL, wait et waitpid y stockent l'information sur la terminaison du fils.
Cette information peut être analysée avec les maccros suivantes, qui réclament en argumentle buffer status(un int, et non pas un pointeur sur ce buffer) :
	WIFEXITED(status) : non nul si le fils s'est terminé normalement
	WIFEXITSTATUS(status) : donne le retour tel qu'il à été mentionné dans l'appel exit() ou dans le return
						  de la routine main.
						  Cette macro ne peut être évaluée que si WIFEXITED est non nul.
    WIFSIGNALED(status) : indique que le fils s'est terminé à cause d'un signal non intercepté.

EN cas de réussite, le PID du fils qui s'est terminé est renvoyé, en cas d'echec -1 est renvoyé et errno contient le code d'erreur.


4 - Chargement d'exécutable

#include <unistd.h>

extern char ** environ;

int execl(const char * path, const char * arg, ...);
int execlp(const char * file, const char * arg, ...);
int execle(const char * path, const char * arg, ..., char * const envp[]);

int execv(const char * path, char * const argv[]);
int execvp(const char * file, char * const argv[]);
int execve(const char * path, char * const argv[], char * const envp[]);

La famille de fonction exec remplace l'image mémoire du processus en cours par un nouveau processus.
L'argument initial de toutes ces fonctions est le chemin d'accès du fichier à exécuter.
Les arguments const char * arg ainsi que les ... des fonctions execl, execlp et execle peuvent être cues comme des arg0, arg1, .., argN.
Ensemble, ils décrivent une liste d'un ou plusieurs pointeurs sur des chaines de caractères terminées par des caarctères nuls, 
	qui constituent les arguments disponnibles pour le programme à exécuter.
Par convention, le premier argument doit pointer sur le nom du fichier associé au programme à exécuter.
La liste des arguments doit se termeiner pas uen pointeur NULL.

Les fonctions execv, execvp et execve utilisent un tableau de pointeurs sur des chaines de caractères terminées par des caractères nuls, 
	qui constituent le sraguments disponibles pour le programme à exécuter.
Par convention, le premier argument doit pointer sur le nom du fichier assocué au programme à exécuter.
Le tableau de pointeur doit se terminer pas un pointeur NULL.
Les fonctions execle et execve peuvent également indiquer l'environnement du processus à exécuter en faisant suivre le pointeur NULL qui termine la liste d'argumenrts, 
	ou le pointeur NULL de la table par un paramètre supplémentaire.
Ce paramètre est un tableau de pointeurs sur des chaines de caractères terminées par des caractères nuls, 
	qui doit se terminer par un pointeur NULL.
Les autres fonctions fournissent au nouveau processu l'environnement constituté par la variable externe environ.

Certaines d eces fonctions ont une sémantique spécifique.
Les focntions execlp et execvp agiront comme le shell dans la recherche du fichier exécutable si le nom fourni ne contient pas de slash (/).
Le chemin de recherche est spécifié dans la variable d'environnement PATH.
Si cette variable n'est pas définie, le chemin par défaut sera "/bin:/usr/bin".
De plus, certaines erreurs sont traités de manière spécifique.

Si la permission d'accès au fichier est refusée (execve renvois EACCES), ces fonctions continueront à parcourir le reste du chemin de recherche.
Si aucun fichier n'est trouvé, elles reviendront et errno contiendra le code d'erreur EACCES.

Si l'entête d'un fichier n'est pas reconnu (execve renvoie ENOEXEC), ces fonctions exécuteront un shell avec le chemin d'accès au fichier en tant que premier argument. 
Si ceci échoue, aucune recherche supplémentaire n'est effectuée.

Si l'une quelconque de ces fonctions exec revient à l'appelant, c'est qu'une erreur à eu lieu. 
La valeur de retour est -1 et errno contient le code d'erreur.




















