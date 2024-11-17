#include <stdio.h>
#include <stdlib.h>
#define NOMBRE 80
#define NOMBRECARRERA 120
#define MAXIMO_MAT 3


struct Profesor {
	char nombre[NOMBRE];
	char carrera[NOMBRECARRERA];
	int numeroMat;
	char materia[MAXIMO_MAT][NOMBRE];
	int paralelo[MAXIMO_MAT];
};

void registrarProfesor(struct Profesor *profesor);

void mostrarProfesor(const struct Profesor *profesor);


