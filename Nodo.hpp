#pragma once
#include <iostream>
using namespace std;

class Nodo{
    private:
        int dato;
        Nodo* izquierda;
        Nodo* derecha;
        Nodo* arriba;
        Nodo* abajo;
    public:
        Nodo(int dato);
        int getDato();
        Nodo* getIzquierda();
        Nodo* getDerecha();
        Nodo* getArriba();
        Nodo* getAbajo();
        void setDato(int dato);
        void setIzquierdo(Nodo* izquierdo);
        void setDerecho(Nodo* derecho);
        void setArriba(Nodo* arriba);
        void setAbajo(Nodo* abajo);
        ~Nodo();
};