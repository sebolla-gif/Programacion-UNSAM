/*
(opcional) Investigar el uso de la función sprintf(). 
*/
#include <stdio.h>

int main(void)
{
    char buffer[100];
    int num = 42;
    sprintf(buffer, "El n�mero es: %d", num);
    printf("Cadena formateada: %s\n", buffer);
    return 0;
}
/*
En este ejemplo, sprintf() formatea el entero num en la cadena "El n�mero es: %d" y almacena el resultado en el array buffer.
Despu�s, printf() se utiliza para imprimir el contenido de buffer.
Es importante tener en cuenta que sprintf() no hace ninguna comprobaci�n de l�mites para el array str,
lo que significa que si la cadena formateada es demasiado larga para caber en el array proporcionado,
podr�a causar un desbordamiento de b�fer, que es un error grave en programaci�n.
Siempre es recomendable utilizar funciones seguras como snprintf() en lugar de sprintf() si trabajas con datos que podr�an exceder el tama�o del buffer,
para evitar estos problemas de seguridad. snprintf() funciona de manera similar a sprintf(),
pero tambi�n toma un argumento adicional que especifica el tama�o m�ximo del buffer.
*/
