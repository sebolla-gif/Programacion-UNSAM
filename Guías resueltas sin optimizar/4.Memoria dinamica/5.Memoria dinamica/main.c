#include <stdio.h>
#include <stdlib.h>

struct punto
{
    int x;
    int y;
};
struct rectangulo
{
    struct punto superior_izq;
    struct punto inferior_der;
};


int main(void)
{
    // Asignar memoria dinámicamente para una estructura rectangulo
    struct rectangulo *p = (struct rectangulo *)malloc(sizeof(struct rectangulo));

    if (p == NULL) {
        printf("Error: No se pudo asignar memoria para la estructura rectangulo\n");
        return 1;
    }

    // Establecer las coordenadas para los puntos superior_izq e inferior_der
    p->superior_izq.x = 10;
    p->superior_izq.y = 25;
    p->inferior_der.x = 20;
    p->inferior_der.y = 15;

    // Acceder a las coordenadas del rectangulo a través de p
    printf("Coordenadas del rectangulo:\n");
    printf("Superior izquierda: (%d, %d)\n", p->superior_izq.x, p->superior_izq.y);
    printf("Inferior derecha: (%d, %d)\n", p->inferior_der.x, p->inferior_der.y);

    // Liberar la memoria asignada
    free(p);

    return 0;
}
