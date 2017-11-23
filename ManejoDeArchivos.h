//
// Created by Rodrigo Gonzalez on 18-11-17.
// CC tlaraunab
//

#ifndef PROYECTOFINAL_MANEJODEARCHIVOS_H
#define PROYECTOFINAL_MANEJODEARCHIVOS_H

#endif //PROYECTOFINAL_MANEJODEARCHIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t magikNumber[3];
    uint32_t N;
    uint32_t M;
    uint32_t cantidad;
} DescriptorBacterias;

typedef struct{
    uint32_t x;
    uint32_t y;
}Coordenadas;

int GuardarArchivo(int N,int M,int K, int Matriz[N][M]);
void Manejador(int N,int M, int MatrizNueva[N][M]);
DescriptorBacterias InfoArchivo();
int GuardarArchivo(int N,int M,int K, int Matriz[N][M]);

void Manejador(int N,int M, int MatrizNueva[N][M]) {
    Pila* Instrucciones = crearPila();
    Coor Miembro;
    FILE *fr, *fw;
    DescriptorBacterias db;
    Coordenadas cor;

    fr = fopen("bacterias.bin", "rb");

    fread(&db, sizeof(DescriptorBacterias), 1, fr);

    for (int i=0;i<db.cantidad;i++){
        fread(&cor, sizeof(Coordenadas), 1, fr);
        Miembro.x=cor.x;
        Miembro.y=cor.y;
        Push(Instrucciones,Miembro,1);
    }
    fclose(fr);

    int n=db.N;
    int m=db.M;

    //Inicializa Matriz Vacia para albergar los elementos que se leeran de las instrucciones de creacion
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            MatrizNueva[i][j]=0;
        }
    }

    while (Instrucciones->ultimo != NULL) {
        MatrizNueva[Instrucciones->ultimo->Coodenadas.x][Instrucciones->ultimo->Coodenadas.y] = Instrucciones->ultimo->accion;
        Pop(Instrucciones);
    }


}


DescriptorBacterias InfoArchivo() {

    FILE *fr;
    DescriptorBacterias db;
    Coordenadas cor;

    fr = fopen("bacterias.bin", "rb");
    fread(&db, sizeof(DescriptorBacterias), 1, fr);

    if(db.magikNumber[0]==237){
        if(db.magikNumber[1]==210){
            if(db.magikNumber[2]==1){
                if(db.magikNumber[3]==114){
                    printf ("Validacion exitosa del numero magico\n");
                }else{
                    printf ("Error validando numero magico.\n");
                    exit(0);
                }
            } else{
                printf ("Error validando numero magico.\n");
                exit(0);
            }
        }else{
            printf ("Error validando numero magico.\n");
            exit(0);
        }

    }else{
        printf ("Error validando numero magico.\n");
        exit(0);
    }
    return db;
}

int GuardarArchivo(int N,int M,int K, int Matriz[N][M]){
    FILE *fw;
    int contador=0,header;

    // Se abre un nuevo archivo para escritura
    fw = fopen("salida.bin","wb");
    header= 0x7201D2ED;
    fwrite(&header, sizeof(int), 1, fw);
    fwrite(&N, sizeof(int), 1, fw);
    fwrite(&M, sizeof(int), 1, fw);
    fwrite(&K, sizeof(int), 1, fw);

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (Matriz[i][j]==1){
                fwrite(&i, sizeof(int), 1, fw);
                fwrite(&j, sizeof(int), 1, fw);
                contador++;
            }

        }
    }
    if (contador==K){
        printf ("La matriz se ha guardado en el archivo salida.bin correctamente.\n");
    }else{
        printf ("La matriz no se ha guardado en el archivo correctamente.\n");
    }
    fclose(fw);
}