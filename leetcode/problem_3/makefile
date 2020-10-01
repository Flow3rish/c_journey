default: solution.o hashtable/hashtable.o
	gcc -o solution solution.o hashtable/hashtable.o

solution.o: solution.c
	gcc -c -o solution.o solution.c


hashtable.o: hashtable/hashtable.c hashtable/hashtable.h
	gcc -c -o hashtable/hashtable.o hashtable/hashtable.c


run:
	./solution