#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profesor.h"
#include "estudiante.h"

int main(int argc, char *argv[]) {
    int cantidad_personas = 0;
    char opcion = '\0';

    // Verificar que se pasaron los argumentos correctos
    if (argc < 3) {
        printf("Uso: %s <cantidad_personas> <opcion>\n", argv[0]);
        printf("Opciones:\n -p para Profesor\n -e para Estudiante\n -a para Ambos\n");
        return 1;
    }

    // Validar la cantidad de personas
    cantidad_personas = atoi(argv[1]);
    if (cantidad_personas < 2) {
        printf("La cantidad de personas debe ser mayor a 2.\n");
        return 1;
    }

    // Validar la opción de registro
    if (strcmp(argv[2], "-p") == 0) {
        opcion = 'p';
    } else if (strcmp(argv[2], "-e") == 0) {
        opcion = 'e';
    } else if (strcmp(argv[2], "-a") == 0) {
        opcion = 'a';
    } else {
        printf("Opción inválida. Use -p para Profesor, -e para Estudiante, -a para Ambos\n");
        return 1;
    }

    // Declarar punteros para las estructuras
    struct Profesor *profesores = NULL;
    struct Estudiante *estudiantes = NULL;
    int num_profesores = 0;
    int num_estudiantes = 0;

    // Calcular la cantidad de profesores y estudiantes de manera explícita
    if (opcion == 'p') {
        // Solo profesores
        num_profesores = cantidad_personas;
        num_estudiantes = 0;
    } else if (opcion == 'e') {
        // Solo estudiantes
        num_profesores = 0;
        num_estudiantes = cantidad_personas;
    } else if (opcion == 'a') {
        // Ambos: un profesor y el resto estudiantes
        num_profesores = 1;
        num_estudiantes = cantidad_personas - 1;
    }

    // Asignar memoria dinámica para las estructuras
    if (num_profesores > 0) {
        profesores = malloc(num_profesores * sizeof(struct Profesor));
        if (profesores == NULL) {
            perror("Error al reservar memoria para profesores");
            return 1;
        }
    }

    if (num_estudiantes > 0) {
        estudiantes = malloc(num_estudiantes * sizeof(struct Estudiante));
        if (estudiantes == NULL) {
            perror("Error al reservar memoria para estudiantes");
            free(profesores);  // Liberar memoria de profesores en caso de error
            return 1;
        }
    }

    // Registro de personas
    if (num_profesores > 0) {
        for (int i = 0; i < num_profesores; i++) {
            printf("Registro de Profesor %d:\n", i + 1);
            registrarProfesor(&profesores[i]);
        }
    }

    if (num_estudiantes > 0) {
        for (int i = 0; i < num_estudiantes; i++) {
            printf("Registro de Estudiante %d:\n", i + 1);
            registrarEstudiante(&estudiantes[i]);
        }
    }

    // Mostrar información registrada
    printf("\nInformación Registrada:\n");
    if (num_profesores > 0) {
        for (int i = 0; i < num_profesores; i++) {
            printf("\nProfesor %d:\n", i + 1);
            mostrarProfesor(&profesores[i]);
        }
    }

    if (num_estudiantes > 0) {
        for (int i = 0; i < num_estudiantes; i++) {
            printf("\nEstudiante %d:\n", i + 1);
            mostrarEstudiante(&estudiantes[i]);
        }
    }

    // Liberar memoria
    free(profesores);
    free(estudiantes);

    return 0;
}
