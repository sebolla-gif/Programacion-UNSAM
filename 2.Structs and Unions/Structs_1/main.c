#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct estudiantes
{
    int legajo;

    char nombre[10];

    float promedio;

} estudiantes;

void AlmacenarStructs(estudiantes alumnos [])
{
    FILE *f = fopen("struct.dat","wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        return;
    }
    int i = 0;
    printf ("Finalice ingresando 0 en un legajo.\n");
    printf ("Ingrese el primer legajo: ");
    scanf ("%d", &alumnos[i].legajo);
    while (alumnos[i].legajo != 0)
    {
        printf ("Ingrese el nombre del alumno de legajo %d: ", alumnos[i].legajo);
        scanf ("%s", alumnos[i].nombre);
        printf ("Ingrese el promedio: ");
        scanf ("%f", &alumnos[i].promedio);
        if(fwrite(&alumnos[i], sizeof(estudiantes), 1, f) != 1)
        {
            printf("/n Error al escribir el archivo/n");
            return;
        }
        i++;
        printf ("Ingrese otro legajo: ");
        scanf ("%d", &alumnos[i].legajo);
    }

    if (fclose(f) != 0)
    {
        printf("\nError al cerrar el archivo\n");
        return;
    }
}

int main(void)
{
    estudiantes alumnos[MAX];
    AlmacenarStructs(alumnos);
    return 0;
}
