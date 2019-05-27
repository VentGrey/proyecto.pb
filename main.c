#include <stdio.h>
#include <stdlib.h>

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

//-- Prototipos de alojamiento
void AltaAlojs();
void BajaAlojs();
void ModifAlojs();
void ListadoAlojs();

//-- Prototipos de histórico
void AltaHist();
void BajaHist();
void ModifHist();
void ListadoHist();


int main(){
    menu();
    return 0;
}

void menu(){
    int opcion,opcion2;
    do{
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("                          1) Presupuestos\n");
        printf("                          2) Alojamientos\n");
        printf("                          3) Historico\n");
        printf("                          4) Clientes\n");
        printf("                          5) Salir\n");
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
                                AltaPresu();
                                break;
                            case 2:
                                BajaPresu();
                                break;
                            case 3:
                                ModifPresu();
                                break;
                            case 4:
                                ListadoPresu();
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


void ListadoPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","rb");
    fread(&presu,sizeof(Presupuesto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %s ; %.2f ; %.2f\n",presu.codigo,presu.fecha,presu.cuit,presu.total,presu.descuento);
        fread(&presu,sizeof(Presupuesto),1,pf);
    }
    fclose(pf);
}

void ModifPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    int codigoaux;
    pf = fopen("Presupuesto.dat","rb");
    pfaux = fopen("Presupuestoaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }else{
                    printf("Ingrese Fecha\n");
                    scanf("%s",presu.fecha);
                    printf("Ingrese CUIT\n");
                    scanf("%s",presu.cuit);
                    printf("Ingrese Total\n");
                    scanf("%f",&presu.total);
                    printf("Ingrese Descuento\n");
                    scanf("%f",&presu.descuento);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
}

void BajaPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    int codigoaux;
    pf = fopen("Presupuesto.dat","rb");
    pfaux = fopen("Presupuestoaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
}

void AltaAlojs(){
    FILE *pf;
    Alojamiento prod;
    pf = fopen("Alojamientos.dat","ab");
    printf("Ingrese Codigo\n");
    scanf("%i",&prod.codigo);
    printf("Ingrese Detalle\n");
    scanf("%s",prod.detalle);
    printf("Ingrese Precio\n");
    scanf("%f",&prod.precio);
    printf("Ingrese Costo\n");
    scanf("%f",&prod.costo);
    printf("Ingrese Proveedor\n");
    scanf("%s",prod.prov);
    fseek(pf,0L,SEEK_END);
    fwrite(&prod,sizeof(Alojamiento),1,pf);
    fclose(pf);
    system("clear");
    menu();
}

void ListadoAlojs(){
    FILE *pf;
    Alojamiento prod;
    pf = fopen("Alojamientos.dat","rb");
    fread(&prod,sizeof(Alojamiento),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %.2f ; %.2f ; %s\n",prod.codigo,prod.detalle,prod.precio,prod.costo,prod.prov);
        fread(&prod,sizeof(Alojamiento),1,pf);
    }
    fclose(pf);
}

void ModifAlojs(){
    FILE *pf,*pfaux;
    Alojamiento prod;
    int codigoaux;
    pf = fopen("Alojamientos.dat","rb");
    pfaux = fopen("Alojamientosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Alojamiento),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Alojamiento),1,pfaux);
                }else{
                    printf("Ingrese Detalle\n");
                    scanf("%s",prod.detalle);
                    printf("Ingrese Precio\n");
                    scanf("%f",&prod.precio);
                    printf("Ingrese Costo\n");
                    scanf("%f",&prod.costo);
                    printf("Ingrese Proveedor\n");
                    scanf("%s",prod.prov);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Alojamiento),1,pfaux);
                }
            fread(&prod,sizeof(Alojamiento),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Alojamientos.dat");
    rename("Alojamientosaux.dat","Alojamientos.dat");
}

void BajaAlojs(){
    FILE *pf,*pfaux;
    Alojamiento prod;
    int codigoaux;
    pf = fopen("Alojamientos.dat","rb");
    pfaux = fopen("Alojamientosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Alojamiento),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Alojamiento),1,pfaux);
                }
            fread(&prod,sizeof(Alojamiento),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Alojamientos.dat");
    rename("Alojamientosaux.dat","Alojamientos.dat");
}
