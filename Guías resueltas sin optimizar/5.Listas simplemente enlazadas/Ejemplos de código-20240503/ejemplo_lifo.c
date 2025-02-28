/*
Ejemplo sencillo de lista LIFO
Programa que inserta los valores 1, 2, 3 al principio de una lista enteros (LIFO).
Programacion UNSAM
Autor: David Lopez
Año: 2018
*/

#include<stdio.h>
#include<stdlib.h>

//Declaración de la estructura para los nodos (tipo de datos)
typedef struct nodo {
    int dato;
    struct nodo *sig;   
} nodo;

//Funcion que inserta al principio
nodo *insertar_lifo (nodo *l, int d)
    {
    nodo *nuevo;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
    }   

//Funcion que muestra los elementos de la lista
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

//Funcion que libera toda la memoria ocupada por la lista
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

//Programa principal que hace uso de las funciones definidas arriba
int main ()
    {
    nodo *lista = NULL;

    //Insertar en la lista valores de ejemplo
    lista = insertar_lifo (lista, 1); //Inserta el valor 1
    lista = insertar_lifo (lista, 2); //Inserta el valor 2
    lista = insertar_lifo (lista, 3); //Inserta el valor 3

    //Mostrar la lista
    mostrar (lista);

    //Destruir lista
    lista = destruir (lista);

    return 0;
    }
