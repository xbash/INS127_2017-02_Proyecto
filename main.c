/*
 * Algoritmo de busqueda de vecinos en una matriz en done los extremos de las la matriz se consideran vecinos
 * con sus opuestos
 * El programa soporta hasta una matriz de 1447x1447
 * Las bacterias vivas estan representadas por un 1, las muertas por un 0
 * Debe definir la cantidad de ciclos evolutivos asignando un valor a la constante L
 * El archivo de salida donde es almacenado la matriz final despues de L ciclos evolutivos tiene por nombre salida.bin
 */
#include <stdio.h>
#include "Vecinos.h"
#include "Ciclos.h"
#include <time.h>
#include "ManejoDeArchivos.h"
static const int CrearMatrizDePrueba = 0;
static const int L = 10; //Cantidad de ciclos evolutivos


int main() {
    clock_t tic = clock();
    int N=5; //Valores iniciales usado cuando CrearMatrizDePrueba es usado, en cualquier otro caso no se usa
    int M=7; //Valores iniciales usado cuando CrearMatrizDePrueba es usado, en cualquier otro caso no se usa
    /*
     * Punto 1
     */
    DescriptorBacterias db = InfoArchivo();
    N=db.N; //Comentar en caso de que CrearMatrizDePrueba = 1
    M=db.M; //Comentar en caso de que CrearMatrizDePrueba = 1
    int Matriz[N][M];

    Manejador(N,M,Matriz); //Comentar en caso de que CrearMatrizDePrueba = 1

    if(CrearMatrizDePrueba==1){
        int cont = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if(i%2 == 0){
                    //printf("i: %d\n",i);
                    Matriz[i][j]=1;
                }
                else
                    Matriz[i][j]=0;

                if(j==3)Matriz[i][j]=0;

                cont++;

            }
        }
    }

    /*
     * Punto 2
     */
    printf ("Matriz actual, Elementos vivos: %d\n", BacteriasVivas(N, M, Matriz));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            printf (" %2d ",Matriz[i][j]);
        }
        printf ("\n\n");
    }


    /*
     * Punto 3
     */
    printf ("Comienzo de ejecucion de ciclos de vida. \n\n");
    int ElementosVivos = 0;
    //Ciclos de Vida
    for (int c=1;c<=L;c++){
        CiclodeVida(N,M,Matriz);
        ElementosVivos = BacteriasVivas(N, M, Matriz);
        printf ("Bacterias Vivas: %d en ciclo: %d\n",ElementosVivos,c);
        if (ElementosVivos == 0){
            printf ("La poblacion se ha extinguido en el ciclo:%d\n",c);
            break;
        }


    }
    /*
     * Punto 4
     */
    //Guarda la matriz
    GuardarArchivo(N,M,ElementosVivos,Matriz);
    clock_t toc = clock();

    printf("Tiempo: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}

