#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct data
{
    int16_t valor;
    char text[20];
    float aux;
    double doble;

} data;

typedef struct nodo_d
{
    int16_t valor;
    char text[20];
    float aux;
    double doble;
    struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble
{
    nodo_d *prim, *ult;
} lista;


lista insertar_fifo(lista l, data *p)
{
    nodo_d *nuevo;

    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo->valor = p->valor;
    strcpy(nuevo->text,p->text);
    nuevo->aux = p->aux;
    nuevo->doble = p->doble;
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
lista destruir (lista l)
{
    nodo_d *p, *aux;

    p = l.prim;
    while (p != NULL)
    {
        aux = p;
        p = p->sig;
        free (aux);
    }
    printf ("Lista destruida\n");
    l.prim = NULL;
    l.ult = NULL;
    return l;
}

/* Función de comparación para ordenar la lista por strings */
int comparar_strings(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

/* Inserta un elemento en orden ascendente en la lista por strings */
lista insertar_ordenadostr(lista l, const char *str)
{
    nodo_d *nuevo, *p;
    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    strcpy(nuevo->text, str);
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (l.prim == NULL)   /* Lista vacía, el nuevo nodo será el único */
    {
        l.prim = nuevo;
        l.ult = nuevo;
        return l;
    }

    /* Buscar la posición para insertar el nuevo nodo */
    p = l.prim;
    while (p != NULL && comparar_strings(p->text, str) < 0)
    {
        p = p->sig;
    }

    if (p == NULL)   /* El nuevo nodo será el último de la lista */
    {
        nuevo->ant = l.ult;
        l.ult->sig = nuevo;
        l.ult = nuevo;
    }
    else if (p->ant == NULL)     /* El nuevo nodo será el primero de la lista */
    {
        nuevo->sig = l.prim;
        l.prim->ant = nuevo;
        l.prim = nuevo;
    }
    else     /* El nuevo nodo se inserta en medio de la lista */
    {
        nuevo->ant = p->ant;
        nuevo->sig = p;
        p->ant->sig = nuevo;
        p->ant = nuevo;
    }

    return l;
}

/* Inserta un elemento en orden ascendente en la lista */
lista insertar_ordenado(lista l, data *d)
{

    nodo_d *nuevo, *p;
    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo->aux = d->aux;
    nuevo->valor = d->valor;
    strcpy(nuevo->text, d->text);
    nuevo->doble = d->doble;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (l.prim == NULL)   /* Lista vacía, el nuevo nodo será el único */
    {
        l.prim = nuevo;
        l.ult = nuevo;
        return l;
    }

    /* Buscar la posición para insertar el nuevo nodo */
    p = l.prim;
    while (p != NULL && p->aux < d->aux)
    {
        p = p->sig;
    }

    if (p == NULL)   /* El nuevo nodo será el último de la lista */
    {
        nuevo->ant = l.ult;
        l.ult->sig = nuevo;
        l.ult = nuevo;
    }
    else if (p->ant == NULL)     /* El nuevo nodo será el primero de la lista */
    {
        nuevo->sig = l.prim;
        l.prim->ant = nuevo;
        l.prim = nuevo;
    }
    else     /* El nuevo nodo se inserta en medio de la lista */
    {
        nuevo->ant = p->ant;
        nuevo->sig = p;
        p->ant->sig = nuevo;
        p->ant = nuevo;
    }

    return l;
}

/* Elimina un nodo de la lista */
nodo_d *eliminar (nodo_d* l, int16_t d)
{
    nodo_d *ret = l, *aux;

    if (l == NULL)   /* 1er caso: Si la lista es nula no hay que hacer nada */
    {
        printf ("La lista esta vacia\n");
    }
    else   /* La no lista es nula */
    {
        if (l->valor == d)  /* 2do caso: el nodo a borrar es el primero */
        {
            ret = l->sig;
            free (l);
            printf ("Elemento eliminado\n");
        }
        else   /* 3er caso: el nodo a borrar no es el primero */
        {
            while (l->sig != NULL && l->sig->valor != d)
                l = l->sig;
            if (l->sig != NULL)   /* Si l->sig es NULL es porque el dato no existe en l */
            {
                aux = l->sig;
                l->sig = aux->sig;
                free (aux);
                printf ("Dato %d eliminado\n", d);
            }
            else   /* Si l->sig es NULL */
            {
                printf ("El dato %d no se encuentra en la lista\n", d);
            }
        }
    }
    return ret; /* Va a ser el nuevo principio de la lista */
}

int main(void)
{
    int op,op2;
    int16_t elim;
    int key = 0;
    lista l; /* La lista propiamente dicha */
    lista l2;
    nodo_d *auxn=NULL;
    FILE *f;
    /* Inicializo la lista */
    l.prim = NULL;
    l.ult = NULL;

    l2.prim = NULL;
    l2.ult = NULL;

    do
    {
        printf("1.Leer un archivo\n2.Agregar un producto\n3.Eliminar un elemento\n4.Generar una versión ordenada de lista\n5.Mostrar  maestra / ordenada en sentido directo / inverso\n6.Sobrescribir en archivo con los datos de la lista maestra\n7. productos con nombre duplicado\n8.Salir \n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:

            f=fopen("datos.dat", "r");
            if(f==NULL)
            {
                printf("\nError al abrir el archivo\n");
                return 1;
            }
            printf("\nArchivo abierto correctamente\n");
            int i=0;
            data *p = (data *)malloc(sizeof(data));
            int aux = fread(p, sizeof (*p), 1, f);
            while(aux == 1)
            {
                l = insertar_fifo(l, (p+i));
                i++;
                p=(data *)realloc(p, sizeof (*p) * (i+1));
                aux = fread((p+i), sizeof (*(p+i)), 1, f);

            }

            if(fclose(f)!=0)
            {
                printf("\nError al cerrar el archivo\n");
                return 3;
            }
            printf("\nEl archivo se cerro correctamente\n");
            break;
        case 2:

            /*

            case 2:
            for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
            {
            // Crear un nuevo nodo de tipo nodo_d
            nodo_d *nuevo_nodo = (nodo_d*) malloc(sizeof(nodo_d));

            // Copiar los datos de data a nuevo_nodo
            nuevo_nodo->valor = auxn->valor;
            strcpy(nuevo_nodo->text, auxn->text);
            nuevo_nodo->aux = auxn->aux;
            nuevo_nodo->doble = auxn->doble;

            // Insertar nuevo_nodo en la lista ordenada
            l2 = insertar_ordenadostr(l2, nuevo_nodo->text);
            }
            break;

            */
            i++;
            p = (data *)realloc(p, sizeof(data) * i); // Corrección del tamaño del vector de estructuras
            printf("\nIngrese el valor entero: ");
            scanf("%hi", &(p+(i-1))->valor); // Corrección del acceso a la estructura
            printf("\nIngrese la cadena de caracteres: ");
            scanf("%s", (p+(i-1))->text); // Corrección del acceso a la estructura
            printf("\nIngrese el valor flotante: ");
            scanf("%f", &(p+(i-1))->aux); // Corrección del acceso a la estructura
            printf("\nIngrese el valor doble: ");
            scanf("%lf", &(p+(i-1))->doble); // Corrección del acceso a la estructura

            l = insertar_fifo(l, (p+(i-1))); // Pasar la dirección de la estructura
            l2 =insertar_ordenado(l2, (p+(i-1)));
            printf("\n");
            break;
        case 3:

            printf("ingrese el codigo de el nodo que quiere eliminar: ");
            scanf("%hi", &elim);
            l.prim = eliminar(l.prim,elim);
            break;
        case 4:
            printf("1.ordenar por int\n2.ordenar por text\n3.ordenar por float\n4.ordenar por double\n");
            scanf("%d", &op2);
            if(key==0)
            {
                switch(op2)
                {
                case 1:
                    for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
                    {
                        l2=insertar_ordenado(l2,auxn);
                    }
                    break;
                case 2:
                    for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
                    {
                        l2=insertar_ordenadostr(l2,auxn->text);
                    }
                    break;
                case 3:
                    for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
                    {

                    }
                    break;
                case 4:
                    for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
                    {

                    }
                    break;
                default:
                    printf("opcion no valida\n");
                }
                key=1;
            }
            break;
        case 5:
            printf("\nMuestro en orden ingresado\n"); /* Al derecho, desde el principio */
            for (auxn = l.prim; auxn != NULL; auxn = auxn->sig)
            {
                printf("\nvalor entero: %hi\n",auxn->valor);
                printf("valor flotante: %f\n",auxn->aux);
                printf("texto: %s\n",auxn->text);
                printf("Doble = %lf\n", auxn->doble);
            }



            printf("\nMuestro en orden inverso\n"); /* Al reves, desde el final */
            for (auxn = l.ult; auxn != NULL; auxn = auxn->ant)
            {
                printf("\nvalor entero: %hi\n",auxn->valor);
                printf("valor flotante: %f\n",auxn->aux);
                printf("texto: %s\n",auxn->text);
                printf("Doble = %lf\n", auxn->doble);
            }

            printf("\nMuestro en orden ingresado ORDENADO\n"); /* Al derecho, desde el principio */
            for (auxn = l2.prim; auxn != NULL; auxn = auxn->sig)
            {
                printf("\nvalor entero: %hi\n",auxn->valor);
                printf("valor flotante: %f\n",auxn->aux);
                printf("texto: %s\n",auxn->text);
                printf("Doble = %lf\n", auxn->doble);
            }
            printf("\nMuestro en orden inverso ORDENADO\n"); /* Al reves, desde el final */
            for (auxn = l2.ult; auxn != NULL; auxn = auxn->ant)
            {
                printf("\nvalor entero: %hi\n",auxn->valor);
                printf("valor flotante: %f\n",auxn->aux);
                printf("texto: %s\n",auxn->text);
                printf("Doble = %lf\n", auxn->doble);
            }

            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            printf("opcion no valida\n");
        }
    }
    while(op!=8);
    return 0;
}
