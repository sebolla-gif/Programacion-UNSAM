#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *sig;

} nodo;


nodo *insertar_al_final(nodo *l, int v)
{

    nodo *nuevo, *aux;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error: No se sigudo asignar memoria sigara el nuevo nodo.\n");
        return NULL;
    }
    nuevo->valor = v;
    nuevo->sig=NULL;
    if(l==NULL)
    {
        return nuevo;
    }
    aux=l;
    while(aux->sig != NULL)
    {
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

/*

// Función para buscar un elemento en la lista por comparación con una clave
void buscar_elemento(nodo *lista, int clave) {
    nodo *anterior = NULL;
    nodo *actual = lista;

    while (actual != NULL && actual->valor != clave) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("El elemento %d no se encuentra en la lista.\n", clave);
    } else {
        printf("El elemento %d se encuentra en la lista.\n", clave);
        if (anterior != NULL) {
            printf("El elemento anterior es %d.\n", anterior->valor);
        } else {
            printf("No hay elemento anterior, ya que %d es el primer elemento de la lista.\n", clave);
        }
    }
}

*/
void buscar_elemento(nodo *l, int v)
{

    int *p=NULL;
    int aux;

    while(l!=NULL && l->valor != v)
    {
        if(l->sig->valor == v)
        {
            p=&aux;
            aux = l->valor;
        }
        l=l->sig;
    }
    if(l==NULL)
    {
        printf("El elemento no existe en la lista\n");
    }
    else
    {
        printf("El elemento %d pertenece a la lista\n", v);
        if(p==NULL){
            printf("No existe un valor anterior\n");
        }
        else{
            printf("Existe un valor anterior y vale %d\n", aux);
        }
    }
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

    buscar_elemento(listafifo,3);

    mostrar(listafifo);

    listafifo = destruir(listafifo);

    return 0;
}
