//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAXFILS 1

void mgreps(char* c, char* lf[], int na) {
    for (int i = 2; i < na ; i++) {
    	struct rusage r;
        int p = fork();
        if (p == -1) {
            perror("fork()");
            exit(1);
        }
        if (p == 0) {
            execl("/bin/grep", "grep", c, lf[i], NULL);
            perror("execl()");
            exit(1);
        } else {
            wait3(NULL,0, &r);
            printf("Temps User : %f\nTemps System : %f\n", r.ru_utime.tv_sec + 1E-6*r.ru_utime.tv_usec, r.ru_stime.tv_sec + 1E-6*r.ru_stime.tv_usec);
        }
    }
}

void mgreppc(char* c, char* lf[], int na) {
    for (int i = 2; i < MAXFILS + 2 ; i++) {
    	start :
        	int p = fork();
        	if (p == -1) {
            	perror("fork()");
            	exit(1);
        	}
        	if (p == 0) {
            	execl("/bin/grep", "grep", c, lf[i], NULL);
            	perror("execl()");
            	exit(i);
        	} else {
            	wait(NULL);  
        	}
        	if (lf[i+1] != NULL){
        		i++;
        		goto start;
        }
    }
    
}

int main(int argc, char* argv[]) {
    mgreps(argv[1], argv, argc);
    //mgreppc(argv[1], argv, argc);
    return EXIT_SUCCESS;
}









