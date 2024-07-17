#include <stdio.h>
#include <stdlib.h>

typedef struct tiempo
{
    int horas, minutos, segundos;

} tiempo;

tiempo Diferencia(tiempo h1, tiempo h2)
{
    tiempo resultado;
    resultado.segundos = h2.segundos - h1.segundos;
    if (resultado.segundos < 0)
    {
        resultado.segundos += 60;
        h2.minutos--;
    }
    resultado.minutos = h2.minutos - h1.minutos;
    if (resultado.minutos < 0)
    {
        resultado.minutos += 60;
        h2.horas--;
    }
    resultado.horas = h2.horas - h1.horas;
    return resultado;
}

void LeerTiempo(tiempo *p, int num)
{
    do
    {
        printf("Ingrese la hora, minutos y segundos del tiempo %d (formato: HH MM SS): \n", num);
        scanf("%d %d %d", &p->horas, &p->minutos, &p->segundos);

        if (p->horas < 0 || p->horas >= 24)
        {
            printf("Hora invalida. Debe estar entre 0 y 23.\n");
        }
        if (p->minutos < 0 || p->minutos >= 60)
        {
            printf("Minutos invalidos. Deben estar entre 0 y 59.\n");
        }
        if (p->segundos < 0 || p->segundos >= 60)
        {
            printf("Segundos invalidos. Deben estar entre 0 y 59.\n");
        }
    }
    while (p->horas < 0 || p->horas >= 24 || p->minutos < 0 || p->minutos >= 60 || p->segundos < 0 || p->segundos >= 60);
}

int main(void)
{
    tiempo hs[3];

    for(int i=0; i<2; i++)
    {
        LeerTiempo(&hs[i], i+1);
    }

    hs[2]=Diferencia(hs[0],hs[1]);

    printf("la diferencia de tiempo es de %i horas %i minutos %i segundos\n", hs[2].horas, hs[2].minutos, hs[2].segundos);

    return 0;
}
