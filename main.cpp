#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SparseMatrix.hpp"

void crearMatriz(SparseMatrix* matriz, int filas, int columnas, int cantidadDatos){
    int inserted = 0;
    while (inserted < cantidadDatos) {
        int fila = rand() % filas;
        int col  = rand() % columnas;
        int val  = rand() % 9 + 1;
        if (matriz->get(fila, col) == 0) {
            matriz->add(val, fila, col);
            inserted++;
            
        }
        
    }

    cout << "Densidad: " << matriz->density() << endl;

};

int main(){
    clock_t inicio, fin;
    double tiempo;
   
    
    SparseMatrix* matriz = new SparseMatrix();

    inicio = clock(); //guardar el tiempo inicial
    crearMatriz(matriz,15,15,50);
    
    
    fin = clock();//guarda el tiempo final
    tiempo = double(fin -inicio) / CLOCKS_PER_SEC; //conversion a segundos
    
    cout << "Tiempo de ejecucion: " << tiempo << " segundos" << endl;


    return 0;
}