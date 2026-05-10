#NOME_PROGRAMA = main #(LINUX)
NOME_PROGRAMA = main.exe #(WINDOWS)

CC = gcc

CFLAGS = -Wall

all: main.o heap.o
	$(CC) $(CFLAGS) -o $(NOME_PROGRAMA) main.o heap.o

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

clean:
#[TAB]rm -f *.o $(NOME_PROGRAMA) (LINUX)
	del /Q /F *.o $(NOME_PROGRAMA)