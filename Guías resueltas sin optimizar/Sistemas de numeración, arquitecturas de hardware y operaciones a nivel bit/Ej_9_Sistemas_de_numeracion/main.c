#include <stdio.h>

void mostrarhex(unsigned char valor){

    // Solicita al usuario que ingrese un valor decimal sin signo de 8 bits
    printf("Ingrese un valor decimal sin signo de 8 bits (0-255): ");

    // %hhu es el especificador de formato para unsigned char
    scanf("%hhu", &valor);

    // Muestra el valor en formato hexadecimal
    printf("El valor en hexadecimal es: %02X\n", valor);

}

void mostrarendec(unsigned char valor){

    // Solicita al usuario que ingrese un valor hexadecimal sin signo de 8 bits
    printf("Ingrese un valor hexadecimal sin signo de 8 bits (00-FF): ");

    // %hhx es el especificador de formato para unsigned char en hexadecimal
    scanf("%hhx", &valor);

    // Muestra el valor en formato decimal
    printf("El valor en decimal es: %u\n", valor);
}


int main(void) {

    unsigned char valor;

    mostrarhex(valor);

    mostrarendec(valor);

    return 0;
}
