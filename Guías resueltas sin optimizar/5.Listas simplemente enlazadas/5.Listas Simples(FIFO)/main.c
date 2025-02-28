#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *sig;

} nodo;


nodo *insertar_al_final(nodo *l, int v){

    nodo *nuevo, *aux;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error: No se sigudo asignar memoria sigara el nuevo nodo.\n");
        return NULL;
    }
    nuevo->valor = v;
    nuevo->sig=NULL;
    if(l==NULL){
        return nuevo;
    }
    aux=l;
    while(aux->sig != NULL){
        aux=aux->sig;
    }
    aux->sig=nuevo;

    return l;
}

void mostrar(nodo *lista)
{
    printf("Lista: \n");
    while(lista != NULL)
    {
        printf("->%d", lista->valor);
        lista = lista->sig;
    }
    printf("\n");
}

nodo *destruir(nodo *lista)
{

    nodo *aux;
    while(lista != NULL)
    {
        aux = lista;
        lista=lista->sig;
        free(aux);
    }
    return NULL;
}
int main(void)
{
    nodo *listafifo = NULL;
    listafifo=insertar_al_final(listafifo, 1);
    listafifo=insertar_al_final(listafifo, 2);
    listafifo=insertar_al_final(listafifo, 3);
    listafifo=insertar_al_final(listafifo, 4);
    listafifo=insertar_al_final(listafifo, 5);
    listafifo=insertar_al_final(listafifo, 6);

    mostrar(listafifo);

    listafifo = destruir(listafifo);

    return 0;
}
