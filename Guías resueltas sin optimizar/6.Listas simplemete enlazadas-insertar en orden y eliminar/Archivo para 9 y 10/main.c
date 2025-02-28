#include <stdio.h>
#include <stdlib.h>

typedef struct data
{

    int valor;
    float aux;
    char text[30];

} data;

int main(void)
{
    int aux;
    data data[4];
    for(int i=0; i<1; i++)
    {
        printf("Ingrese el valor entero nro %d\n", i+1);
        scanf("%d", &data[i].valor);
        printf("Ingrese el valor flotante nro %d\n", i+1);
        scanf("%f", &data[i].aux);
        printf("Ingrese la cadena de texto nro %d\n", i+1);
        scanf("%s", data[i].text);
    }
    FILE *f;
    f=fopen("datos.dat", "w");
    if(f==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return 1;
    }
    printf("Archivo abierto correctamente\n");
    for(int i=0;i<1;i++){
        aux = fwrite(&data[i], sizeof (data[i]), 1, f);
        if(aux!=1){
           printf("\nError al escribir el archivo\n");
           return 2;
        }
    }

    printf("El archivo se escribio correctamente\n");

    if(fclose(f)!=0)
    {
        printf("\nError al cerrar el archivo\n");
        return 3;
    }
    printf("El archivo se cerro correctamente\n");

    return 0;
}
