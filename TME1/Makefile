CC = gcc

main: tabmain.o tab.o
	gcc tab.o tabmain.o -o main

tab.o: tab.c 
	gcc -c tab.c

tabmain.o: tabmain.c 
	gcc -c tabmain.c

clean:
	rm *.o
	rm main

run:
	gcc -c tabmain.c
	gcc -c tab.c
	gcc tabmain.o tab.o -o main
	./main
	rm *.o
	rm main