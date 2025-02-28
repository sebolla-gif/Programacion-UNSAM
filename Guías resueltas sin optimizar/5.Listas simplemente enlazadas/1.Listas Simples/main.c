#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *p;

} nodo;

nodo *insertarnodo(nodo *lista, int valor)
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

int main(void)
{
    nodo *lista = NULL;
    int op,valor;
    do
    {
        printf ("1.insertar valor a la lista\n2.mostrar lista\n3.Salir\nIngrese opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nIngrese el valor: ");
            scanf("%d", &valor);
            lista = insertarnodo(lista,valor);
            break;
        case 2:
            mostrar(lista);
            break;
        case 3:
            break;
        default:
            printf("No ingreso una opcion valida\n");
            break;
        }
    }
    while(op!=3);
    lista = destruir(lista);
    return 0;
}
