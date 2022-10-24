CC = gcc
CFLAGS = -O2 -Wall
OBJS = main.o vector.o

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: main
	./main

clean:
	@rm -f main *.o
