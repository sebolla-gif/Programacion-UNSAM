/*
Leer 5 strings por teclado y almacenarlos en un archivo.
*/
#include <stdio.h>
#include <string.h>

void AlmacenarString(int cantidad)
{
    FILE *f = fopen("cadenas.txt","wt");

    char str[100];

    if(f == NULL)
    {
        perror("No se pudo abrir el archivo");
        fclose(f);
        return;
    }

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese una cadena: ");

        gets(str);

        if (fprintf(f, "%s\n", str) < 0)
        {
            perror("Error al escribir en el archivo");
            fclose(f);
            return;
        }
    }

    if (fclose(f) != 0)
    {
        perror("\nError al cerrar el archivo\n");
        return;
    }

}


int main(void)
{
    AlmacenarString(5);

    return 0;
}
