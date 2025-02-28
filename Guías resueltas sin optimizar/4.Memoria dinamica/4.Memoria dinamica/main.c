#include <stdio.h>
#include <stdlib.h>

int *crear_vector (int n, int valor_inicial)
{
    int *vector=(int *)malloc(n*sizeof(int));
    if (vector == NULL)
    {
        return NULL;
    }
    for(int i=0; i<n; i++)
    {
        *(vector+i)=valor_inicial;
    }
    return vector;
}

int main(void)
{
    int *v;
    int n=10;
    int valor=2;
    v=crear_vector(n,valor);
    if(v!=NULL)
    {
        printf("\nVector creado\n");
        for(int i=0; i<n; i++)
        {
            printf("\nEl valor %d es: %d",i+1,*(v+i));
        }
    }
    else
    {
        printf("No se creo el vector");
    }
    free(v);
    return 0;
}
