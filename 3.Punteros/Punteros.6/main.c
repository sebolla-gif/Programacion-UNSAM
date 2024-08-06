/*
Suponga que se ejecutan las siguientes instrucciones:
int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a [1], *q = &a [5];

a. �Cu�l es el valor de *(p+3)?
b. �Cu�l es el valor de *(q-3)?
c. �Cu�l es el valor de q-p?
d. �La condici�n p<q es verdadera o falsa?
e. �La condici�n *p<*q es verdadera o falsa?
*/
#include <stdio.h>

int main(void) {
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1];  // p apunta a a[1], es decir, 15
    int *q = &a[5];  // q apunta a a[5], es decir, 2

    // a. �Cu�l es el valor de *(p+3)?
    int val_p_plus_3 = *(p + 3);  // Esto es a[4], que es 14
    printf("El valor de *(p+3) es: %d\n", val_p_plus_3);

    // b. �Cu�l es el valor de *(q-3)?
    int val_q_minus_3 = *(q - 3);  // Esto es a[2], que es 34
    printf("El valor de *(q-3) es: %d\n", val_q_minus_3);

    // c. �Cu�l es el valor de q-p?
    int diff_q_p = q - p;  // Esto es 5 - 1, que es 4
    printf("El valor de q-p es: %d\n", diff_q_p);

    // d. �La condici�n p<q es verdadera o falsa?
    int condition_p_less_q = (p < q);  // Esto es verdadero porque 1 < 5
    printf("La condici�n p<q es: %s\n", condition_p_less_q ? "verdadera" : "falsa");

    // e. �La condici�n *p<*q es verdadera o falsa?
    int condition_val_p_less_val_q = (*p < *q);  // Esto es falso porque 15 < 2 es falso
    printf("La condici�n *p<*q es: %s\n", condition_val_p_less_val_q ? "verdadera" : "falsa");

    return 0;
}
/*
NOTA:
 En un vector de memoria est�tica, las direcciones de memoria se asignan en orden creciente en hexadecimal.
Por lo tanto, la direcci�n a la que apunta q es mayor que la direcci�n a la que apunta p.
Al restar q menos p, se obtiene una diferencia positiva en hexadecimal."
*/
