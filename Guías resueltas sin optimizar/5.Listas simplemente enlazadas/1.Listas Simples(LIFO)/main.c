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

int main() {

    nodo *lista = NULL;

    lista=insertar_al_inicio(lista, 3);
    lista=insertar_al_inicio(lista, 2);
    lista=insertar_al_inicio(lista, 1);

    mostrar(lista);

    lista = destruir(lista);

    return 0;
}
