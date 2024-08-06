/*
Suponga que primero, ultimo y medio son punteros del mismo tipo y
primero y ultimo apuntan al primer y último elemento de un vector.  Si quiere
que medio apunte al elemento que está en la mitad del vector ¿por qué la siguiente
instrucción es inválida y cómo se podría solucionar?
medio = (primero + ultimo) / 2;
*/
#include <stdio.h>

int main(void)
{
    int vector[10];
    for (int i = 0; i < 10; i++)
    {
        vector[i] = i;
    }

    int *primero = vector;
    int *ultimo = vector + 9;
    int *medio = primero + (ultimo - primero)/ 2;

    printf("El valor en la posicion media es: %d\n", *medio);
    return 0;
}
/*
    medio = (primero + ultimo) / 2; esta no es una operacion permitida en la aritmetica de punteros
    medio = primero + (ultimo - primero) / 2;
    aca sacamos un valor que es la diferencia de las ubicaciones de memoria dividido por 2 y a ese valor le sumamos la primer ubicacion de memoria
    esto si da como resultado una ubicacion de memoria.
*/
