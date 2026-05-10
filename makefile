#NOME_PROGRAMA = main #(LINUX)
NOME_PROGRAMA = main.exe #(WINDOWS)

CC = gcc

CFLAGS = -Wall

all: main.o arvore.o
	$(CC) $(CFLAGS) -o $(NOME_PROGRAMA) main.o arvore.o

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c arvore.c

main.o: main.c arvore.h
	$(CC) $(CFLAGS) -c main.c

clean:
#[TAB]rm -f *.o $(NOME_PROGRAMA) (LINUX)
	del /Q /F *.o $(NOME_PROGRAMA)