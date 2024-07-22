/*
¿Cuál es la diferencia entre un struct y un union? 

En C, tanto struct como union son herramientas para agrupar datos, pero se diferencian en c�mo se almacenan en memoria.
Un struct asigna una ubicaci�n de memoria individual para cada miembro, mientras que un union los coloca todos en la misma ubicaci�n.

En un struct, cada miembro se puede acceder y modificar de forma independiente sin afectar a los dem�s.
En cambio, en un union, solo se puede acceder a un miembro a la vez, ya que al modificar uno se sobrescriben los dem�s.

En resumen, se usan structs para agrupar datos relacionados que se necesitan juntos con frecuencia,
mientras que se usan uniones cuando se necesita almacenar diferentes tipos de datos en la misma variable,
dependiendo del contexto.
*/

#include <stdio.h>
#include <string.h>

// Definici�n de struct
typedef struct {
    int entero;
    float decimal;
    char texto[20];
} MiStruct;

// Definici�n de union
typedef union {
    int entero;
    float decimal;
    char texto[20];
} MiUnion;

int main() {
    // Declaraci�n y uso de struct
    MiStruct ejemploStruct;
    ejemploStruct.entero = 42;
    ejemploStruct.decimal = 3.14f;
    strcpy(ejemploStruct.texto, "Hola");

    printf("Struct - entero: %d\n", ejemploStruct.entero);
    printf("Struct - decimal: %.2f\n", ejemploStruct.decimal);
    printf("Struct - texto: %s\n", ejemploStruct.texto);

    // Declaraci�n y uso de union
    MiUnion ejemploUnion;
    ejemploUnion.entero = 42;
    printf("\nUnion despu�s de asignar entero - entero: %d\n", ejemploUnion.entero);

    ejemploUnion.decimal = 3.14f;
    printf("Union despu�s de asignar decimal - decimal: %.2f\n", ejemploUnion.decimal);
    printf("Union despu�s de asignar decimal - entero: %d\n", ejemploUnion.entero);

    strcpy(ejemploUnion.texto, "Hola");
    printf("Union despu�s de asignar texto - texto: %s\n", ejemploUnion.texto);
    printf("Union despu�s de asignar texto - decimal: %.2f\n", ejemploUnion.decimal);

    return 0;
}
