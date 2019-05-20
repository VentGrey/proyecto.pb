/* Bibliotecas */

// Standard Input Output //
#include <stdio.h>

// Standard Library //
#include <stdlib.h>

// Dynamic memory management //
#include <malloc.h>

// Booleans library (Requires C99 +) //
#include <stdbool.h>

// String management library //
#include <string.h>

/* Estructuras */

// Estructura del stay
typedef struct stay {
        int id;
        char longitud[20];
        char latitud[20];
        char tipo[50];
        char fecha[50];
} stay;

// Estructura de histoŕico
typedef struct historial {
        int id;
        float precio;
        int calif;
        char fechas_disp[100];
} historial;

// Archivo a guardar
FILE *file = NULL;

/* Prototipos de funciones */

//-- Archivos
void crear_archivo_aloj();
void cerrar_archivo_aloj();

//-- Interfaces
void menu();
void ejecutar(char tecla);


//-- Godínez
void insertar();
void buscar();

/* MAIN */


/* FUNCIONES */
void crear_archivo_aloj() {
        file = fopen("info.hsp", "w+b");
        int tamanio = sizeof(struct stay);

        FILE *main_file = fopen("datos.hsp", "r+b");

        // Revisar si el archivo existe
        if(main_file != NULL) {
                struct stay * entidad = (struct stay *) malloc(tamanio);
        }
}
