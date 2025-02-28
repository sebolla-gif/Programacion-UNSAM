#include <stdio.h>
#include <stdlib.h>

int menu(int a)
{

    printf("\n1. Informar el tamaño del archivo\n2. Mostrar la hora en formato hh:mi:ss\n3. Mostrar el año completo en formato aaaa, es decir, si fuera 2022 deberíamostrar 2022\n4. Informar si el bit AIE está activo (si/no)\n5. Salir\n");
    scanf("%d", &a);
    return a;
}

void tamanodelarchivo(const char* nombre)
{
    FILE* f;
    unsigned char aux;
    int res, cont = 0;
    /* Abrir archivo para lectura en modo binario */
    f = fopen(nombre, "rb"); /*b significa binario. No tiene efecto en Linux */
    if (f == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }

    /* Leer archivo */
    res = fread(&aux, sizeof aux, 1, f); /* Leer un entero */
    while (res == 1)
    {
        cont++;
        res = fread(&aux, sizeof aux, 1, f);
    }
    printf("En el archivo hay %d bytes",cont);
    /* Cerrar archivo */
    res = fclose(f);
    if (res != 0)
    {
        printf("\nError al cerrar el archivo\n");
        return;
    }

    printf("\n");

}

void cargardatos(unsigned char* rtc,const char *nombre)
{
    FILE* f;
    int res;
    /* Abrir archivo para lectura en modo binario */
    f = fopen(nombre, "rb"); /*b significa binario. No tiene efecto en Linux */
    if (f == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }
    fread(rtc, sizeof(unsigned char), 64, f);
    /* Cerrar archivo */
    res = fclose(f);
    if (res != 0)
    {
        printf("\nError al cerrar el archivo\n");
        return;
    }
    printf("\n");

    return;
}


int main(void)
{
    unsigned char aie,seg, min, hora, an1, an2;
    unsigned char rtc[64];
    int a;
    cargardatos(rtc,"rtc.bin");
    do
    {
        a = menu(a);
        switch(a)
        {
        case 1:
            tamanodelarchivo("rtc.bin");
            break;
        case 2:
            seg = rtc[0];
            min = rtc[2];
            hora = rtc[4];
            printf ("Hora: %02x:%02x:%02x\n", hora, min, seg);
            break;
        case 3:
            an1 = rtc[0x32];
            an2 = rtc[9];
            printf("Anio: %02x%02x\n", an1, an2);
            break;
        case 4:
            aie = rtc[0xb];
            if((aie & 0x20)!= 0)
            {
                printf("\n AIE esta activo\n");
            }
            else
            {
                printf("\nEl AIE esta inactivo\n");
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


/*







*/
