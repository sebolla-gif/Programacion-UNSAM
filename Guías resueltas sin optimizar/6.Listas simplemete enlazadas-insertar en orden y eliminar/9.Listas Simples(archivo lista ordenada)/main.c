#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int valor;
    float aux;
    char text[30];

} data;

typedef struct nodo
{
    int dato;
    float aux;
    char text[30];
    struct nodo *sig;

} nodo;

/*Inserta en orden*/
nodo *insertar_ordenado(nodo *l, data *p)
{
    nodo *nuevo, *aux;

    nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = p->valor;
    nuevo->aux = p->aux;
    strcpy(nuevo->text, p->text);
    if (l == NULL || l->dato > p->valor)
    {
        /*Lista vacia o primer elemento > nuevo*/
        nuevo->sig = l;
        return nuevo;
    }
    /*Si llega hasta aca => lista no vacia y nuevo > primer*/
    aux = l;
    while (aux->sig != NULL && aux->sig->dato <= p->valor)
        aux = aux->sig;
    /*Salio del ciclo => aux->sig es NULL o aux->sig->dato > d*/
    /*Inserto el nuevo entre aux y aux->sig*/
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
    return l;
}

/*Muestra los elementos de la lista*/
void mostrar (nodo *l)
{
    printf ("Lista");
    while (l != NULL)
    {
        printf (" --> %d", l->dato);
        printf (" %f ", l->aux);
        printf (" %s ", l->text);
        l = l->sig;
    }
    printf ("\n");
}

/*Libera toda la memoria ocupada por la lista*/
nodo *destruir (nodo *l)
{
    nodo * aux;

    while (l != NULL)
    {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("lista destruida\n");
    return NULL;
}

/* Elimina un nodo de la lista */
nodo *eliminar (nodo* l, int d)
{
    nodo *ret = l, *aux;

    if (l == NULL)   /* 1er caso: Si la lista es nula no hay que hacer nada */
    {
        printf ("La lista esta vacia\n");
    }
    else   /* La no lista es nula */
    {
        if (l->dato == d)  /* 2do caso: el nodo a borrar es el primero */
        {
            ret = l->sig;
            free (l);
            printf ("Elemento eliminado\n");
        }
        else   /* 3er caso: el nodo a borrar no es el primero */
        {
            while (l->sig != NULL && l->sig->dato != d)
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
    nodo *lista=NULL;
    FILE *f;
    f=fopen("C://Users//sebav//Documents//Programacion//6.Listas simplemete enlazadas-insertar en orden y eliminar//Archivo para 9 y 10//datos.dat", "r");
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
        printf("\nvalor entero nro %d: %d\n",i+1,(p+i)->valor);
        printf("valor flotante nro %d: %f\n",i+1,(p+i)->aux);
        printf("texto nro %d: %s\n",i+1,(p+i)->text);
        lista = insertar_ordenado(lista, (p+i));
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

    int op;
    do
    {
        printf("\n1.Agregar un nodo a la lista.\n");
        printf("2.Eliminar un nodo de la lista, habiendo sido encontrado.\n");
        printf("3.Grabar en un nuevo archivo y salir.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        switch(op)
        {
        case 1:

            printf("\nLista actual: \n");
            mostrar(lista);
            i++;
            p = (data *)realloc(p, sizeof(data) * i); // Corrección del tamaño del vector de estructuras
            printf("\nIngrese el valor entero: ");
            scanf("%d", &(p+(i-1))->valor); // Corrección del acceso a la estructura
            printf("\nIngrese el valor flotante: ");
            scanf("%f", &(p+(i-1))->aux); // Corrección del acceso a la estructura
            printf("\nIngrese la cadena de caracteres: ");
            scanf("%s", (p+(i-1))->text); // Corrección del acceso a la estructura
            lista = insertar_ordenado(lista, (p+(i-1))); // Pasar la dirección de la estructura
            printf("\n");
            mostrar(lista);
            printf("\n");
            break;
            printf("\n");
            mostrar(lista);
            printf("\n");
            break;
        case 2:
            printf("\nIngrese el valor del nodo a eliminar: ");
            scanf("%d", &aux);
            lista = eliminar(lista,aux);
            mostrar(lista);
            break;
        case 3:
            /*
            f=fopen("C://Users//sebav//Documents//Programacion//6.Listas simplemete enlazadas-insertar en orden y eliminar//Archivo para 9 y 10//datos.dat", "wb");
            if(f==NULL)
            {
                printf("\nError al abrir el archivo\n");
                return 1;
            }
            printf("\nArchivo abierto correctamente\n");

            for(int j=0; j<i; j++)
            {
                aux=fwrite((p+j), sizeof (*(p+j)), 1, f);
                if(aux!=1)
                {
                    printf("Error al escribir el archivo");
                }
            }
            if(fclose(f)!=0)
            {
                printf("\nError al cerrar el archivo\n");
                return 3;
            }
            printf("\nEl archivo se cerro correctamente\n");
            */
            f=fopen("lista.dat", "wb");
            if(f==NULL)
            {
                printf("\nError al abrir el archivo\n");
                return 1;
            }
            printf("\nArchivo abierto correctamente\n");

            for(int j=0; j<i; j++)
            {
                aux=fwrite((lista+j), sizeof (*(lista+j)), 1, f);
                if(aux!=1)
                {
                    printf("Error al escribir el archivo");
                }
            }

            if(fclose(f)!=0)
            {
                printf("\nError al cerrar el archivo\n");
                return 3;
            }
            printf("\nEl archivo se cerro correctamente\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
    while(op!=3);
    return 0;
}
