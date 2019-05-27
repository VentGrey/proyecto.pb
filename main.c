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
void mostrar();

/* MAIN */
int main(int argc, char *argv[])
{

        return 0;
}

/* FUNCIONES */
void crear_archivo_aloj()
{
        file = fopen("info.hsp", "w+b");
        int tamanio = sizeof(struct stay);

        FILE *main_file = fopen("datos.hsp", "r+b");

        // Revisar si el archivo existe
        if (main_file != NULL) {
                struct stay * entidad = (struct stay *) malloc(tamanio);
                fseek(main_file, 0 , SEEK_SET);

                do {
                        fread(entidad, tamanio, 1, main_file);
                        fwrite(entidad, tamanio, 1, file);
                } while (!feof(main_file));

                fclose(main_file);
        }
}

void cerrar_archivo_aloj() {
        FILE *main_file = fopen("datos.hsp", "w+b");
        struct stay * entidad = (struct stay *) malloc(sizeof(struct stay));

        fseek(file, 0, SEEK_SET);

        do {
                fread(entidad, sizeof(struct stay), 1, file);
                fwrite(entidad, sizeof(struct stay), 1, main_file);
        } while (!feof(file));

        fclose(main_file);
        fclose(file);
}

void menu() {
        char op;
        while (op != 'S' && op != 's') {
                printf("---- ALOJAMIENTOS -----\n");
                printf("1 - Ingresar un alojamiento\n");
                printf("2 - Mostrar un alojamiento\n");
                printf("3 - Eliminar un alojamiento\n");
                printf("4 - Mostrar todos los alojamientos registrados\n");
                printf("---- HISTORIAL -------\n");
                printf("5 - Ingresar un elemento en el historial\n");
                printf("6 - Mostrar un elemento del historial\n");
                printf("7 - Eliminar un elemento del historial");
                printf("8 - Mostrar todos los elementos del historial");
                scanf("%c", op);

                if (op != 'S' && op != 's') {
                        ejecutar(op);
                }
        }
}
