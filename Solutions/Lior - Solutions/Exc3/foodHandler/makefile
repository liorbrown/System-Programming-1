CC = gcc
CFLAGS = -c -g
PROG = pizza

.PHONY: all clean

all : $(PROG)

$(PROG): main.o inputs.o meal.o
	$(CC) $^ -o $@

main.o: main.c inputs.h meal.h
	$(CC) $(CFLAGS) $< -o $@

meal.o: meal.c
	$(CC) $(CFLAGS) $< -o $@

inputs.o: inputs.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(PROG)