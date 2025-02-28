#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *p;

} nodo;

nodo *insertar_al_inicio(nodo *lista, int valor)
{
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        return NULL;
    }
    nuevo->p=lista;
    nuevo->valor=valor;
    return nuevo;
}

nodo *par(nodo *lista, nodo *pares)
{
    nodo *actual = lista;
    while (actual != NULL)
    {
        if (actual->valor % 2 == 0)
        {
            pares = insertar_al_inicio(pares, actual->valor); // Insertar en la lista de pares
        }
        actual = actual->p;
    }
    return pares;
}

nodo *impar(nodo *lista, nodo *impares)
{
    nodo *actual = lista;
    while (actual != NULL)
    {
        if (actual->valor % 2 != 0)
        {
            impares = insertar_al_inicio(impares, actual->valor); // Insertar en la lista de impares
        }
        actual = actual->p;
    }
    return impares;
}

void mostrar(nodo *lista)
{
    printf("Lista: \n");
    while(lista != NULL)
    {
        printf("->%d", lista->valor);
        lista = lista->p;
    }
    printf("\n");
}
/*
int *buscarpar(nodo *lista)
{

    int *v = malloc(sizeof(int)); // Asignar memoria para el puntero
    if (v == NULL)
    {
        printf("Error: No se pudo asignar memoria para el array.\n");
        return NULL;
    }

    int i = 0;
    while(lista != NULL)
    {
        if((lista->valor) % 2 == 0)
        {
            *(v+i) = lista->valor;
            i++;
            v = realloc(v, sizeof(int) * (i + 1)); // Ampliar la memoria asignada para el puntero si es necesario
            if (v == NULL)
            {
                printf("Error: No se pudo asignar memoria para el array.\n");
                return NULL;
            }
        }
        lista = lista->p;
    }
    *(v+i) = 3; // Agregar un valor de terminación al array
    return v;
}

int *buscarimpar(nodo *lista)
{

    int *v = malloc(sizeof(int)); // Asignar memoria para el puntero
    if (v == NULL)
    {
        printf("Error: No se pudo asignar memoria para el array.\n");
        return NULL;
    }

    int i = 0;
    while(lista != NULL)
    {
        if((lista->valor) % 2 != 0)
        {
            *(v+i) = lista->valor;
            i++;
            v = realloc(v, sizeof(int) * (i + 1)); // Ampliar la memoria asignada para el puntero si es necesario
            if (v == NULL)
            {
                printf("Error: No se pudo asignar memoria para el array.\n");
                return NULL;
            }
        }
        lista = lista->p;
    }
    *(v+i) = 2; // Agregar un valor de terminación al array
    return v;
}
*/
nodo *destruir(nodo *lista)
{

    nodo *aux;
    while(lista != NULL)
    {
        aux = lista;
        lista=lista->p;
        free(aux);
    }
    return NULL;
}

int main(void)
{

    nodo *lista = NULL;
    nodo *listapar = NULL;
    nodo *listaimpar = NULL;
    //int *vp;
    //int *vip;

    lista=insertar_al_inicio(lista, 6);
    lista=insertar_al_inicio(lista, 5);
    lista=insertar_al_inicio(lista, 4);
    lista=insertar_al_inicio(lista, 3);
    lista=insertar_al_inicio(lista, 2);
    lista=insertar_al_inicio(lista, 1);


    listapar=par(lista,listapar);
    listaimpar=impar(lista,listaimpar);

    /*
    vp=buscarpar(lista);
    int i=0;
    while(*(vp+i)!=3)
    {
        listapar=insertar_al_inicio(listapar, *(vp+i));
        i++;
    }
    vip=buscarimpar(lista);
    i=0;
    while(*(vip+i)!=2)
    {
        listaimpar=insertar_al_inicio(listaimpar, *(vip+i));
        i++;
    }
    */
    mostrar(lista);
    mostrar(listapar);
    mostrar(listaimpar);

    //free(vp);
    //free(vip);
    lista = destruir(lista);
    listapar = destruir(listapar);
    listaimpar = destruir(listaimpar);

    return 0;
}
