#include <stdio.h>

// Función para verificar si un valor de 8 bits es un BCD válido
int esBCDValido(unsigned char valor) {
    // Extraer el nibble superior (bits 7-4)
    unsigned char nibbleSuperior = (valor >> 4) & 0x0F;
    // Extraer el nibble inferior (bits 3-0)
    unsigned char nibbleInferior = valor & 0x0F;

    // Verificar si ambos nibbles son valores BCD válidos (0-9)
    if (nibbleSuperior <= 9 && nibbleInferior <= 9) {
        return 1; // true
    } else {
        return 0; // false
    }
}

int main() {
    unsigned char valor;

    // Solicita al usuario que ingrese un valor decimal sin signo de 8 bits
    printf("Ingrese un valor decimal sin signo de 8 bits (0-255): ");
    scanf("%hhu", &valor); // %hhu es el especificador de formato para unsigned char

    // Verificar si el valor es un BCD válido
    if (esBCDValido(valor)) {
        printf("El valor %d es un BCD válido.\n", valor);
    } else {
        printf("El valor %d no es un BCD válido.\n", valor);
    }

    return 0;
}
