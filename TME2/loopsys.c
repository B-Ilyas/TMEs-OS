//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "fcts.h"
/* 
------1.3------
time ./loopsys

real	0m0,995s
user	0m0,995s
sys	0m0,000s
*/

void loopsys(){
	for (int i=0; i < 50000000; i++){
		getpid();
	}
}

int main(){
	loopsys();
}
