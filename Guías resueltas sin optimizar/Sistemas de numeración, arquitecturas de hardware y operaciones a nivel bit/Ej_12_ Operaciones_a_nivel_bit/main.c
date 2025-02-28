#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned char a;
    printf("Ingrese un valor en decimales (0 a 255)\n");
    scanf("%hhu", &a);
    printf("el valor en HEX es: %02X", a);
    if((a & 0x10) !=0){
        printf("\nEl 5to bit es 1");
    }
    else{
        printf("\nEl 5to bit es 0");
    }
    if((a & 0x01) != 0){
        printf("\nEl primer bit es 1");
    }
    else{
        printf("\nEl primer bit es 0");
    }
    if((a & 0x08) != 0){
        printf("\nEl 4to bit es 1");
    }
    else{
        printf("\nEl 4to bit es 0");
    }
    if(((a & 0x08) != 0) || ((a & 0x01) != 0)){
        printf("\nEl primero o el cuarto estan en 1");
    }
    else{
        printf("\nNi el primero, ni el cuarto estan en 1");
    }
    a = a | 0x80;
    a = a | 0x01;
    printf("\nEl numero con el primer y ultimo bit en 1 es: %hhu ", a);

    a = a & 0x7E; //0x7E 01111110
    printf("\nEl numero con el primer y ultimo bit en 0 es: %hhu ", a);

    //Negar todo los bits

    a = ~a; //not

    printf("\nEl numero negado: %hhu ", a);

    unsigned char mascara = 0x0F; // 0b00001111

    a = (a & ~mascara) | (~a & mascara);

    printf("\nEl numero dolo los ultimos cuatro bits negados: %hhu ", a);


    /*
    a             = 0b00110010 //50
    ~mascara      = 0b11110000
    a & ~mascara  = 0b00110000

    ~a            = 0b11001101
    mascara       = 0b00001111
    ~a & mascara  = 0b00001101

    (a & ~mascara) | (~a & mascara)
    0b00110000     | 0b00001101
    0b00111101
    */
    return 0;
}
