#include "Nodo.hpp";

Nodo::Nodo(int dato){
    this->dato = dato;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

int Nodo::getDato(){
    return this->dato;
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
    cout << "Nodo eliminado" << endl;
}