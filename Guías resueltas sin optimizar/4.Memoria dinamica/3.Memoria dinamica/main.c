#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicar(char *str)
{

    int len=strlen(str);
    // Reservar memoria dinámicamente para la nueva cadena
    char *duplicated_str = (char *)malloc((len + 1) * sizeof(char));

    // Verificar si la reserva de memoria fue exitosa
    if (duplicated_str == NULL)
    {
        return NULL; // Retornar NULL si la reserva falla
    }

    // Copiar los datos de la cadena original a la nueva cadena
    strcpy(duplicated_str, str);

    return duplicated_str; // Retornar el puntero a la nueva cadena duplicada


}

int main(void)
{
    char *str="Hola";
    char *p=duplicar(str);
    // Verificar si la reserva de memoria fue exitosa
    if (p != NULL)
    {
        printf("Cadena duplicada: %s\n", p);
        free(p); // Liberar la memoria asignada a la cadena duplicada
    }
    else
    {
        printf("Error: No se pudo duplicar la cadena. La reserva de memoria falló.\n");
    }
    return 0;
}
