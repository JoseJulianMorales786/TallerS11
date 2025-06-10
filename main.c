#include <stdio.h>
#include "funciones.h"

int main() {
    Libro biblioteca[MAX_LIBROS];
    int contador = 0;
    int opcion;

    do {
        printf("\nGestion de Biblioteca\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");

        // Validar entrada numerica para la opcion
        do {
            printf("Seleccione una opcion: ");
            if (scanf("%d", &opcion) != 1) {
                printf("Entrada invalida. Por favor ingrese un numero.\n");
                while (getchar() != '\n'); // Limpiar el buffer
                opcion = -1; // Valor invalido para repetir el ciclo
            }
        } while (opcion < 1 || opcion > 6);

        // Limpiar el buffer después de leer la opción
        while (getchar() != '\n'); // Limpiar el buffer

        switch (opcion) {
            case 1:
                registrarLibro(biblioteca, contador);
                contador++;
                break;
            case 2:
                mostrarLibros(biblioteca, contador);
                break;
            case 3:
                buscarLibro(biblioteca, contador);
                break;
            case 4:
                actualizarEstado(biblioteca, contador);
                break;
            case 5:
                eliminarLibro(biblioteca, contador);
                contador--;
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}