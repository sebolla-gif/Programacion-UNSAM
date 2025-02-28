#include <stdio.h>
#include <sys/io.h> // Para usar inb y outb

// Puertos para acceder al RTC
#define RTC_INDEX_PORT  0x70
#define RTC_DATA_PORT   0x71

// Función para leer un registro del RTC y mostrar su valor en hexadecimal
void leerRTCRegistro(int numeroRegistro) {
    if (numeroRegistro < 0 || numeroRegistro > 13) {
        printf("Número de registro inválido. Debe estar entre 0 y 13.\n");
        return;
    }

    // Habilitar acceso a los puertos de E/S (se requiere privilegios de superusuario)
    if (ioperm(RTC_INDEX_PORT, 2, 1)) {
        perror("No se pudo obtener permiso para los puertos de E/S");
        return;
    }

    // Seleccionar el registro del RTC
    outb(numeroRegistro, RTC_INDEX_PORT);
    // Leer el valor del registro
    unsigned char valor = inb(RTC_DATA_PORT);

    // Imprimir el valor en hexadecimal
    printf("El valor del registro RTC %d es: 0x%02X\n", numeroRegistro, valor);

    // Deshabilitar acceso a los puertos de E/S
    ioperm(RTC_INDEX_PORT, 2, 0);
}

int main() {
    int numeroRegistro;

    // Solicitar al usuario el número del registro RTC
    printf("Ingrese el número del registro RTC (0-13): ");
    scanf("%d", &numeroRegistro);

    // Leer y mostrar el valor del registro RTC
    leerRTCRegistro(numeroRegistro);

    return 0;
}
