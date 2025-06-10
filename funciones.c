#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibro(Libro biblioteca[], int contador) {
    if (contador >= MAX_LIBROS) {
        printf("No se pueden agregar mas libros.\n");
        return;
    }

    Libro nuevoLibro;
    char idInput[20]; // Buffer para leer la entrada del ID

    // Validar ID unico y que sea un numero
    do {
        printf("Ingrese el ID del libro (solo numeros): ");
        fgets(idInput, sizeof(idInput), stdin);
        idInput[strcspn(idInput, "\n")] = '\0'; // Eliminar salto de linea

        // Verificar que la entrada sea un numero
        int valido = 1;
        for (int i = 0; idInput[i] != '\0'; i++) {
            if (idInput[i] < '0' || idInput[i] > '9') {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("Entrada invalida. Por favor ingrese solo numeros.\n");
            continue;
        }

        
        // Verificar que el ID sea unico
        int idUnico = 1;
        for (int i = 0; i < contador; i++) {
            if (biblioteca[i].id == nuevoLibro.id) {
                idUnico = 0;
                break;
            }
        }

        if (!idUnico) {
            printf("El ID ya existe. Intente nuevamente.\n");
        } else {
            break; // Salir del ciclo si el ID es valido y unico
        }
    } while (1);

    printf("Ingrese el titulo del libro: ");
    fgets(nuevoLibro.titulo, MAX_TITULO, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0'; // Eliminar salto de linea

    printf("Ingrese el autor del libro: ");
    fgets(nuevoLibro.autor, MAX_AUTOR, stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0';

    int anioValido;
    do {
        printf("Ingrese el año de publicacion: ");
        anioValido = scanf("%d", &nuevoLibro.anio);
        if (!anioValido) {
            printf("Entrada invalida. Por favor ingrese un numero.\n");
            while (getchar() != '\n'); // Limpiar el buffer
        }
    } while (!anioValido);

    int estado;
    do {
        printf("Ingrese el estado del libro (1. Disponible, 2. Prestado): ");
        estado = scanf("%d", &estado);
        if (estado == 1) {
            strcpy(nuevoLibro.estado, "Disponible");
        } else if (estado == 2) {
            strcpy(nuevoLibro.estado, "Prestado");
        } else {
            printf("Estado invalido. Intente nuevamente.\n");
            while (getchar() != '\n'); // Limpiar el buffer
        }
    } while (estado != 1 && estado != 2);

    biblioteca[contador] = nuevoLibro;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(Libro biblioteca[], int contador) {
    printf("ID\tTitulo\t\tAutor\t\tAño\tEstado\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n", biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
    }
}

void buscarLibro(Libro biblioteca[], int contador) {
    int opcion;
    printf("Buscar por: 1. ID 2. Titulo\n");
    do {
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1 || (opcion != 1 && opcion != 2)) {
            printf("Entrada invalida. Por favor ingrese 1 o 2.\n");
            while (getchar() != '\n'); // Limpiar el buffer
            opcion = -1; // Valor invalido para repetir el ciclo
        }
    } while (opcion != 1 && opcion != 2);

    if (opcion == 1) {
        int id;
        printf("Ingrese el ID del libro: ");
        scanf("%d", &id);
        while (getchar() != '\n'); // Limpiar el buffer
        for (int i = 0; i < contador; i++) {
            if (biblioteca[i].id == id) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                return;
            }
        }
    } else if (opcion == 2) {
        char titulo[MAX_TITULO];
        printf("Ingrese el titulo del libro: ");
        getchar(); // Limpiar buffer
        fgets(titulo, MAX_TITULO, stdin);
        titulo[strcspn(titulo, "\n")] = '\0';
        for (int i = 0; i < contador; i++) {
            if (strcmp(biblioteca[i].titulo, titulo) == 0) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                return;
            }
        }
    }
    printf("Libro no encontrado.\n");
}

void actualizarEstado(Libro biblioteca[], int contador) {
    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpiar el buffer
    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].id == id) {
            printf("Estado actual: %s\n", biblioteca[i].estado);
            int estado;
            do {
                printf("Ingrese el nuevo estado (1. Disponible, 2. Prestado): ");
                estado = scanf("%d", &estado);
                if (estado == 1) {
                    strcpy(biblioteca[i].estado, "Disponible");
                } else if (estado == 2) {
                    strcpy(biblioteca[i].estado, "Prestado");
                } else {
                    printf("Estado invalido. Intente nuevamente.\n");
                    while (getchar() != '\n'); // Limpiar el buffer
                }
            } while (estado != 1 && estado != 2);
            printf("Estado actualizado.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(Libro biblioteca[], int contador) {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpiar el buffer
    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].id == id) {
            for (int j = i; j < contador - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            printf("Libro eliminado.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}