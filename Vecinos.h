//
// Created by Rodrigo Gonzalez on 16-11-17.
//

#ifndef PROYECTOFINAL_VECINOS_H
#define PROYECTOFINAL_VECINOS_H

#endif //PROYECTOFINAL_VECINOS_H
typedef struct Coor{
    int x;
    int y;
}Coor;


Coor VecinoNorte(Coor target, int N);
Coor VecinoNO(Coor target, int N, int M);
Coor VecinoNE(Coor target, int N, int M);
Coor VecinoEste(Coor target, int M);
Coor VecinoOEste(Coor target, int M);
Coor VecinoSO(Coor target, int N, int M);
Coor VecinoSUR(Coor target, int N);
Coor VecinoSE(Coor target, int N, int M);


//(-1,0)
Coor VecinoNorte(Coor target, int N){
    int x,y;
    if ((target.x - 1)< 0){
        x=N-1;
    }else{
        x=target.x - 1;
    }
    y=target.y;

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}


//(-1,-1)
Coor VecinoNO(Coor target, int N, int M){
    int x,y;
    //Para X
    if ((target.x - 1)< 0){
        x=N-1;
    }else{
        x=target.x - 1;
    }

    //Para Y
    if ((target.y - 1)< 0){
        y=M-1;
    }else{
        y=target.y - 1;
    }

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}

//(-1,+1)
Coor VecinoNE(Coor target, int N, int M){
    int x,y;
    //Para X
    if ((target.x - 1)< 0){
        x=N-1;
    }else{
        x=target.x - 1;
    }

    //Para Y
    if ((target.y + 1)>= (M)){
        y=0;
    }else{
        y=target.y + 1;
    }

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}

//(0,+1)
Coor VecinoEste(Coor target, int M){
    int x,y;
    if ((target.y + 1) >= M){
        y=0;
    }else{
        y=target.y + 1;
    }
    x=target.x;

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}

//(0,+1)
Coor VecinoOEste(Coor target, int M){
    int x,y;
    if ((target.y - 1) < 0){
        y=M-1;
    }else{
        y=target.y - 1;
    }
    x=target.x;

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}

//(+1,-1)

Coor VecinoSO(Coor target, int N, int M){
    int x,y;
    //Para X
    if ((target.x + 1)>=N){
        x=0;
    }else{
        x=target.x + 1;
    }

    //Para Y
    if ((target.y - 1)<0){
        y=M-1;
    }else{
        y=target.y - 1;
    }

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}

//(+1,0)
Coor VecinoSUR(Coor target, int N){
    int x,y;
    if ((target.x + 1)>= N){
        x=0;
    }else{
        x=target.x + 1;
    }
    y=target.y;

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}
//(+1,+1)
Coor VecinoSE(Coor target, int N, int M){
    int x,y;
    //Para X
    if ((target.x + 1)>=N){
        x=0;
    }else{
        x=target.x + 1;
    }

    //Para Y
    if ((target.y + 1)>=M){
        y=0;
    }else{
        y=target.y + 1;
    }

    Coor VN;
    VN.x = x;
    VN.y = y;
    return VN;
}
