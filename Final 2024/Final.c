/*
Dado que cada instrucción requiere 4 ciclos de clock y hay 12 instrucciones en total, el número total de ciclos de clock necesarios será:

Total de ciclos de clock = 4 ciclos/instrucción * 12 instrucciones = 48 ciclos

Para calcular la velocidad del microprocesador, podemos usar la fórmula:

Tiempo = (Total de ciclos de clock) / (Velocidad de clock)

Dado que el tiempo es de 2ms, podemos calcular el tiempo de la siguiente manera:

Velocidad = 48ciclos / 2ms = 24MHz

Por lo tanto, la velocidad del microprocesador es de 24MHz.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int menu(int op)
{
    printf("\n1.Insertar valores\n2.lista\n3.Guardar datos\n4.Finalizar el programa.\n");
    scanf("%d", &op);
    return op;
}


typedef struct nodo
{
    unsigned char valor;
    char modelo[16];
    struct nodo *sig;

} nodo;


typedef struct dinamico
{
    char modelo[16];
    unsigned char ID;

} dinamico;


nodo *insertar_al_final(nodo *l, unsigned char valor, char modelo[])
{

    nodo *nuevo, *aux;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error: No se sigudo asignar memoria sigara el nuevo nodo.\n");
        return NULL;
    }
    nuevo->valor = valor;
    nuevo->sig=NULL;
    strcpy (nuevo->modelo, modelo);
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
        printf("ID: %c\n", lista->valor);
        printf("modelo: %s\n", lista->modelo);
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



void grabar(dinamico *v,int n)
{
    int aux,aux2;
    printf("cuantos elementos desea guardar:\n");
    scanf("%i", &aux);
    while(aux > n)
    {
        printf("No hay esa cantidad de elementos en el vector, ingrese otro valor:\n");
        scanf("%i", &aux);
    }
    aux2 = n-aux;
    // Abrir el archivo para escritura
    FILE *archivo = fopen("listado.bin", "wb");
    if (archivo == NULL)
    {
        printf("Error: no se pudo abrir el archivo.\n");
        return;
    }

    // Escribir los elementos en el archivo

    if(fwrite(v+aux2, sizeof(dinamico), aux, archivo) != aux)
    {
        printf("error al escribir el archivo");
        return;
    }
    // Cerrar el archivo y liberar la memoria del vector
    if(fclose(archivo)!=0)
    {
        printf("error al cerrar el archivo");
        return;
    }
    printf("Los elementos se han guardado en el archivo listado.bin.\n");
}




nodo *mascaras(nodo *listafifo,dinamico vector[],unsigned char v[],int n)
{
    unsigned char auxv;
    int contador=0,contador2=0;
    unsigned char masks[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    int aux;

    printf("elegir uno de los valores del vector V\n");
    scanf("%i", &aux);
    while(aux>254 || aux<0)
    {
        printf("valor fuera de rango, ingrese otro valor \n");
        scanf("%i",&aux);
    }
    auxv = v[aux];

    contador = 0;
    for(int i =0; i<7; i++)
    {
        if((auxv & masks[i])!=0)
        {
            contador++;
        }
    }
    for(int i=0; i<n; i++)
    {
        contador2=0;
        for(int j =0; j<7; j++)
        {
            if((vector[i].ID & masks[j])!=0)
            {
                contador2++;
            }
        }
        if(contador2 == contador)
        {
            listafifo=insertar_al_final(listafifo,vector[i].ID,vector[i].modelo);
        }
    }

    return listafifo;
}

int main(void)
{
    unsigned char v[255];
    for(int j =254; j>=0; j--)
    {
        v[j]= 255 - 3 * j % 256;
    }
    dinamico *vector = NULL;
    nodo *listafifo = NULL;
    char nombre[16];
    int n=0;
    int op;
    do
    {
        op = menu(op);
        switch(op)
        {
        case 1:

            printf ("Ingrese el modelo (* finaliza):");
            scanf ("%s", nombre);
            while (strcmp (nombre, "*") != 0)   //Mientras el nombre no sea "*"
            {
                n++;
                if(n>255)
                {
                    printf("ya no se puden ingresar mas modelos: \n");
                    break;
                }
                vector = (dinamico*) realloc (vector, sizeof (dinamico) * n);
                strcpy (vector[n - 1].modelo, nombre);
                vector[n-1].ID = v[n-1];
                printf ("Ingrese el modelo (* finaliza):");
                scanf ("%s", nombre);
            }
            for(int i = 0; i < n; i++)
            {
                printf("%c\n", vector[i].ID);
                printf("%s\n", vector[i].modelo);
            }

            break;
        case 2:
            listafifo = mascaras(listafifo,vector,v,n);
            mostrar(listafifo);
            break;
        case 3:
            grabar(vector,n);
            break;
        case 4:
            break;
        default:
            printf ("Opcion invalida\n");
            break;
        }

    }
    while(op != 4);
    free(vector);
    listafifo=destruir(listafifo);
    return 0;
}
