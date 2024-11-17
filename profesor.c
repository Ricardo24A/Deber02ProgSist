#include <stdio.h>
#include <string.h>
#include "profesor.h"

// Funcion para registrar un profesor
void registrarProfesor(struct Profesor *profesor) {
    printf("Ingrese el nombre del profesor: ");
    fgets(profesor->nombre, NOMBRE, stdin); // Leer el nombre completo con espacios
    profesor->nombre[strcspn(profesor->nombre, "\n")] = '\0'; // Eliminar salto de línea

    printf("Ingrese la carrera del profesor: ");
    fgets(profesor->carrera, NOMBRECARRERA, stdin); // Leer la carrera completa si la pone con espacios, decidi utilizar gets debido a que si ponian con espacios habia error. 
    profesor->carrera[strcspn(profesor->carrera, "\n")] = '\0';

    do {
        printf("Ingrese el número de materias que va a dictar (2-3): ");
        scanf("%d", &profesor->numeroMat);
        while (getchar() != '\n');
    } while (profesor->numeroMat < 2 || profesor->numeroMat > 3);

    for (int i = 0; i < profesor->numeroMat; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(profesor->materia[i], NOMBRE, stdin); 
        profesor->materia[i][strcspn(profesor->materia[i], "\n")] = '\0';

        printf("Ingrese el paralelo de la materia %d: ", i + 1);
        scanf("%d", &profesor->paralelo[i]);
        while (getchar() != '\n'); // Limpiar el buffer para que recoja bien los datos sin conflictos
    }
}
// Funcion para mostrar la información de un profesor
void mostrarProfesor(const struct Profesor *profesor) {
    printf("Información del Profesor:\n");
    printf("Nombre: %s\n", profesor->nombre);
    printf("Carrera: %s\n", profesor->carrera);
    printf("Materias que dicta:\n");
    for (int i = 0; i < profesor->numeroMat; i++) {
        printf("  --> Materia: %s (Paralelo: %d)\n", profesor->materia[i], profesor->paralelo[i]);
    }
}
