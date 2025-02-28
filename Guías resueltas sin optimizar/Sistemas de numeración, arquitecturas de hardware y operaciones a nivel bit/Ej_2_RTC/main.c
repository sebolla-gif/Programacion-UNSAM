#include <stdio.h>
#include <sys/io.h> // Para usar inb y outb

// Puertos para acceder al RTC
#define RTC_INDEX_PORT  0x70
#define RTC_DATA_PORT   0x71



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


// Función para leer un registro del RTC y mostrar su valor en hexadecimal
unsigned char leerRTCRegistro(int numeroRegistro) {
    // Seleccionar el registro del RTC
    outb(numeroRegistro, RTC_INDEX_PORT);
    // Leer el valor del registro
    return inb(RTC_DATA_PORT);
}

int main()
{

    // Descripciones de los primeros 13 registros del RTC
    const char* descripciones[] =
    {
        "Segundo",
        "Alarma segundo",
        "Minuto",
        "Alarma minuto",
        "Hora",
        "Alarma hora",
        "Dia de la semana",
        "Dia del mes",
        "Mes",
        "Ano",
        "Registro A",
        "Registro B",
        "Registro C",
        "Registro D"
    };

    // Habilitar acceso a los puertos de E/S (se requiere privilegios de superusuario)
    if (ioperm(RTC_INDEX_PORT, 2, 1)) {
        perror("No se pudo obtener permiso para los puertos de E/S");
        return 1;
    }

    // Mostrar los valores de los primeros 13 registros del RTC con descripciones
    for (int i = 0; i <= 13; i++) {
        unsigned char valor = leerRTCRegistro(i);
        printf("%s: 0x%02X\n", descripciones[i], valor);
        mostrarBinario(valor);
    }

    // Deshabilitar acceso a los puertos de E/S
    ioperm(RTC_INDEX_PORT, 2, 0);

    return 0;
}
