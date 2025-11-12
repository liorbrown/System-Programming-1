CC = gcc
CFLAGS = -c -g
PROG = pizza

$(PROG): main.o inputs.o meal.o
	$(CC) $^ -o $@

main.o: main.c inputs.h meal.h
	$(CC) $(CFLAGS) $< -o $@

meal.o: meal.c
	$(CC) $(CFLAGS) $< -o $@

inputs.o: inputs.c
	$(CC) $(CFLAGS) $< -o $@