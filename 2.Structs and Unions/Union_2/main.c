#include <stdio.h>
#include <stdlib.h>

typedef union tipo
{
    int uno;
    float dos;
    double tres;
} tipo;

typedef struct campo
{
    int tipo;
    tipo dato;
} campo;

// Función para leer el tipo de dato y el valor
void leerDato(campo *campo)
{
    printf("Ingrese el tipo de dato que desea almacenar: 1.int 2.float 3.double \n");
    scanf("%i", &campo->tipo);

    switch(campo->tipo)
    {
    case 1:
        printf("Ingrese el valor tipo INT \n");
        scanf("%i", &campo->dato.uno);
        break;
    case 2:
        printf("Ingrese el valor tipo FLOAT \n");
        scanf("%f", &campo->dato.dos);
        break;
    case 3:
        printf("Ingrese el valor tipo DOUBLE \n");
        scanf("%lf", &campo->dato.tres);
        break;
    default:
        printf("Tipo de dato no valido\n");
        exit(EXIT_FAILURE);
    }
    return;
}

// Función para mostrar el valor almacenado
void mostrarDato(campo *campo)
{
    switch(campo->tipo)
    {
    case 1:
        printf("Se almaceno %i\n", campo->dato.uno);
        break;
    case 2:
        printf("Se almaceno %f\n", campo->dato.dos);
        break;
    case 3:
        printf("Se almaceno %lf\n", campo->dato.tres);
        break;
    default:
        printf("Tipo de dato no valido\n");
    }
    return;
}

int main(void)
{

    campo campo;

    leerDato(&campo);
    mostrarDato(&campo);

    return 0;
}
