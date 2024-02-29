CFLAGS = -Wall 

all: mgrep zomb

mgrep: mgrep.o 
	gcc $(CFLAGS) -o mgrep mgrep.o
	
zomb: zomb.o 
	gcc $(CFLAGS) -o zomb zomb.o 

mgrep.o: mgrep.c
	gcc $(CFLAGS) -c mgrep.c

zomb.o: zomb.c
	gcc $(CFLAGS) -c zomb.c
	
clean: 
	rm -f mgrep.o mgrep zomb zomb.o
