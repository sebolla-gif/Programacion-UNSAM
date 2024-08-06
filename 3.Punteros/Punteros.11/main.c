/*
Suponga que el puntero p está declarado como sigue:
struct mi_estructura {
char a, b;
int c;
int e [5];
};
struct mi_estructura me;
struct mi_estructura *p = &me;

¿Cuáles de las siguientes instrucciones son válidas?
a) p->b = ’ ’;
b) p->e [3] = 10;
c) (*p).a = ’*’;
d) *p.b = ’?’;
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

    // Instrucciones válidas
    p->b = ' ';        // Válida
    p->e[3] = 10;      // Válida
    (*p).a = '*';      // Válida
    me.c = 1;          // Válida

    // Instrucciones inválidas
    // *p.b = '?';    // No válida
    // p.c = 1;       // No válida

    // Imprimir los valores asignados
    printf("a: %c\n", p->a);
    printf("b: %c\n", p->b);
    printf("c: %d\n", me.c);
    printf("e[3]: %d\n", p->e[3]);

    return 0;
}
