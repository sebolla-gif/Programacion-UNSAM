/*
Escribir un programa que imprima los elementos de un vector de enteros en orden
inverso utilizando punteros (no usar subíndices []).
int v[10] = {1,2,3,4,5,6,7,8,9,10};
int *p;
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = v;
    for(int i=9; i>=0; i--)
    {
        printf("%d ", *(p+i));
    }
    return 0;
}
