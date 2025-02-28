/*
Ejercicio 1a y 1b listas dobles
Programa que permite agregar elementos al final o al principio de una lista doble y la recorre en ambos sentidos
Autor: David Lopez
ProgramaciÃ³n UNSAM
AÃ±o: 2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato; /* Se decidio arbitrariamente usar float para el dato (podrÃ­a ser cualuier tipo) */
	struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

/* Inserta un elemento en orden ascendente en la lista */
lista insertar_ordenado(lista l, float d) {
    nodo_d *nuevo, *p;
    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo->dato = d;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (l.prim == NULL) { /* Lista vacía, el nuevo nodo será el único */
        l.prim = nuevo;
        l.ult = nuevo;
        return l;
    }

    /* Buscar la posición para insertar el nuevo nodo */
    p = l.prim;
    while (p != NULL && p->dato < d) {
        p = p->sig;
    }

    if (p == NULL) { /* El nuevo nodo será el último de la lista */
        nuevo->ant = l.ult;
        l.ult->sig = nuevo;
        l.ult = nuevo;
    } else if (p->ant == NULL) { /* El nuevo nodo será el primero de la lista */
        nuevo->sig = l.prim;
        l.prim->ant = nuevo;
        l.prim = nuevo;
    } else { /* El nuevo nodo se inserta en medio de la lista */
        nuevo->ant = p->ant;
        nuevo->sig = p;
        p->ant->sig = nuevo;
        p->ant = nuevo;
    }

    return l;
}

/* Inserta al principio del la lista */
lista insertar_lifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->ant = NULL;
	nuevo->sig = l.prim;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.ult = nuevo;
	else
		l.prim->ant = nuevo;
	l.prim = nuevo;
	return l;
}

/* Inserta al final del la lista, muy similar a insertar_lifo, ya que  */
/* la estructura de una lista doblemente enlazada es simetrica */
/* solo cambia ant por sig,y viceversa, prim por ult y viceversa */
lista insertar_fifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->sig = NULL;
	nuevo->ant = l.ult;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.prim = nuevo;
	else
		l.ult->sig = nuevo;
	l.ult = nuevo;
	return l;
}

/* Destruye la lista liberando la memoria ocupada por cada nodo */
lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
	l.prim = NULL;
	l.ult = NULL;
	return l;
}

/* Inserta un elemento en la posición indicada de la lista */
lista insertar_en_posicion(lista l, float d, int posicion) {
    nodo_d *nuevo, *p;
    int i;

    if (posicion < 0) {
        printf("La posición debe ser un número positivo.\n");
        return l;
    }

    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo->dato = d;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (l.prim == NULL) { /* Lista vacía */
        if (posicion == 0) { /* Insertar al principio */
            l.prim = nuevo;
            l.ult = nuevo;
        } else {
            printf("La lista está vacía, la posición debe ser 0.\n");
            free(nuevo);
        }
    } else if (posicion == 0) { /* Insertar al principio */
        nuevo->sig = l.prim;
        l.prim->ant = nuevo;
        l.prim = nuevo;
    } else { /* Insertar en una posición intermedia o al final */
        p = l.prim;
        for (i = 0; i < posicion - 1 && p->sig != NULL; i++) {
            p = p->sig;
        }

        if (i < posicion - 1) { /* La lista es más corta de lo esperado */
            printf("La lista es más corta de lo esperado, no se puede insertar en la posición %d.\n", posicion);
            free(nuevo);
        } else { /* Insertar en la posición intermedia o al final */
            nuevo->sig = p->sig;
            if (p->sig != NULL) {
                p->sig->ant = nuevo;
            } else { /* Insertar al final */
                l.ult = nuevo;
            }
            p->sig = nuevo;
            nuevo->ant = p;
        }
    }

    return l;
}


int main() {
	nodo_d *p; /* Puntero para recorrer la lista */
	float f;
	lista l; /* La lista propiamente dicha */
	int modo, posicion; /* Como quiero insertar: lifo o fifo */

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

	printf("Ingrese los datos (0 para terminar): ");
	scanf("%f", &f);
	while (f != 0) {
	    printf ("\nIngrese 1 para LIFO, 2 para FIFO, 3 para insertar ordenado o 4 para insertar en una posición específica: ");
	    scanf ("%d", &modo);
        if (modo == 1)
            l = insertar_lifo(l, f);
        else if (modo == 2)
            l = insertar_fifo(l, f);
        else if (modo == 3)
            l = insertar_ordenado(l, f);
        else if (modo == 4) {
            printf("Ingrese la posición en la que desea insertar el elemento: ");
            scanf("%d", &posicion);
            l = insertar_en_posicion(l, f, posicion);
        } else {
            printf("Opción no válida.\n");
        }
	    printf("\nIngrese los datos (0 para terminar): ");
	    scanf("%f", &f);
	}

	printf("\nMuestro en orden ingresado\n"); /* Al derecho, desde el principio */
	for (p = l.prim; p != NULL; p = p->sig)
	    printf("Dato = %6.2f\n", p->dato);

	printf("Muestro en orden inverso\n"); /* Al reves, desde el final */
	for (p = l.ult; p != NULL; p = p->ant)
	    printf("Dato = %6.2f\n", p->dato);

	l = destruir (l);
	return 0;
}
