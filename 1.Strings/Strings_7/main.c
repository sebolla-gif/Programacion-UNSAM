#include <stdio.h>

int main(void)
{
    char buffer[100];
    int num = 42;
    sprintf(buffer, "El número es: %d", num);
    printf("Cadena formateada: %s\n", buffer);
    return 0;
}
/*
En este ejemplo, sprintf() formatea el entero num en la cadena "El número es: %d" y almacena el resultado en el array buffer.
Después, printf() se utiliza para imprimir el contenido de buffer.
Es importante tener en cuenta que sprintf() no hace ninguna comprobación de límites para el array str,
lo que significa que si la cadena formateada es demasiado larga para caber en el array proporcionado,
podría causar un desbordamiento de búfer, que es un error grave en programación.
Siempre es recomendable utilizar funciones seguras como snprintf() en lugar de sprintf() si trabajas con datos que podrían exceder el tamaño del buffer,
para evitar estos problemas de seguridad. snprintf() funciona de manera similar a sprintf(),
pero también toma un argumento adicional que especifica el tamaño máximo del buffer.
*/
