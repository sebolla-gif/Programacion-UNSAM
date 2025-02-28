#include <stdio.h>
#include <stdlib.h>

void grabar(int *v,int n)
{

    int w;

    // Abrir el archivo para escritura
    FILE *archivo = fopen("vector.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error: no se pudo abrir el archivo.\n");
        return;
    }

    // Escribir los elementos en el archivo
    w = fwrite(v, sizeof(int), n, archivo);
    if(w != n)
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
    printf("Los elementos se han guardado en el archivo vector.dat.\n");
}



int main()
{
    int cantidad_elementos;

    // Solicitar al usuario la cantidad de elementos
    printf("Ingrese la cantidad de elementos que desea ingresar: ");
    scanf("%d", &cantidad_elementos);

    // Crear un vector dinámico para almacenar los elementos
    int *vector = (int *)malloc(cantidad_elementos * sizeof(int));
    if (vector == NULL)
    {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Solicitar al usuario ingresar los valores de los elementos
    printf("Ingrese los elementos:\n");
    for (int i = 0; i < cantidad_elementos; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", (vector+i));
    }
    grabar(vector,cantidad_elementos);
    free(vector);

    return 0;
}
