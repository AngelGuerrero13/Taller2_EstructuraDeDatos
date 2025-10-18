#include "SparseMatrix.hpp"
#include "Nodo.hpp"

SparseMatrix::SparseMatrix(){
    start = nullptr;
}

void SparseMatrix::add(int dato, int xPos, int yPos){
    
    Nodo* nuevo = new Nodo(dato);

    if(start == nullptr){

    }else{

        Nodo* actual = start;

        while(actual != nullptr){

        }
    }
}

int SparseMatrix::get(int xPos, int yPos){

}
void SparseMatrix::remove(int xPos, int yPos){

}
void SparseMatrix::printStoredValues(){

}
int SparseMatrix::density(){
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){

}
SparseMatrix::~SparseMatrix(){

}