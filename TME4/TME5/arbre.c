//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createTree(int level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <level>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int level = atoi(argv[1]);

    if (level <= 0) {
        fprintf(stderr, "Niveau négatif\n");
        exit(EXIT_FAILURE);
    }

    createTree(level);

    return 0;
}

void createTree(int level) {
    if (level == 0) {
        sleep(30);
        return;
    }

    pid_t child_pid1, child_pid2;

    if ((child_pid1 = fork()) == 0) {
        createTree(level - 1);
        exit(EXIT_SUCCESS);
    } else if (child_pid1 > 0) {
        if ((child_pid2 = fork()) == 0) {
            createTree(level - 1);
            exit(EXIT_SUCCESS);
        }
    }

    sleep(30);
    wait(NULL);
    wait(NULL);
}
