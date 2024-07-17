/*
En C, tanto struct como union son herramientas para agrupar datos, pero se diferencian en cómo se almacenan en memoria.
Un struct asigna una ubicación de memoria individual para cada miembro, mientras que un union los coloca todos en la misma ubicación.

En un struct, cada miembro se puede acceder y modificar de forma independiente sin afectar a los demás.
En cambio, en un union, solo se puede acceder a un miembro a la vez, ya que al modificar uno se sobrescriben los demás.

En resumen, se usan structs para agrupar datos relacionados que se necesitan juntos con frecuencia,
mientras que se usan uniones cuando se necesita almacenar diferentes tipos de datos en la misma variable,
dependiendo del contexto.
*/

#include <stdio.h>
#include <string.h>

// Definición de struct
typedef struct {
    int entero;
    float decimal;
    char texto[20];
} MiStruct;

// Definición de union
typedef union {
    int entero;
    float decimal;
    char texto[20];
} MiUnion;

int main() {
    // Declaración y uso de struct
    MiStruct ejemploStruct;
    ejemploStruct.entero = 42;
    ejemploStruct.decimal = 3.14f;
    strcpy(ejemploStruct.texto, "Hola");

    printf("Struct - entero: %d\n", ejemploStruct.entero);
    printf("Struct - decimal: %.2f\n", ejemploStruct.decimal);
    printf("Struct - texto: %s\n", ejemploStruct.texto);

    // Declaración y uso de union
    MiUnion ejemploUnion;
    ejemploUnion.entero = 42;
    printf("\nUnion después de asignar entero - entero: %d\n", ejemploUnion.entero);

    ejemploUnion.decimal = 3.14f;
    printf("Union después de asignar decimal - decimal: %.2f\n", ejemploUnion.decimal);
    printf("Union después de asignar decimal - entero: %d\n", ejemploUnion.entero);

    strcpy(ejemploUnion.texto, "Hola");
    printf("Union después de asignar texto - texto: %s\n", ejemploUnion.texto);
    printf("Union después de asignar texto - decimal: %.2f\n", ejemploUnion.decimal);

    return 0;
}
