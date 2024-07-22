/*
Leer los strings del archivo del ej. anterior y mostrarlos en pantalla. 
*/
#include <stdio.h>
#include <string.h>

void LeerStrings()
{
    char str[100];
    FILE *f = fopen("cadenas.txt","rt");//Debe estar el archivo del problema anterior en la raiz del programa.
    if(f == NULL)
    {
        perror("No se pudo abrir el archivo");
        return;
    }
    while(fgets(str, sizeof(str), f) != NULL)
    {
        printf("%s", str);
    }
    if (fclose(f) != 0)
    {
        perror("\nError al cerrar el archivo\n");
        return;
    }


}

int main(void)
{
    LeerStrings();
    return 0;
}
