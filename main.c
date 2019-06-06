// -- Inclusión de cabeceras
#include <stdio.h>
#include <stdlib.h>


// -- Estrucuras
// Es una herejía usar el typedef aquí, pero por cuestiones de tiempo y
// maleabilidad será mejor, como pro-tip, las estructuras se deben
// accesar con flechas, no typedefs.
typedef struct{
        int id;
        char latitud[20];
        char longitud[20];
        char tipo[20];
        char fecha[30];
}Alojamiento;

typedef struct{
        int id;
        double precio;
        int calificacion;
        char fecha[30];
}Historico;

// -- Prototipo de menú
void menu();

// -- Prototipos de alojamiento
void AltaAlojs();
void BajaAlojs();
void ModifAlojs();
void ListadoAlojs();

// -- Prototipos de histórico
void AltaHist();
void BajaHist();
void ModifHist();
void ListadoHist();

// -- Función main
int main()
{
        menu();
        return 0;
}


/*
 * La función menú es muy simple, tenemos dos enteros
 * que actuarán como disparadores de dos switch case más abajo.
 * Primero se le preguntará al usuario con qué objetos desea interactuar
 * eso lo manejará el case 1 y con el case 2 se enviará a las opciones
 * correspondientes dependiendo de la elección del usuario.
 * */
void menu()
{
        int opcion,opcion2;
        do {
                printf("---------------HOSPEDATE--------------\n");
                printf("--------------------------------------\n");
                printf("           1) Alojamientos            \n");
                printf("           2) Histórico               \n");
                printf("           3) Salir                   \n");
                printf("--------------------------------------\n");
                printf("--------------------------------------\n");
                scanf("%d",&opcion);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("---------------HOSPEDATE--------------\n");
                printf("--------------------------------------\n");
                printf("           1) Alta                    \n");
                printf("           2) Baja                    \n");
                printf("           3) Modificación            \n");
                printf("           4) Listado                 \n");
                printf("           5) Volver al Menú          \n");
                printf("--------------------------------------\n");
                printf(" -------------------------------------\n");
                scanf("%d",&opcion2);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");

                switch (opcion) {
                case 1:
                        switch(opcion2) {
                        case 1:
                                AltaAlojs();
                                break;
                        case 2:
                                BajaAlojs();
                                break;
                        case 3:
                                ModifAlojs();
                                break;
                        case 4:
                                ListadoAlojs();
                                break;
                        case 5:
                                menu();
                                break;
                        }
                        break;
                case 2:
                        switch(opcion2){
                        case 1:
                                AltaHist();
                                break;
                        case 2:
                                BajaHist();
                                break;
                        case 3:
                                ModifHist();
                                break;
                        case 4:
                                ListadoHist();
                                break;
                        case 5:
                                menu();
                                break;
                        }
                        break;
                case 3:
                        break;
                }
        }while (opcion!=5);
}

// ------------ INICIO DE CRUD ALOJAMIENTOS --------------------------


/*
 * La función de alta de alojamientos crea un archivo de alojamientos
 * de tipo binario y almacena la información ingresada por el usuario.
 *
 * Mediante el uso de fseek (que mide los archivos por carácteres) revisamos
 * el final del archivo, luego escribimos los datos utilizando fwrite y
 * finalmente cerramos los archivos para que no se muera la memoria.
 *
 * Llamamos a menu para que el programa le de la opción de hacer más cositas
 * al usuario
  */
void AltaAlojs()
{
        FILE *pf;
        Alojamiento stay;
        pf = fopen("Alojamientos.dat","ab");

        printf("Ingrese el id del alojamiento\n");
        scanf("%i" ,&stay.id);

        printf("Ingrese la latitud del lugar\n");
        scanf("%s", &stay.latitud);

        printf("Ingrese la longitud\n");
        scanf("%s", &stay.longitud);

        printf("Ingrese el tipo de alojamiento\
 (Casa, Departamento, Cuarto, etc)\n");
        scanf("%s", &stay.tipo);

        printf("Ingrese la fecha en la que el alojamiento será realizado\n");
        scanf("%s", &stay.fecha);

        fseek(pf, 0L, SEEK_END);
        fwrite(&stay, sizeof(Alojamiento), 1, pf);
        fclose(pf);
        // -- Imprimir vergos de newlines para "simular" un clearscreen;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        menu();
}

/*
 * La función de listado abre el archivo de alojamientos y mientras que no
 * lleguemos al final del archivo (feof) el ciclo while comenzará a imprimir
 * todos los registros existentes en el archivo .dat*/
void ListadoAlojs()
{
        FILE *pf;
        Alojamiento stay;
        pf = fopen("Alojamientos.dat","rb");
        fread(&stay, sizeof(Alojamiento), 1, pf);
        while (!feof(pf)) {
                printf("%i ; %s ; %s ; %s ; %s\n",stay.id,stay.latitud,
                       stay.longitud,stay.tipo,stay.fecha);
                fread(&stay, sizeof(Alojamiento), 1, pf);
        }
        fclose(pf);
}

/*
 * Para la modificación de los archivos necesitaremos el "doble" de variables
 * en este caso un puntero auxiliar y un archiv auxiliar. El proceso es similar
 * al de altas, pues solo tendremos que pedirle al usuario que ingrese en
 * formato INT el ID de algún alojamiento registrado, y si dicho ID hace
 * match con cualquier ID existente en el archivo se volverán a pedir los
 * datos correspondientes.
 *
 * Finalmente los nuevos datos se escriben en el archivo auxiliar, luego
 * borramos el archivo anterior y renombramos el archivo auxiliar.
  */
void ModifAlojs()
{
        FILE *pf,*pfaux;
        Alojamiento stay;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese Código\n");
        scanf("%i",&codigoaux);
        fread(&stay, sizeof(Alojamiento), 1, pf);

        while (!feof(pf)) {
                if (stay.id != codigoaux) {
                        fseek(pfaux,0l,SEEK_END);
                        fwrite(&stay,sizeof(Alojamiento),1,pfaux);
                } else {
                        printf("Ingrese la latitud\n");
                        scanf("%s",stay.latitud);
                        printf("Ingrese la longitud\n");
                        scanf("%s",&stay.longitud);
                        printf("Ingrese el tipo\n");
                        scanf("%s",&stay.tipo);
                        printf("Ingrese la fecha\n");
                        scanf("%s",stay.fecha);
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&stay, sizeof(Alojamiento), 1, pfaux);
                }
                fread(&stay,sizeof(Alojamiento),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Alojamientos.dat");
        rename("Alojamientosaux.dat","Alojamientos.dat");
}

/*
 * La baja de alojamientos requiere de lo mismo que la
 * modificación, pues vamos a reemplazar archivos de nuevo.
 *
 * Volvemos a pedir el ID de algún alojamiento y si el ID
 * ingresado coincide con cualquiera de los ID's registrados
 * se eliminará la entrada del ID hasta encontrar el final de
 * la misma.
 *
 * Una vez eliminada la entrada cerramos nuestros punteros archivo
 * y eliminamos el archivo anterior para renombrar el archivo auxiliar como
 * original
  */
void BajaAlojs()
{
        FILE *pf,*pfaux;
        Alojamiento stay;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese el ID a buscar\n");
        scanf("%i",&codigoaux);

        fread(&stay, sizeof(Alojamiento), 1, pf);
        while (!feof(pf)) {
                if (stay.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&stay, sizeof(Alojamiento), 1, pfaux);
                }
                fread(&stay,sizeof(Alojamiento),1,pf);
        }

        fclose(pf);
        fclose(pfaux);
        remove("Alojamientos.dat");
        rename("Alojamientosaux.dat","Alojamientos.dat");
}

// ------------ FIN DE CRUD ALOJAMIENTOS --------------------------


// ------------ INICIO DE CRUD HISTÓRICO --------------------------

/*
 * No tiene sentido explicar estas funciones puesto que son un
 * vil copy-pasta de las funciones en el CRUD de alojamientos
 * solo reacomodadas con las variables del histórico, la estructura
 * histórico al poseer un ID hace que las funciones de búsqueda
 * no tengan que modificarse del todo. */

void AltaHist()
{
        FILE *pf;
        Historico hist;

        pf = fopen("historico.dat","ab");

        printf("Ingrese el id del historico\n");
        scanf("%i" ,&hist.id);

        printf("Ingrese el precio de la estancia\n");
        scanf("%lf", &hist.precio);

        printf("Ingrese la calificación del lugar (1 - 5)\n");
        scanf("%i", &hist.calificacion);

        // Revisar que el usuario no se salga de la calificación
        if (hist.calificacion > 5 || hist.calificacion <= 0) {
                printf("La calificación ingresada es errónea");
                return;
        }

        printf("Ingrese la fecha en la que el alojamiento fue realizado\n");
        scanf("%s", &hist.fecha);

        fseek(pf, 0L, SEEK_END);
        fwrite(&hist, sizeof(Historico), 1, pf);
        fclose(pf);
        // -- Imprimir vergos de newlines para "simular" un clearscreen;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        menu();
}

void ListadoHist()
{
        FILE *pf;
        Historico hist;

        pf = fopen("Alojamientos.dat","rb");
        fread(&hist, sizeof(Historico), 1, pf);

        while (!feof(pf)) {
                printf("%i ; %lf ; %i ; %s ;\n",hist.id, hist.precio,
                       hist.calificacion,  hist.fecha);
                fread(&hist,sizeof(Historico), 1, pf);
        }
        fclose(pf);
}

void ModifHist()
{
        FILE *pf,*pfaux;
        Historico hist;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese Código\n");
        scanf("%i",&codigoaux);
        fread(&hist, sizeof(Historico), 1, pf);

        while (!feof(pf)) {
                if (hist.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&hist, sizeof(Historico), 1, pfaux);
                } else {
                        printf("Ingrese el precio\n");
                        scanf("%lf",&hist.precio);
                        printf("Ingrese la calificacion del alojamiento\n");
                        scanf("%i",&hist.calificacion);
                        printf("Ingrese la fecha\n");
                        scanf("%s",&hist.fecha);
                        fseek(pfaux,0l,SEEK_END);
                        fwrite(&hist,sizeof(Historico),1,pfaux);
                }
                fread(&hist,sizeof(Historico),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Historicos.dat");
        rename("Historicosaux.dat","Historicos.dat");
}

void BajaHist()
{
        FILE *pf,*pfaux;
        Historico hist;
        int codigoaux;

        pf = fopen("Historicos.dat","rb");
        pfaux = fopen("Historicosaux.dat","ab");

        printf("Ingrese el ID a buscar\n");
        scanf("%i",&codigoaux);

        fread(&hist, sizeof(Historico), 1, pf);
        while (!feof(pf)) {
                if (hist.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&hist, sizeof(Historico), 1, pfaux);
                }
                fread(&hist,sizeof(Historico),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Historicos.dat");
        rename("Historicosaux.dat","HIstoricos.dat");
}

// ------------ FIN DE CRUD HISTÓRICO --------------------------
