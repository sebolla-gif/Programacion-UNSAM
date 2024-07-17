#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} coordenadas;

float DistanciaEuclidea(coordenadas p1, coordenadas p2)
{
    return hypot(p2.x - p1.x, p2.y - p1.y); //hypot de la biblioteca math.h calcula directamente la distancia euclidiana entre dos puntos.
}

void LeerCoordenadas(coordenadas *p, int num)
{
    printf("Ingrese el valor de la coordenada en x del punto %d: ", num);
    scanf("%i", &p->x); //Lee el valor entero ingresado por el usuario y lo almacena en el miembro x de la estructura coordenadas apuntada por p.
    printf("Ingrese el valor de la coordenada en y del punto %d: ", num);
    scanf("%i", &p->y);
}

int main(void)
{
    coordenadas punto[2];

    for (int i = 0; i < 2; i++)
    {
        LeerCoordenadas(&punto[i], i + 1);
    }

    printf("\n");
    printf("La distancia euclideana es: %.2f\n", DistanciaEuclidea(punto[0], punto[1]));

    return 0;
}
