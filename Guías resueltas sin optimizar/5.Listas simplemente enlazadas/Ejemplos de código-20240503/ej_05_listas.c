/*
Ej 5 practica listas
Escribir una función que inserte un elemento después del último nodo de una lista enlazada.
Programacion UNSAM
Autor: David Lopez
Año: 2020
*/

#include<stdio.h>
#include<stdlib.h>

/*Declaración de la estructura para los nodos (tipo de datos)*/
typedef struct nodo {
    int dato;
    struct nodo *sig;   
} nodo;

/*Inserta un nuevo nodo al final de la lista. Esta es la funcion pedida en el enunciado*/
/*Todo lo demas es para tener un programa completo para poder probar*/
nodo *insertar_fifo (nodo *l, int d)
    {
    nodo *nuevo, *p;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = NULL;  /*Porque va a ser el ultimo nodo*/
    if (l == NULL)
        return nuevo;
    /*Como la lista no esta vacia la recorro buscando el ultimo nodo*/
    p = l;
    while (p->sig != NULL)
        p = p->sig;
    /*Ahora p es el ultimo nodo*/
    p->sig = nuevo;
    return l;
    }       

/*Muestra los elementos de la lista*/
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}


/*Libera toda la memoria ocupada por la lista*/
nodo *destruir (nodo *l) {
    nodo * aux;

    while (l != NULL) {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("lista destruida\n");
    return NULL;
}

/*Pide entros hasta que se ingrese cero y los inserta en la lista*/
nodo *ingresa_usuario(nodo *lista) {
    int temp;

    printf ("Ingrese un nro entero (cero finaliza):");
    scanf ("%d", &temp);
    while (temp != 0) {
        lista = insertar_fifo (lista, temp);
        printf ("\nIngrese otro nro entero (cero finaliza):");
        scanf ("%d", &temp);
    }
    return lista;   
}

/*Programa principal que hace uso de las funciones definidas arriba*/
int main ()
    {
    nodo *lista = NULL;

    /*Inserta en la lista los valores que ingrese el usuario*/
    lista = ingresa_usuario (lista);
    mostrar (lista);

    /*Destruir lista*/
    lista = destruir(lista);

    return 0;
    }
