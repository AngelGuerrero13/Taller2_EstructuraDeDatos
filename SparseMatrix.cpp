#include "SparseMatrix.hpp"

SparseMatrix::SparseMatrix(){
    start = new Nodo(0,-1,-1);
    start->setDerecho(start);
    start->setAbajo(start);
    int ceros = 0;
    maxFilas = -1;
    maxColumnas = -1;

}

void SparseMatrix::add(int dato, int fila, int columna){
    
    if(fila < 0 || columna < 0){//Si la fila o columna es negativa no se pueden poner datos
        return;
    }

    if(dato == 0){//Si el dato es cero no se guarda
        remove(fila, columna);//se elimina ese dato de la memoria
        return;
    }

    //Fila:

    Nodo* prevFila = start;//Apunta al nodo anteriro a la cabecera (start)
    Nodo* cabFila = start->getAbajo();//Aputanta a la cabecera de fila

    while(cabFila != start && cabFila->getFila() < fila){//Mientras la cabecera de la fila sea distinto a start y la fila actual sea menor a la fila buscada
        prevFila = cabFila;
        cabFila = cabFila->getAbajo();//Seguimos bajando
    }

    if(cabFila == start || cabFila->getFila() != fila){//Si la cabecera de la fila es start o la fila actual es distinta a la fila buscada

        Nodo* nuevaFila = new Nodo(0,fila,-1);//Se crea cabecera de fila en (fila,-1)

        nuevaFila->setAbajo(cabFila);//abajo de la nueva fila apunta a la cabecera de la fila
        nuevaFila->setArriba(prevFila);//arriba de la nueva fila apunta al nodo anterior a la cabecera
        prevFila->setAbajo(nuevaFila);//abajo del nodo anterior apunta abajo de la nueva fila
        cabFila->setArriba(nuevaFila);//arriba de la cabecera de la fila apunta a nueva fila

        nuevaFila->setDerecho(nuevaFila);//la derecha de nuevaFila apunta a nueva fila
        nuevaFila->setIzquierdo(nuevaFila);//la izquierda de nuevaFila apunta a nueva fila

        cabFila = nuevaFila;//la cabecera de la fila ahora es nuevaFila
    }

    //Columna:

    Nodo* prevColumna = start;//Apunta al nodo anterior a la cabecera (start)
    Nodo* cabColumna = start->getDerecha();//Aputa a la cabecera de la columna

    while(cabColumna != start && cabColumna->getColumna() < columna){//Mientras la cabecera de la columna sea distinto a start y la columna actual sea menor a la columna buscada
        prevColumna = cabColumna;
        cabColumna = cabColumna->getAbajo();//Seguimos bajando
    }

    if(cabColumna == start || cabColumna->getColumna() != fila){//Si la cabecera de la columna es start o la columna actual es distinta a la columna buscada

        Nodo* nuevaColumna = new Nodo(0,-1,columna);//Se crea cabecera de columna en (-1,columna)

        nuevaColumna->setDerecho(cabColumna);//Derecha de la nueva columna apunta a la cabecera de la columna
        nuevaColumna->setIzquierdo(prevColumna);//Izquierda de la nueva columna apunta al nodo anterior a la cabecera
        prevColumna->setDerecho(nuevaColumna);//Derecha del nodo anterior apunta abajo de la nueva columna
        cabColumna->setIzquierdo(nuevaColumna);//Izquierda de la cabecera de la columna apunta a nueva columna

        nuevaColumna->setAbajo(nuevaColumna);//Abajo de nuevaColumna apunta a nueva columna
        nuevaColumna->setArriba(nuevaColumna);//Arriba de nuevaColumna apunta a nueva columna

        cabFila = nuevaColumna;//la cabecera de la columna ahora es nuevaColumna
    }

    //

    Nodo* anteriorFila = cabFila; //anterior en fila
    Nodo* cursorFila = cabFila->getDerecha();

    while(cursorFila != cabFila && cursorFila->getColumna() < columna){//Mientras el cursor de la fila sea distinto a la cabecera de la fila y la columna actual sea menor a la columna buscada
        anteriorFila = cursorFila;
        cursorFila = cursorFila->getDerecha();//Seguimos avanzando
    }

    if(cursorFila != cabFila && cursorFila->getColumna() == columna){//Si el cursor de la fila es distinto a la cabecera de la fila y la columna actual es igual a la columna buscada
        cursorFila->setDato(dato);//Se cambia el dato

        if(fila > maxFilas){
            maxFilas = fila;
        }

        if(columna > maxColumnas){
            maxColumnas = columna;
        }

        return;
    }
}

int SparseMatrix::get(int fila, int columna){

}
void SparseMatrix::remove(int fila, int columna){

}
void SparseMatrix::printStoredValues(){

}
int SparseMatrix::density(){
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){

}
SparseMatrix::~SparseMatrix(){

}