//
// Created by Rodrigo Gonzalez on 21-10-17.
//

#ifndef PILAS_PILA_H
#define PILAS_PILA_H

#endif //PILAS_PILA_H
#include <stdlib.h>

typedef struct Nodo{
    Coor Coodenadas;
    int accion; //1 vive, 0 muere
    struct Nodo* next;
} Nodo;

typedef struct Pila{
    Nodo* ultimo;
    int size;
}Pila;

Pila* crearPila();
void Push(Pila* Pila, Coor coordenada, int accion);
void Pop(Pila* Pila);


Pila* crearPila(){
    Pila* pivote;
    pivote = (Pila*) malloc(sizeof(Pila));
    if(pivote==NULL){
        printf ("Error allocating memory");
        exit(-1);
    }
    pivote->size = 0;
    pivote->ultimo=NULL;
    return pivote;
}

void Push(Pila* Pila, Coor coordenada, int accion){
    Nodo* pivote=(Nodo*) malloc(sizeof(Nodo));
    pivote->Coodenadas=coordenada;
    pivote->accion=accion;

    if(Pila->size == 0){
        pivote->next=NULL;
        Pila->ultimo=pivote;
    }else{
        pivote->next=Pila->ultimo;
        Pila->ultimo=pivote;
    }
    Pila->size++;
}



void Pop(Pila* Pila){
    if (Pila->size > 0){
        Nodo *pivote = Pila->ultimo->next;
        Pila->ultimo=pivote;
        Pila->size--;
    }

}