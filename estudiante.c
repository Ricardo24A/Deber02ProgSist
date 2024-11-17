#include <stdio.h>
#include <string.h>
#include "estudiante.h"

void registrarEstudiante(struct Estudiante *estudiante) {
    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante->nombre, NOMBRE, stdin); // Leer el nombre completo con espacios
    estudiante->nombre[strcspn(estudiante->nombre, "\n")] = '\0'; // Eliminar salto de línea

    printf("Ingrese el nivel del estudiante: ");
    scanf("%d", &estudiante->nivel);
    while (getchar() != '\n');

    printf("Ingrese la carrera del estudiante: ");
    fgets(estudiante->carrera, CARRERA, stdin);
    estudiante->carrera[strcspn(estudiante->carrera, "\n")] = '\0';

    do {
        printf("Ingrese el número de materias (3-7): ");
        scanf("%d", &estudiante->numMaterias);
        while (getchar() != '\n');
    } while (estudiante->numMaterias < 3 || estudiante->numMaterias > 7);

    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(estudiante->materiasNombres[i], NOMBRE, stdin); // Leer el nombre de la materia
        estudiante->materiasNombres[i][strcspn(estudiante->materiasNombres[i], "\n")] = '\0'; // Eliminar salto de línea

        printf("Ingrese los créditos de la materia %d: ", i + 1);
        scanf("%d", &estudiante->materiasCreditos[i]);
        while (getchar() != '\n'); // Limpiar el buffer para recoger datos sin conflictos
    }
}
void mostrarEstudiante(const struct Estudiante *estudiante) {
    printf("Estudiante:\n");
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Nivel del estudiante: %d\n", estudiante->nivel);
    printf("\n");
    printf("Carrera: %s\n", estudiante->carrera);
    printf("Materias tomadas para el semestre:\n");
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("  --> Materia: %s (Creditos: %d)\n", estudiante->materiasNombres[i], estudiante->materiasCreditos[i]);
    }
}
