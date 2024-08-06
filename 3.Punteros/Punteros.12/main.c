/*
Suponga que f y p están declarados como sigue:
struct {
union {
char a, b;
int c;
} d;
int e [5];
} f, *p = &f;
¿Cuáles de las siguientes instrucciones son válidas?
g) p->b = ’ ’;
h) p->e [3] = 10;
i) (*p).d.a = ’*’;
j) p->d->c = ’x’;
*/
#include <stdio.h>
#include <stdlib.h>

struct f
{
    union
    {
        char a, b;
        int c;
    } d;
    int e [5];
} f, *p = &f;

int main(void)
{
    p->e [3] = 10;
    (*p).d.a = '*';
    //p->b = ' '; opcion invalida, para llegar a b hay que entrar primero a la union d.
    //p->d->c = 'x'; opcion invalida, d no es un puntero.

    return 0;
}
