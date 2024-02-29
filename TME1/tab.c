#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void init(){
  srand(time(NULL));
}

void InitTab(int *tab, int size){
  if(tab)
    for(int i = 0; i < size; i++)
        *(tab + i) = rand() % 10;
  
}

void PrintTab(int *tab, int size){
    char delim[] = "\0\0";

    printf("[");
        for(int i = 0; i < size; i++){
        printf("%s%d", delim, *(tab + i));
        *delim = ',';
    }
    printf("]");
}

int SumTab(int *tab, int size){
    int s = 0;
    for(int i = 0; i < size; i++)
        s += *(tab + i);

    return s;
}

int MinSumTab(int *min, int *tab, int size){
    int s = 0;

    *min = 0x7FFFFFFF;

    for(int i = 0; i < size; i++){
        s+= *(tab + i);
        *min = *min > *(tab + i) ? *(tab + i) : *min;
    }

    return s;
}