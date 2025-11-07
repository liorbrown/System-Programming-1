prog: main.o mylib.o
	gcc main.o mylib.o -o prog

main.o: main.c mylib.h
	gcc -c main.c

mylib.o: mylib.c mylib.h
	gcc -c mylib.c -o mylib.o

clean:
	rm -f *.o prog