#include <stdio.h>
#include <stdlib.h>

int leer(int *v)
{
    int res;
    int aux;
    int i=1;
    FILE *f;
    f=fopen("C://Users//sebav//Documents//Programacion//4.Memoria dinamica//1.Memoria dinamica//vector.dat","r");
    if(f==NULL)
    {
        printf("error al abrir el archivo");
    }
    /* Leer archivo */
    res = fread(&aux, sizeof aux, 1, f);
    *v=aux;
    printf("\nDato: %10d", *v);
    while (res == 1)
    {
        res = fread(&aux, sizeof aux, 1, f);
        if(res == 1)
        {
        v=(int *)realloc(v,sizeof (int) * (i+1));
        if (v == NULL)
        {
            printf("Error al asignar memoria");
            fclose(f);
            return 1;
        }
        *(v+i)=aux;
        printf("\nDato: %10d", *(v+i));
        i++;
        }

    }
    if(fclose(f) != 0)
    {
        printf ("Error al cerrar el archivo de precios\n");
        return 1;
    }
    return i;
}

int main(void)
{
    int *vector = (int *)malloc(sizeof(int));
    if (vector == NULL)
    {
        printf("Error al asignar memoria");
        return 1;
    }
    int cant = leer(vector);
    for(int i=0;i<cant;i++){
        printf("\n%d", vector[i]);
    }
    free(vector);
    return 0;
}
