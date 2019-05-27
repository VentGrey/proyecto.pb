#include <stdio.h>
#include <stdlib.h>

void menu();

typedef struct{
    int codigo;
    char detalle[30];
    float precio;
    float costo;
    char prov[30];
}Producto;

typedef struct{
    int codigo;
    char nombre[30];
    char telefono[30];
    char email[30];
}Proveedores;

typedef struct{
    char cuit[30];
    char cliente[30];
    char fechaalta[11];
    char email[30];
    char telefono[30];
}Clientes;

typedef struct{
    int codigo;
    char fecha[11];
    char cuit[30];
    float total;
    float descuento;
}Presupuesto;

typedef struct{
    int codigo;
    char producto[30];
    int cantidad;
    float precio;
}DetPresupuesto;

void AltaPresu();
void BajaPresu();
void ModifPresu();
void ListadoPresu();
void AltaProds();
void BajaProds();
void ModifProds();
void ListadoProds();
void AltaProvs();
void BajaProvs();
void ModifProvs();
void ListadoProvs();
void AltaClientes();
void BajaClientes();
void ModifClientes();
void ListadoClientes();

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
        printf("                          2) Productos\n");
        printf("                          3) Proveedores\n");
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
                                AltaProds();
                                break;
                            case 2:
                                BajaProds();
                                break;
                            case 3:
                                ModifProds();
                                break;
                            case 4:
                                ListadoProds();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 3:
                        switch(opcion2){
                            case 1:
                                //AltaProvs();
                                break;
                            case 2:
                                //BajaProvs();
                                break;
                            case 3:
                                //ModifProvs();
                                break;
                            case 4:
                                //ListadoProvs();
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

void AltaPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&presu.codigo);
    printf("Ingrese Fecha\n");
    scanf("%s",presu.fecha);
    printf("Ingrese CUIT\n");
    scanf("%s",presu.cuit);
    printf("Ingrese Total\n");
    scanf("%f",&presu.total);
    printf("Ingrese Descuento\n");
    scanf("%f",&presu.descuento);
    fseek(pf,0L,SEEK_END);
    fwrite(&presu,sizeof(Presupuesto),1,pf);
    fclose(pf);
    system("clear");
    menu();
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

void AltaProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","ab");
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
    fwrite(&prod,sizeof(Producto),1,pf);
    fclose(pf);
    system("clear");
    menu();
}

void ListadoProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","rb");
    fread(&prod,sizeof(Producto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %.2f ; %.2f ; %s\n",prod.codigo,prod.detalle,prod.precio,prod.costo,prod.prov);
        fread(&prod,sizeof(Producto),1,pf);
    }
    fclose(pf);
}

void ModifProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","rb");
    pfaux = fopen("Productosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
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
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
}

void BajaProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","rb");
    pfaux = fopen("Productosaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
}
