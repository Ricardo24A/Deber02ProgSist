#define NOMBRE  80
#define CARRERA 100
#define NUM_MATERIAS 7

struct Estudiante {
    char nombre[NOMBRE];
    int nivel;
    char carrera[CARRERA];
    int numMaterias;
    char materiasNombres[NUM_MATERIAS][NOMBRE];
    int materiasCreditos[NUM_MATERIAS];
};

void registrarEstudiante(struct Estudiante *estudiante);
void mostrarEstudiante(const struct Estudiante *estudiante);
