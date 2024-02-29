//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//Un processus zombie est un processus dont l'execution s'est fini en ayant appliqué la fonction exit() et dont le père de ce processus n'a pas pris encore connaissance de sa terminaison avec la fonction wait()

int main(int argc, char* argv[]) {
	int p, i;
	for (i =0; i<2; i++){
		p = fork();
		if (p == -1) {
			perror("fork()");
		}
		if (p == 0) {
			exit(0);
		}
	}
	sleep(10);
	wait(NULL);
    return EXIT_SUCCESS;
}
