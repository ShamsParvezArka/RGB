CC = gcc
CFLAGS = -g -c 
CLIBS = -lX11 

output: main.o
	$(CC) main.o $(CLIBS) -o bin/xliv2D

main.o:
	$(CC) $(CFLAGS) main.c 

clean:
	rm *.o
