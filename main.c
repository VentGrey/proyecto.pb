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

// Estructura del alojamiento
typedef struct alojamiento {
        int id;
        char longitud[20];
        char latitud[20];
        char tipo[50];
        char fecha[50];
} alojamiento;

// Estructura de histoŕico
typedef struct historial {
        int id;
        float precio;
        int calif;
        char fechas_disp[100];
} historial;


/* Prototipos de funciones */

//-- Archivos
void crear_archivo();
void cerrar_archivo();

//-- Interfaces
void menu();
void ejecutar(char tecla);


//-- Godínez
void insertar();
void buscar();

/* MAIN */


/* FUNCIONES */
