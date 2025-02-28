/*
Para elegir entre el CISC o el RISC en la arquitectura de un microcontrolador tomaria en cuenta principalmente
el uso de memoria. Si cuento con la memoria suficiente elegiria el uso de RISC, en caso contrario optaria por el uso de un CISC.
Si bien el CISC requiere menos uso de memoria, el RISC en comparacion es mas eficiente al momento de hacer operaciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tamanodelarchivo(const char* nombre)
{
    FILE* f;
    unsigned char aux;
    int cont1 = 0,cont0 = 0;
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
        //5to
        if((aux & 0x10) !=0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //1ro
        if((aux & 0x01) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //4to
        if((aux & 0x08) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //2do
        if((aux & 0x02) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //3ro
        if((aux & 0x04) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //6to
        if((aux & 0x20) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //7mo
        if((aux & 0x40) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }
        //8vo
        if((aux & 0x80) != 0)
        {
            cont1++;
        }
        else
        {
            cont0++;
        }

    }
    printf("En el archivo hay %d bytes\n",cont);
    printf("La cantodad total de bits cero %d\n",cont0);
    printf("La cantodad total de bits uno %d\n",cont1);
    double por = (double)((double)cont0/(double)(cont0+cont1));
    printf("El porcentaje de 0: %.2lf\n",por*100);
    por = (double)((double)cont1/(double)(cont0+cont1));
    printf("El porcentaje de 1: %.2lf\n",por*100);
    /* Cerrar archivo */
    res = fclose(f);
    if (res != 0)
    {
        printf("\nError al cerrar el archivo\n");
        return;
    }

    printf("\n");

}

int contarcadena(unsigned char *r)
{
    int contador=0;
    while(*r != '\0')
    {
        contador++;
        r++;
    }

    return contador;
}

int menu(int a)
{
    printf("\n1.Mostrar datos\n2.Guardar datos\n3.Leer datos\n4.RTC\n5.Salir\n");
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
    printf("%s\n", binario);
}


int main(void)
{
    unsigned char *r,*aux;
    r = (unsigned char *) "HOY {ES UN LINDO DIA (PARA SALIR A CAMINAR (al aire libre)}";
    aux = r;
    FILE* f;
    int a,cont,num,res;
    unsigned char auxc,c;
    do
    {
        a = menu(a);
        switch(a)
        {
        case 1:
            r = aux;
            while(*r != '\0')
            {
                printf("%c %d 0x%02x ", *r, *r, *r);
                mostrarBinario(*r);
                r++;
            }
            break;
        case 2:
            cont=0;
            f = fopen("resultados.bin", "wb");
            if (f == NULL)
            {
                printf("\nError al abrir el archivo\n");
                break;
            }
            r = aux;
            cont=contarcadena(r);
            //printf("%d", cont);
            printf("ingrese el numero: ");
            scanf("%d", &num);
            while(num>cont || num<0)
            {
                printf("\nEl valor no se encuentra en el vector, ingrese el numero nuevamente");
                scanf("%d", &num);
            }
            printf("Ingrese 1 si desea usar &\n");
            printf("Ingrese 2 si desea usar |\n");
            scanf("%d", &a);
            switch(a)
            {
            case 1:
                r = aux;
                while(*r != '\0')
                {
                    auxc = (*r & r[num]);
                    res=fwrite(&auxc,sizeof (unsigned char),1,f);
                    if(res!=1)
                    {
                        perror("error al escribir el archivo");
                        break;
                    }
                    printf("%02x\n", auxc);
                    r++;
                }
                break;
            case 2:
                r = aux;
                while(*r != '\0')
                {
                    auxc = (*r | r[num]);
                    res=fwrite(&auxc,sizeof (unsigned char),1,f);
                    if(res!=1)
                    {
                        perror("error al escribir el archivo");
                        break;
                    }
                    printf("%02x\n", auxc);
                    r++;
                }
                break;
            default:
                printf("opcion no valida");
                break;
            }
            /* Cerrar archivo */
            res = fclose(f);
            if (res != 0)
            {
                printf("\nError al cerrar el archivo\n");
                break;
            }
            break;
        case 3:
            tamanodelarchivo("resultados.bin");
            break;
        case 4:
            r = aux;
            cont = contarcadena(r);
            c = *(r+(cont-2));
            if (c & 0x20){
                printf ("Alarma activada\n");
            }
            else{
                printf ("Alarma desactivada\n");
            }
            break;
        case 5:
            break;
        default:
            break;
        }

    }
    while(a != 5);
    return 0;
}
