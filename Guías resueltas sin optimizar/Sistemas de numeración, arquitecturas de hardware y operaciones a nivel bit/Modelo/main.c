#include <stdio.h>
#include <stdlib.h>

int menu(int a)
{
    printf("\n1.Mostrar datos\n2.Guardar datos\n3.RTC\n4.PF\n5.Salir\n");
    scanf("%d", &a);
    return a;
}

// Función para convertir un valor de 8 bits sin signo a binario y mostrarlo en pantalla
void mostrarBinario(unsigned char valor)
{
    char binario[9]; // Arreglo para almacenar los bits y el carácter nulo al final
    binario[8] = '\0'; // Carácter nulo para terminar la cadena

    // Convertir el valor a binario
    for (int i = 7; i >= 0; i--)
    {
        binario[i] = (valor % 2) ? '1' : '0';
        valor /= 2;
    }

    // Mostrar el valor en binario
    printf("El valor en binario es: %s\n", binario);
}

void mostrarhex(unsigned char valor)
{

    // Muestra el valor en formato hexadecimal
    printf("El valor en hexadecimal es: %02X\n", valor);

}

// Función para verificar si un valor de 8 bits es un BCD válido
int esBCDValido(unsigned char valor)
{

    // Extraer el valor superior (bits 7-4)
    unsigned char valorSuperior = (valor >> 4) & 0x0F;

    // Extraer el valor inferior (bits 3-0)
    unsigned char valorInferior = valor & 0x0F;

    // Verificar si ambos nibbles son valores BCD válidos (0-9)
    if (valorSuperior <= 9 && valorInferior <= 9)
    {
        return 1; // true
    }
    else
    {
        return 0; // false
    }
}


int main(void)
{
    char* datos = "QUIERO ganar la tercera.";
    unsigned char *r = (unsigned char *)datos;
    FILE* f;
    int a,res;
    do
    {
        a = menu(a);
        switch(a)
        {
        case 1:
            r = (unsigned char *)datos;
            a=0;
            while(*r != '\0')
            {
                printf("%d",a);
                a++;
                mostrarBinario(*r);
                mostrarhex(*r);
                if(esBCDValido(*r)==1)
                {
                    printf("Es BCD valido\n");
                }
                else
                {
                    printf("No es BCD valido\n");
                }
                r++;
            }
            break;
        case 2:
            r = (unsigned char *)datos;
            f = fopen("datos.bin", "wb");
            if (f == NULL)
            {
                printf("\nError al abrir el archivo\n");
                break;
            }
            while(*r != '\0')
            {
                if(((*r & 0x01) != 0) && ((*r & 0x02) != 0))
                {
                    res=fwrite(r,sizeof (unsigned char),1,f);
                    if(res!=1){
                        perror("error al escribir el archivo");
                        break;
                    }
                }
                r++;
            }
            /* Cerrar archivo */
            res = fclose(f);
            if (res != 0)
            {
                printf("\nError al cerrar el archivo\n");
                break;
            }

            printf("\n");
            break;
        case 3:
            r = (unsigned char *)datos;
            printf ("minutos: %02x\n", *(r+0x02));
            printf ("minutos alarma: %02x\n", *(r+0x03));
            break;
        case 4:
            r = (unsigned char *)datos;
            if((*(r+0xc) & 0x40) != 0){
                printf("PF activo\n");
            }else{
                printf("PF inactivo\n");
            }
            break;
        case 5:
            break;
        default:
            break;
        }

    } while(a != 5);

    return 0;
}
