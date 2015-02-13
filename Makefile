all: Problem1

Problem1: Problem1.o
	gcc Problem1.o -o Problem1


Problem1.o: Problem1.c
	gcc -c Problem1.c

clean:
	rm *.o Problem1
