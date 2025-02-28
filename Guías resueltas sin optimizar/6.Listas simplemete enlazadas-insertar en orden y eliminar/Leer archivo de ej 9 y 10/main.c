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

    FILE *f;
    f=fopen("C://Users//sebav//Documents//Programacion//6.Listas simplemete enlazadas-insertar en orden y eliminar//Archivo para 9 y 10//datos.dat", "r");
    if(f==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return 1;
    }
    printf("Archivo abierto correctamente\n");
    for(int i=0;i<4;i++){
        aux = fread(&data[i], sizeof (data[i]), 1, f);
        if(aux!=1){
           printf("\nError al escribir el archivo\n");
           return 2;
        }
        printf("valor entero nro %d: %d\n",i+1,data[i].valor);
        printf("valor flotante nro %d: %f\n",i+1,data[i].aux);
        printf("texto nro %d: %s\n",i+1,data[i].text);
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
