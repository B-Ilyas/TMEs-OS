//21118889 BENYAHIA Ilyas

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/times.h>
#include <string.h>
#include <time.h>

static clock_t st_time;
static clock_t en_time;
static struct tms st_cpu;
static struct tms en_cpu;

float time_diff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) + 0.000001 * (end->tv_usec - start->tv_usec);
}

void lance_cmd(char* cmd){
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	int m = system(cmd);
	if (m){
		printf("La commande n'a pas pu être executé !\n");
		return;
	}
	gettimeofday(&end, NULL);
	printf("Temps mis par l'execution de la commande : %.1f sec\n",  time_diff(&start, &end));
}

void start_clock(){
    st_time = times(&st_cpu);
}

void end_clock(char *msg) {
    en_time = times(&en_cpu);
    long int s = sysconf(_SC_CLK_TCK);
    printf("Statistique de '%s' :\nTemps Total: %.6f\nTemps utilisateur : %.6f\nTemps systeme : %.6f\nTemps utilisateur fils : %.6f\nTemps systeme fils: %.6f\n", msg, ((en_time - st_time)/(double)s), ((en_cpu.tms_utime - st_cpu.tms_utime)/(double)s), ((en_cpu.tms_stime - st_cpu.tms_stime)/(double)s), ((en_cpu.tms_cutime - st_cpu.tms_cutime)/(double)s), ((en_cpu.tms_cstime - st_cpu.tms_cstime)/(double)s));
}



