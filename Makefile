CC = gcc
CFLAGS = -c -I.

# Regla principal para crear el programa
programa: profesor.o estudiante.o main.o
	$(CC) -o programa profesor.o estudiante.o main.o

# Reglas para compilar cada archivo fuente en un archivo objeto
profesor.o: profesor.c
	$(CC) $(CFLAGS) -o profesor.o profesor.c

estudiante.o: estudiante.c
	$(CC) $(CFLAGS) -o estudiante.o estudiante.c

main.o: main.c
	$(CC) $(CFLAGS) -o main.o main.c

.PHONY: clean
clean:
	rm -f *.o programa
