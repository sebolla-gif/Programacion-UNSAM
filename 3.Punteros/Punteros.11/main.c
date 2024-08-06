/*
Suponga que el puntero p est� declarado como sigue:
struct mi_estructura {
char a, b;
int c;
int e [5];
};
struct mi_estructura me;
struct mi_estructura *p = &me;

�Cu�les de las siguientes instrucciones son v�lidas?
a) p->b = � �;
b) p->e [3] = 10;
c) (*p).a = �*�;
d) *p.b = �?�;
e) me.c = 1;
f) p.c = 1;
*/
#include <stdio.h>

struct mi_estructura {
    char a, b;
    int c;
    int e[5];
};

int main(void) {
    struct mi_estructura me;
    struct mi_estructura *p = &me;

    // Instrucciones v�lidas
    p->b = ' ';        // V�lida
    p->e[3] = 10;      // V�lida
    (*p).a = '*';      // V�lida
    me.c = 1;          // V�lida

    // Instrucciones inv�lidas
    // *p.b = '?';    // No v�lida
    // p.c = 1;       // No v�lida

    // Imprimir los valores asignados
    printf("a: %c\n", p->a);
    printf("b: %c\n", p->b);
    printf("c: %d\n", me.c);
    printf("e[3]: %d\n", p->e[3]);

    return 0;
}
