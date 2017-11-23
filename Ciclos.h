//
// Created by Rodrigo Gonzalez on 16-11-17.
//


#ifndef PROYECTOFINAL_CICLOS_H
#define PROYECTOFINAL_CICLOS_H

#endif //PROYECTOFINAL_CICLOS_H

#include "Pila.h"
int CalcularVecinosVivos(Coor target,int N, int M,int Matriz[N][M]);
void CiclodeVida(int N, int M,int Matriz[N][M]);
int BacteriasVivas(int N, int M, int Matriz[N][M]);
int BacteriasVivas(int N, int M, int Matriz[N][M]);


int CalcularVecinosVivos(Coor target,int N, int M,int Matriz[N][M]){
    Coor VN,VNO,VNE,VE,VO,VSO,VS,VSE;
    int VecinosVivos=0;
    VN = VecinoNorte(target,N);
    VNO = VecinoNO(target,N,M);
    VNE = VecinoNE(target,N,M);
    VE = VecinoEste(target,M);
    VO = VecinoOEste(target,M);
    VSO = VecinoSO(target,N,M);
    VS = VecinoSUR(target,N);
    VSE = VecinoSE(target,N,M);

    //Vecinos vivos un 1

    if(Matriz[VN.x][VN.y] == 1){
        VecinosVivos++;
    }

    if(Matriz[VNO.x][VNO.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VNE.x][VNE.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VE.x][VE.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VO.x][VO.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VSO.x][VSO.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VS.x][VS.y] == 1){
        VecinosVivos++;
    }
    if(Matriz[VSE.x][VSE.y] == 1){
        VecinosVivos++;
    }

    return VecinosVivos;

}

void CiclodeVida(int N, int M,int Matriz[N][M]){
    Coor Miembro;
    int accion=0;
    Pila* Instrucciones = crearPila();
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            Coor target;
            target.x=i;
            target.y=j;

            Miembro.x=i;
            Miembro.y=j;

            if ((Matriz[i][j]==0) && ((CalcularVecinosVivos(target,N,M,Matriz)) == 3)){
                //Bacteria revive
                Push(Instrucciones,Miembro,1);
            }

            else if ((Matriz[i][j]==1) && (((CalcularVecinosVivos(target,N,M,Matriz)) == 2) || ((CalcularVecinosVivos(target,N,M,Matriz)) == 3))){
                //Bacteria sigue viviendo
                accion=1;

            }
            else if (Matriz[i][j]==1){
                //Bacteria  en cualquier otro caso muere
                Push(Instrucciones,Miembro,0);
            }

        }
    }

    //Ejecutar acciones de la Pila
    while (Instrucciones->ultimo != NULL){
        Matriz[Instrucciones->ultimo->Coodenadas.x][Instrucciones->ultimo->Coodenadas.y]=Instrucciones->ultimo->accion;
        Pop(Instrucciones);
    }
}

//Se encarga de retornar las bacterias vivas actuales en la matriz

int BacteriasVivas(int N, int M, int Matriz[N][M]){
    int contador=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if(Matriz[i][j] == 1){
                contador++;
            }
        }
    }
    return contador;
}