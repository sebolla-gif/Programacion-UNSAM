#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct estudiantes
{
    int legajo;

    char nombre[10];

    float promedio;

} estudiantes;

void LeerStructs(estudiantes alumnos[])
{
    int i=0;
    float mayor=0;
    char nmayor[10];
    FILE *f;
    f = fopen("struct.dat", "rb");
    if (f == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return ;
    }
    while (fread(&alumnos[i], sizeof (struct estudiantes), 1, f) == 1)
    {

        printf("Legajo: %d\n", alumnos[i].legajo);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
        if(alumnos[i].promedio > mayor)
        {
            mayor = alumnos[i].promedio;
            strcpy(nmayor, alumnos[i].nombre);
        }
        i++;
    }
    if (fclose(f) != 0)
    {
        printf("\nError al cerrar el archivo\n");
        return ;
    }
    printf("El mayor promedio es: %.2f, del alumno %s", mayor, nmayor);
    printf("\n");

}

int main(void)
{
    estudiantes alumnos[MAX];
    LeerStructs(alumnos);
    return 0;
}
