#include <iostream>
#include <chrono>
#include <cstdlib>
#include "SparseMatrix.hpp"
using namespace std;
using namespace std::chrono;

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
    
   
    
    SparseMatrix* matriz = new SparseMatrix();

    auto inicio = high_resolution_clock::now();
    crearMatriz(matriz,80,80,5000);
    auto fin = high_resolution_clock::now();

    
    auto duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    
    auto duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;

    return 0;
}   