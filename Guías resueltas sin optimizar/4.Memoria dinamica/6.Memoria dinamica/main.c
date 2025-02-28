/************************************************************************************************************************************************************
Las funciones memset() y memcpy() son funciones estándar de la biblioteca estándar de C (<string.h>) que se utilizan para manipular bloques de memoria.

memset(): La función memset() se utiliza para establecer un valor específico en un bloque de memoria.
Toma tres argumentos: un puntero al inicio del bloque de memoria que se va a llenar,
el valor que se utilizará para llenar el bloque y el número de bytes que se llenarán.
La función asigna el valor especificado a cada byte del bloque de memoria.
memcpy(): La función memcpy() se utiliza para copiar un bloque de memoria de origen a un bloque de memoria de destino.
Toma tres argumentos: un puntero al inicio del bloque de memoria de destino,
un puntero al inicio del bloque de memoria de origen y el número de bytes que se copiarán.
La función copia los bytes desde el bloque de memoria de origen al bloque de memoria de destino.
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Aquí tienes un programa de ejemplo que demuestra el uso de ambas funciones:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Ejemplo de uso de memset()
    int n=10;
    char *buffer=(char *)malloc(sizeof(char)*n);
    printf("Antes de memset(): %s\n", buffer); // El contenido inicial del buffer es impredecible
    memset(buffer,'*', sizeof(char)*(n-1)); // Llenar el buffer con el caracter '*'
    *(buffer+n)='\0';
    printf("Después de memset(): %s\n", buffer); // El buffer ahora está lleno de '*'

    // Ejemplo de uso de memcpy()
    char *source = "Hello, world!";
    int len_source = strlen(source);
    char *destination=(char *)malloc(sizeof(char)*(len_source + 1));

    printf("Antes de memcpy(): %s\n", destination); // El contenido inicial del destino es impredecible

    memcpy(destination, source, len_source + 1); // Copiar el contenido de source a destination
    printf("Después de memcpy(): %s\n", destination); // El destino ahora contiene el mismo contenido que source

    return 0;
}
