//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/times.h>

#define MAX_CMD_LENGTH 100

void execCmd(char** toks);
void printExecTime(clock_t start, clock_t end);

int main() {
    char input[MAX_CMD_LENGTH];

    while (1) {
        printf("Entrez une commande (ou 'quit' pour quitter): ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; //retire \n de la commande entré
        if (strcmp(input, "quit") == 0) {
            break;
        }
		
        int background = (input[strlen(input) - 1] == '&'); // vérification de '&'

        pid_t pid = fork();

        if (pid == 0) {
            if (background) {
                input[strlen(input) - 1] = '\0'; //retire le '&' par '\0'
            }
            
            char* token = strtok(input, " ");
            char* args[4];
            int i = 0;

            while (token != NULL) {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;

			execCmd(args);
            exit(EXIT_SUCCESS);
        } else if (pid > 0) {
            if (!background) {
                struct tms start, end;
                times(&start);
                wait(NULL);
                times(&end);
                printExecTime(start.tms_utime, end.tms_utime);
            }
        } else {
            perror("fork()");
        }
    }
    return 0;
}

void execCmd(char** toks) {
    execlp(toks[0], toks[0], toks[1], toks[2],toks[3],(char *)NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
}

void printExecTime(clock_t start, clock_t end) {
    clock_t total_time = end - start;
    printf("Temps d'execution: %f secondes\n", (double)total_time / sysconf(_SC_CLK_TCK));
}
