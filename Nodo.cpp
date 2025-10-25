#include "Nodo.hpp"

Nodo::Nodo(int dato,int fila, int columna){
    this->dato = dato;
    this->fila = fila;
    this->columna = columna;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

int Nodo::getDato(){
    return this->dato;
}
int Nodo::getFila(){
    return this->fila;
}
int Nodo::getColumna(){
    return this->columna;
}
Nodo* Nodo::getIzquierda(){
    return this->izquierda;
}
Nodo* Nodo::getDerecha(){
    return this->derecha;
}
Nodo* Nodo::getArriba(){
    return this->arriba;
}
Nodo* Nodo::getAbajo(){
    return this->abajo;
}

void Nodo::setDato(int dato){
    this->dato = dato;
}
void Nodo::setIzquierdo(Nodo* izquierda){
    this->izquierda = izquierda;
}
void Nodo::setDerecho(Nodo* derecha){
    this->derecha = derecha;
}
void Nodo::setArriba(Nodo* arriba){
    this->arriba = arriba;
}
void Nodo::setAbajo(Nodo* abajo){
    this->abajo = abajo;
}

Nodo::~Nodo(){
    
}