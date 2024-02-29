//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/times.h>
#include <time.h>
#include "fcts.h"

int main(int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		start_clock();
		lance_cmd(argv[i]);
		end_clock(argv[i]);
	}
	return 0;
}

/*
------5.1------
Sa priorité est de 80
------5.2------
Elle est maintenant de 99
*/
