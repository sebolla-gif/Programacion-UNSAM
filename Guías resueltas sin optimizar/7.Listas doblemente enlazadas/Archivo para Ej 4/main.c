#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define tam 3

typedef struct data
{
    int16_t valor;
    char text[20];
    float aux;
    double doble;

} data;

int main(void)
{
    int aux;
    data data[tam];
    for(int i=0; i<tam; i++)
    {
        printf("Ingrese el valor entero de 16bits nro %d\n", i+1);
        scanf("%hi", &data[i].valor);
        printf("Ingrese la cadena de texto nro %d\n", i+1);
        scanf("%s", data[i].text);
        printf("Ingrese el valor flotante nro %d\n", i+1);
        scanf("%f", &data[i].aux);
        printf("Ingrese el doble nro %d\n", i+1);
        scanf("%lf", &data[i].doble);

    }
    FILE *f;
    f=fopen("datos.dat", "w");
    if(f==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return 1;
    }
    printf("Archivo abierto correctamente\n");
    for(int i=0;i<tam;i++){
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
