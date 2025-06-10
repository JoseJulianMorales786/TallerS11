#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_LIBROS 10
#define MAX_TITULO 100
#define MAX_AUTOR 50

typedef struct {
    int id;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
    char estado[15];
} Libro;

void registrarLibro(Libro biblioteca[], int contador);
void mostrarLibros(Libro biblioteca[], int contador);
void buscarLibro(Libro biblioteca[], int contador);
void actualizarEstado(Libro biblioteca[], int contador);
void eliminarLibro(Libro biblioteca[], int contador);

#endif