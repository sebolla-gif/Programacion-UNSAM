#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato; /* Se decidio arbitrariamente usar float para el dato (podría ser cualuier tipo) */
	struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

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

int localizar(lista l, float b){

    nodo_d *p;

    for (p = l.prim; p != NULL; p = p->sig){
        if(p->dato == b){
            printf("dato encontrado\n");
            printf("Dato = %6.2f\n", p->dato);
            return 1;
        }

    }
    return 0;
}

int main(void)
{
    //nodo_d *p; /* Puntero para recorrer la lista */
	//float f;
	lista l; /* La lista propiamente dicha */
	//int modo, posicion; /* Como quiero insertar: lifo o fifo */

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

	l=insertar_lifo(l,2.2);
	l=insertar_lifo(l,3.2);
	l=insertar_lifo(l,1.2);
	l=insertar_lifo(l,2.52);

	int retornodelaf = localizar(l,2.32);
	if(retornodelaf!=1){
        printf("no se pudo localizar el valor en la lista");
	}

    return 0;
}
