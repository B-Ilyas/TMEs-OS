#21118889 BENYAHIA Ilyas

CC = gcc

mytimes: mytimes.o cmd.o
	gcc -Wall mytimes.o cmd.o -o mytimes

loopcpu: loopcpu.o
	gcc -Wall loopcpu.o -o loopcpu

loopsys: loopsys.o
	gcc -Wall loopsys.o -o loopsys

loopcpu.o: loopcpu.c
	gcc -Wall -c loopcpu.c
	
loopsys.o: loopsys.c
	gcc -Wall -c loopsys.c
	
cmd.o: cmd.c 
	gcc -Wall -c cmd.c

mytimes.o: mytimes.c 
	gcc -Wall -c mytimes.c

clean:
	rm *.o
	rm mytimes


