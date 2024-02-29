//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "fcts.h"
/*
------1.1------
time sleep 5 

real	0m5,003s
user	0m0,000s
sys	    0m0,002s

------1.2------
time ./loopcpu &
L'execution est longue...
*/

void loopcpu(){
	for (int i=0; i < 5000000000; i++){
	}
}

int main(){
	loopcpu();
}

