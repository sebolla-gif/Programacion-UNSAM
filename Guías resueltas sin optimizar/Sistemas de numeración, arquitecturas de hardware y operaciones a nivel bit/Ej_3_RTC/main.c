#include <stdio.h>
#include <sys/io.h> // Para usar inb y outb

// Puertos para acceder al RTC
#define RTC_INDEX_PORT  0x70
#define RTC_DATA_PORT   0x71

// Función para leer un registro del RTC y mostrar su valor en hexadecimal
unsigned char leerRTCRegistro(int numeroRegistro) {
    // Seleccionar el registro del RTC
    outb(numeroRegistro, RTC_INDEX_PORT);
    // Leer el valor del registro
    return inb(RTC_DATA_PORT);
}

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

// Función para imprimir los flags de un registro
void imprimir_flags(const char* nombre_registro, unsigned char valor) {
    printf("Registro %s: %02X\n", nombre_registro, valor);
    mostrarBinario(valor);
    printf("\n");

    // Aquí podrías añadir más información sobre cada flag específico
    // Por ejemplo:
    if (nombre_registro == "A") {
        // Flags del registro A
        printf("UIP: %d\n", (valor >> 7) & 1); // Update-in-progress
        // Otros flags...
    } else if (nombre_registro == "B") {
        // Flags del registro B
        printf("SET: %d\n", (valor >> 7) & 1); // Set time
        // Otros flags...
    } else if (nombre_registro == "C") {
        // Flags del registro C
        printf("IRQF: %d\n", (valor >> 7) & 1); // Interrupt request flag
        // Otros flags...
    } else if (nombre_registro == "D") {
        // Flags del registro D
        printf("VRT: %d\n", (valor >> 7) & 1); // Valid RAM and time
        // Otros flags...
    }
}

int main(void)
{
    // Leer y mostrar los flags de los registros A, B, C y D
    unsigned char valor_A = leer_registro_rtc(10); // Registro A está en 0x0A (10)
    unsigned char valor_B = leer_registro_rtc(11); // Registro B está en 0x0B (11)
    unsigned char valor_C = leer_registro_rtc(12); // Registro C está en 0x0C (12)
    unsigned char valor_D = leer_registro_rtc(13); // Registro D está en 0x0D (13)

    imprimir_flags("A", valor_A);
    imprimir_flags("B", valor_B);
    imprimir_flags("C", valor_C);
    imprimir_flags("D", valor_D);

    return 0;
}
