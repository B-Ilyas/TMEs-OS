/**
*  ===========================================
*           BAMHAOUD Yassine 21110685
*            BENYAHIA Ilyas 21118889
*  ===========================================
**/

#include <malloc.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "tab.h"

void PrintMem(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    long mem = usage.ru_maxrss;

    printf("Mémoire utilisé : %ld\n", mem);
}

int main(int argc, char *argv[]){
    printf(" === Début du programme === \n");
    // INIT
    init();

    // TEST InitTab, PrintTab
    PrintMem(); // 2492
    int s_tab[NMAX] = {0};


    InitTab(s_tab, NMAX);
    printf("Stack : ");
    PrintTab(s_tab, NMAX);
    printf("\n");

    PrintMem(); // 5204

    int *tab;
    if((tab = (int *) malloc(NMAX *sizeof(int)))){
        InitTab(tab, NMAX);
        printf("Malloc : ");
        PrintTab(tab, NMAX);
    }
    printf("\n\n");

    // TEST SUM
    printf("Somme de Stack : %d\n", SumTab(s_tab, NMAX));
    printf("Somme de Malloc : %d\n", SumTab(tab, NMAX));
    
    int min;
    int sum;

    sum = MinSumTab(&min, s_tab, NMAX);
    printf("(min) Somme de Stack : %d (min : %d)\n", sum, min);

    sum = MinSumTab(&min, tab, NMAX);
    printf("(min) Somme de Malloc : %d (min : %d)\n\n", sum, min);

    // TEST PRINT MEM
    PrintMem(); // 9096

    printf(" === Fin du programme === \n");

    return 0;
}