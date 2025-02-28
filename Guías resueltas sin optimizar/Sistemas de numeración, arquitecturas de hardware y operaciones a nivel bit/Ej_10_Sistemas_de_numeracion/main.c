#include <stdio.h>

// Función para convertir un valor de 8 bits sin signo a binario y mostrarlo en pantalla
void mostrarBinario(unsigned char valor) {
    char binario[9]; // Arreglo para almacenar los bits y el carácter nulo al final
    binario[8] = '\0'; // Carácter nulo para terminar la cadena

    // Convertir el valor a binario
    for (int i = 7; i >= 0; i--) {
        binario[i] = (valor % 2) ? '1' : '0';
        valor /= 2;
    }

    // Mostrar el valor en binario
    printf("El valor en binario es: %s\n", binario);
}

int main(void) {
    unsigned char valor;

    // Solicita al usuario que ingrese un valor decimal sin signo de 8 bits
    printf("Ingrese un valor decimal sin signo de 8 bits (0-255): ");
    scanf("%hhu", &valor); // %hhu es el especificador de formato para unsigned char

    // Llamar a la función para mostrar el valor en binario
    mostrarBinario(valor);

    return 0;
}
