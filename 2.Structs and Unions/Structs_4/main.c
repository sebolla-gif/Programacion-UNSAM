#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas
{
    int x, y, z;
} coordenadas;

coordenadas Componer(coordenadas v1, coordenadas v2)
{
    coordenadas resultado;
    resultado.x = v1.x + v2.x;
    resultado.y = v1.y + v2.y;
    resultado.z = v1.z + v2.z;
    return resultado;
}

void LeerCoordenadas(coordenadas *p, int num)
{
    printf("Ingrese las coordenadas del vector %d (x y z): \n", num);
    scanf("%d %d %d", &p->x, &p->y, &p->z);
}

int main(void)
{
    coordenadas vectores[3];

    for (int i = 0; i < 2; i++)
    {
        LeerCoordenadas(&vectores[i], i + 1);
    }

    vectores[2] = Componer(vectores[0], vectores[1]);

    printf("El vector resultante es: (%d, %d, %d)\n", vectores[2].x, vectores[2].y, vectores[2].z);

    return 0;
}
