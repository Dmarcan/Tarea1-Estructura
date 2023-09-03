#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "funciones_answers.h"
#include "list.h"

struct EntradaLibro{
  char titulo[51]; 
  char autor[50];
  char genero[50];
  char isbn[50];
  char ubicacion[50];
  char estado[11];
  struct EntradaLibro* reservaciones;
  struct EntradaLibro *siguiente;
};

 struct Reserva{
  char nombreEstudiante[50];
  struct Reserva *siguiente;
};

void mostrarOpciones(){           

    printf("\n--- MENÚ ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar datos de libro\n");
    printf("3. Mostrar todos los libros\n");
    printf("4. Reservar libro\n");
    printf("5. Cancelar reserva de libro\n");
    printf("6. Retirar libro\n");
    printf("7. Devolver libro\n");
    printf("8. Mostrar libros prestados\n");
    printf("9. Importar libros desde archivo CSV\n");
    printf("10. Exportar libros a archivo CSV\n");
    printf("0. Salir\n");
    printf("Elija una opción: ");
}

void mostrarMenu(List* biblioteca){
    int bookCount = 0;  
    int opciones;
    do {
        mostrarOpciones();
        scanf("%d", &opciones);
        getchar(); 
        
        switch (opciones) {
            case 1:
                // Funcion para registrar libro
                registrarLibro(biblioteca, &bookCount);
                break;
            case 2:
                // Llamar a la función para mostrar un libro
                mostrarDatosLibro(biblioteca);
                break;
            case 3:
                // Llamar a la función mostrar todos los libros 
                mostrarLibros(biblioteca);
                break;
            case 4:
                // LLamar a la función para reservar un libro
                reservarLibro(biblioteca);
                break;
            case 5:
                // Llamar a la función para cancelar una reserva de un libro
                cancelarReserva(biblioteca);
                break;
            case 6:
                // Llamar a la funcion para retirar un libro
                retirarLibro(biblioteca);
                break;
            case 7:
                // Llamar a la función para devolver libro
                devolverLibro(biblioteca);
                break;
            case 8:
                // Llamar a la función para mostrar libros prestados
                mostrarLibrosPrestados(biblioteca);
                break;
            case 9:
                // Llamar a la función para importar libros desde archivo CSV
                importarLibros(biblioteca);
                break;
            case 10:
                // Llamar a la función para exportar libros a archivo CSV
                exportarLibros(biblioteca);
                break;
            case 0:
                printf("Saliendo de la aplicación\n");
                break;
            default:
                printf("\nOpción no válida. Elija nuevamente.\n");
        }
    } while (opciones != 0);
}

void registrarLibro(struct List* biblioteca, int* bookCount) {
    char nuevoTitulo[51];
    
    printf("Ingrese titulo: ");
    scanf("%50[^\n]%*c", nuevoTitulo);

    struct EntradaLibro* current = firstList(biblioteca);
    
    while (current != NULL) {
        if (strcmp(nuevoTitulo, current->titulo) == 0) {
            printf("Error: El título ya existe en la biblioteca. No se puede registrar duplicados.\n");
            return;
        }
        current = nextList(biblioteca);
    }

    struct EntradaLibro* libro = malloc(sizeof(struct EntradaLibro));
    if (libro == NULL) {
        printf("Error: No se pudo asignar memoria para el libro.\n");
        return;
    }
    
    strcpy(libro->titulo, nuevoTitulo);

    printf("Ingrese autor: ");
    scanf("%49[^\n]%*c", libro->autor);
      
    printf("Ingrese genero: ");
    scanf("%49[^\n]%*c", libro->genero);
      
    printf("Ingrese isbn: ");
    scanf("%49[^\n]%*c", libro->isbn);
  
    printf("Ingrese ubicación: ");
    scanf("%49s", libro->ubicacion);

    strcpy(libro->estado, "Disponible");
    libro->reservaciones = NULL;
    libro->siguiente = NULL;

    pushFront(biblioteca, libro);
    (*bookCount)++;
}

void mostrarDatosLibro(struct List* biblioteca){
    char titulo[51];
    char autor[51];

  printf("Ingrese el título del libro: ");
  scanf("%49[^\n]s",titulo);
    getchar();
    
  printf("Ingrese el autor del libro: ");
  scanf("%49[^\n]s",autor);
    getchar();

  struct EntradaLibro* aux = firstList(biblioteca);
  while(aux != NULL){

    if(strcmp(titulo, aux->titulo) == 0 && strcmp(autor, aux->autor) == 0){
      printf("\nDatos del libro\n");
        printf("Título: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Estado: %s\n", aux->estado);
      return;
    }
    
    aux = nextList(biblioteca);
  }
  printf("Libro no econtrado :(\n");
}

void mostrarLibros(struct List* biblioteca){
    
    struct EntradaLibro* current = firstList(biblioteca);
    
    if (current == NULL){
        printf("\nLa biblioteca está vacía.\n");
        return;
    }
    int count = 1;
    printf("\n--- Libros en la Biblioteca ---\n");
    while(current != NULL){
        printf("\nLibro %d:\n", count);
        printf("Título: %s\n", current->titulo);
        printf("Autor: %s\n", current->autor);
        printf("Género: %s\n", current->genero);
        printf("ISBN: %s\n", current->isbn);
        printf("Ubicación: %s\n", current->ubicacion);
        printf("Estado: %s\n", current->estado);
        current = nextList(biblioteca);
        count++;
    }
}

void reservarLibro(struct List* biblioteca){
    char auxTitulo[51];
    char auxAutor[51];
    
    printf("Ingrese el título del libro: ");
    scanf("%49[^\n]s", auxTitulo);
    getchar();

    printf("Ingrese el autor del libro: ");
    scanf("%49[^\n]s", auxAutor);
    getchar();

    struct EntradaLibro* current = firstList(biblioteca);

    while (current != NULL) {
        if (strcmp(auxTitulo, current->titulo) == 0 && strcmp(auxAutor, current->autor) == 0) {
            char nombreEstudiante[51];
            printf("Ingrese nombre del estudiante: ");
            scanf("%s", nombreEstudiante);
            
            struct Reserva* nuevaReserva = malloc(sizeof(struct Reserva));
            if (nuevaReserva == NULL) {
                printf("Error: No se pudo asignar memoria para la reserva.\n");
                return;
            }
            strcpy(nuevaReserva->nombreEstudiante, nombreEstudiante);
            nuevaReserva->siguiente = NULL;
            
            if (current->reservaciones == NULL) {
                current->reservaciones = nuevaReserva;
            } else {
                struct Reserva* reservaActual = current->reservaciones;
                while (reservaActual->siguiente != NULL) {
                    reservaActual = reservaActual->siguiente;
                }
                reservaActual->siguiente = nuevaReserva;
            }
            
            strcpy(current->estado, "Reservado");
            return;
        }
        current = nextList(biblioteca);
    }

    printf("El libro no está registrado.\n");
}
    
void cancelarReserva(struct List* biblioteca) {
    char auxTitulo[51];
    char auxAutor[51];

    printf("Ingrese el título del libro: ");
    scanf("%49[^\n]s", auxTitulo);
    getchar();

    printf("Ingrese el autor del libro: ");
    scanf("%49[^\n]s", auxAutor);
    getchar();

    struct EntradaLibro* current = firstList(biblioteca);

    while (current != NULL) {
        if (strcmp(auxTitulo, current->titulo) == 0 && strcmp(auxAutor, current->autor) == 0) {
            if (strcmp(current->estado, "Reservado") == 0) {
                char nombreEstudiante[51];
                printf("Ingrese nombre del estudiante que desea cancelar la reserva: ");
                scanf("%s", nombreEstudiante);

                struct Reserva* reservaActual = current->reservaciones;
                struct Reserva* reservaAnterior = NULL;

                while (reservaActual != NULL) {
                    if (strcmp(reservaActual->nombreEstudiante, nombreEstudiante) == 0) {
                        if (reservaAnterior == NULL) {
                            current->reservaciones = reservaActual->siguiente;
                        } else {
                            reservaAnterior->siguiente = reservaActual->siguiente;
                        }
                        free(reservaActual);

                        if (current->reservaciones == NULL) {
                            strcpy(current->estado, "Disponible");
                        }

                        printf("Reserva cancelada con éxito.\n");
                        return;
                    }
                    reservaAnterior = reservaActual;
                    reservaActual = reservaActual->siguiente;
                }

                printf("El estudiante no tiene una reserva para este libro.\n");
                return;
            } else {
                printf("El libro no está reservado.\n");
                return;
            }
        }
        current = nextList(biblioteca);
    }
    printf("El libro no está registrado.\n");
}

void retirarLibro(struct List* biblioteca) {
    char auxTitulo[51];
    char auxAutor[51];

    printf("Ingrese el título del libro: ");
    scanf("%49[^\n]s", auxTitulo);
    getchar();

    printf("Ingrese el autor del libro: ");
    scanf("%49[^\n]s", auxAutor);
    getchar();

    struct EntradaLibro* current = firstList(biblioteca);

    while (current != NULL) {
        if (strcmp(auxTitulo, current->titulo) == 0 && strcmp(auxAutor, current->autor) == 0) {
            if (strcmp(current->estado, "Disponible") == 0) {
                strcpy(current->estado, "Prestado");
                printf("Libro prestado con éxito.\n");
                return;
            } else if (strcmp(current->estado, "Reservado") == 0) {

                if (current->reservaciones != NULL) {
                    struct Reserva* primeraReserva = current->reservaciones;
                    strcpy(current->estado, "Prestado");
                    printf("Libro prestado a %s con éxito.\n", primeraReserva->nombreEstudiante);

                    current->reservaciones = primeraReserva->siguiente;
                    free(primeraReserva);
                } else {
                    printf("No hay estudiantes en la cola de reservas para este libro.\n");
                }
                return;
            } else {
                printf("El libro ya está prestado.\n");
                return;
            }
        }
        current = nextList(biblioteca);
    }
    printf("El libro no está registrado.\n");
}

void devolverLibro(struct List* biblioteca){
    char auxTitulo[51];
    char auxAutor[51];

    printf("Ingrese el título del libro: ");
    scanf("%49[^\n]s", auxTitulo);
    getchar();

    printf("Ingrese el autor del libro: ");
    scanf("%49[^\n]s", auxAutor);
    getchar();

    struct EntradaLibro* current = firstList(biblioteca);

    while(current != NULL){
        if ((strcmp(auxTitulo, current->titulo) == 0 && strcmp(auxAutor, current->autor) == 0)){
            if(strcmp(current->estado, "Prestado") == 0){
                if (current->reservaciones != NULL){
                    strcpy(current->estado, "Reservado");
                    printf("Libro devuelto y marcado como 'Reservado'\n");
                }
                else{
                    strcpy(current->estado, "Disponible");
                    printf("Libro devuelto y marcado como 'Disponible'\n");
                }
            return;
            }
            else{
                printf("El libro no ha sido prestado\n");
                return;
            }
        }
        current = nextList(biblioteca);
    }
    printf("El libro no ha sido registrado\n");
}

void mostrarLibrosPrestados(struct List* biblioteca){
    
    struct EntradaLibro* current = firstList(biblioteca);
    
    if (current == NULL){
        printf("\nNo hay libros prestados para mostrar.\n");
        return;
    }
    
    printf("\n--- Libros Prestados ---\n\n");
        while(current != NULL){
            if (strcmp(current->estado, "Prestado") == 0){
                printf("Título: %s\n", current->titulo);
                printf("Autor: %s\n\n", current->autor);
            }
            current = nextList(biblioteca);
    }

}

void importarLibros(struct List* biblioteca) {
    char nombreArchivo[201];  
    printf("Ingrese el nombre del archivo CSV para importar libros: ");
    scanf("%200s", nombreArchivo);  

    FILE* archivo = fopen(nombreArchivo, "r");  // Se abre el archivo en modo lectura

    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo.\n");
        return;
    }

    char* linea = NULL;
    size_t longitud = 0;
    ssize_t encabezado;

    // lee y descarta la primera línea del archivo CSV
    encabezado = getline(&linea, &longitud, archivo);

    while ((encabezado = getline(&linea, &longitud, archivo)) != -1) {
        char titulo[50], autor[50], genero[50], isbn[50], ubicacion[50], estado[11];
        sscanf(linea, "%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%10[^,],%*[^\n]\n",
            titulo, autor, genero, isbn, ubicacion, estado);

        // Crea una nueva entrada de libro y configura sus valores
        struct EntradaLibro* libro = malloc(sizeof(struct EntradaLibro));
        if (libro == NULL) {
            printf("Error: No se pudo asignar memoria para el libro.\n");
            free(linea);  
            fclose(archivo);
            return;
        }
        strcpy(libro->titulo, titulo);
        strcpy(libro->autor, autor);
        strcpy(libro->genero, genero);
        strcpy(libro->isbn, isbn);
        strcpy(libro->ubicacion, ubicacion);
        strcpy(libro->estado, estado);
        
        libro->reservaciones = NULL;  // Inicializa la cola de reservas

        pushFront(biblioteca, libro);
    }

    free(linea);  
    fclose(archivo);  
    printf("Libros importados exitosamente desde el archivo CSV.\n");
}

void exportarLibros(struct List* biblioteca) {
    char nombreArchivo[201];  

    printf("Ingrese el nombre del archivo CSV para exportar libros: ");
    scanf("%200s", nombreArchivo);  

    FILE* archivo = fopen(nombreArchivo, "w");  // Se abre el archivo en modo escritura

    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo para escribir.\n");
        return;
    }

    // Escribe el encabezado en el archivo CSV
    fprintf(archivo, "titulo,autor,genero,isbn,ubicacion,estado\n");

    // Exporta la cola de reservas del libro, si existe
    struct EntradaLibro* current = firstList(biblioteca);
    while (current != NULL) {
        fprintf(archivo, "%s,%s,%s,%s,%s,%s\n", current->titulo, current->autor,
                current->genero, current->isbn, current->ubicacion, current->estado);

        struct Reserva* reserva = current->reservaciones;
        
        while (reserva != NULL) {
            fprintf(archivo, ",,,,%s,Reservado,%s\n", current->ubicacion, reserva->nombreEstudiante);
            reserva = reserva->siguiente;
        }

        current = nextList(biblioteca);
    }

    fclose(archivo);  
    printf("Libros exportados exitosamente al archivo CSV.\n");
}