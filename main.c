// -- Inclusión de cabeceras
#include <stdio.h>
#include <stdlib.h>


// -- Estrucuras
// Es una herejía usar el typedef aquí, pero por cuestiones de tiempo y
// maleabilidad será mejor.
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
        int calificación;
        char fecha[30];
}Historico;

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
int main(){
    menu();
    return 0;
}

void menu(){
    int opcion,opcion2;
    do{
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("                          1) Alojamientos\n");
        printf("                          2) Historico\n");
        printf("                          3) Salir\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion);
        system("clear");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("                          1) Alta\n");
        printf("                          2) Baja\n");
        printf("                          3) Modificación\n");
        printf("                          4) Listado\n");
        printf("                          5) Volver al Menú\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion2);
        system("clear");
            switch (opcion){
                case 1:
                        switch(opcion2){
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
                case 3:
                        switch(opcion2){
                            case 1:
                                //AltaHist();
                                break;
                            case 2:
                                //BajaHist();
                                break;
                            case 3:
                                //ModifHist();
                                break;
                            case 4:
                                //ListadoHist();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 4:
                        switch(opcion2){
                            case 1:
                                //AltaClientes();
                                break;
                            case 2:
                                //BajaClientes();
                                break;
                            case 3:
                                //ModifClientes();
                                break;
                            case 4:
                                //ListadoClientes();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 5:
                    break;

            }
    }while (opcion!=5);
}

void AltaAlojs(){
    FILE *pf;
    Alojamiento stay;
    pf = fopen("Alojamientos.dat","ab");
    printf("Ingrese Codigo\n");
    scanf("%i",&stay.codigo);
    printf("Ingrese Detalle\n");
    scanf("%s",stay.detalle);
    printf("Ingrese Precio\n");
    scanf("%f",&stay.precio);
    printf("Ingrese Costo\n");
    scanf("%f",&stay.costo);
    printf("Ingrese Proveedor\n");
    scanf("%s",stay.prov);
    fseek(pf,0L,SEEK_END);
    fwrite(&stay,sizeof(Alojamiento),1,pf);
    fclose(pf);
    system("clear");
    menu();
}

void ListadoAlojs(){
    FILE *pf;
    Alojamiento stay;
    pf = fopen("Alojamientos.dat","rb");
    fread(&stay,sizeof(Alojamiento),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %.2f ; %.2f ; %s\n",stay.codigo,stay.detalle,stay.precio,stay.costo,stay.prov);
        fread(&stay,sizeof(Alojamiento),1,pf);
    }
    fclose(pf);
}

void ModifAlojs(){
    FILE *pf,*pfaux;
    Alojamiento stay;
    int codigoaux;
    pf = fopen("Alojamientos.dat","rb");
    pfaux = fopen("Alojamientosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&stay,sizeof(Alojamiento),1,pf);
        while (!feof(pf)){
                if (stay.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&stay,sizeof(Alojamiento),1,pfaux);
                }else{
                    printf("Ingrese Detalle\n");
                    scanf("%s",stay.detalle);
                    printf("Ingrese Precio\n");
                    scanf("%f",&stay.precio);
                    printf("Ingrese Costo\n");
                    scanf("%f",&stay.costo);
                    printf("Ingrese Proveedor\n");
                    scanf("%s",stay.prov);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&stay,sizeof(Alojamiento),1,pfaux);
                }
            fread(&stay,sizeof(Alojamiento),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Alojamientos.dat");
    rename("Alojamientosaux.dat","Alojamientos.dat");
}

void BajaAlojs(){
    FILE *pf,*pfaux;
    Alojamiento stay;
    int codigoaux;
    pf = fopen("Alojamientos.dat","rb");
    pfaux = fopen("Alojamientosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&stay,sizeof(Alojamiento),1,pf);
        while (!feof(pf)){
                if (stay.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&stay,sizeof(Alojamiento),1,pfaux);
                }
            fread(&stay,sizeof(Alojamiento),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Alojamientos.dat");
    rename("Alojamientosaux.dat","Alojamientos.dat");
}
