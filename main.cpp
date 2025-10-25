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
    crearMatriz(matriz,8,8,50);
    auto fin = high_resolution_clock::now();

    
    auto duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    auto duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;


    inicio = high_resolution_clock::now();
    SparseMatrix* matrizB = new SparseMatrix();
    crearMatriz(matrizB,8,8,50);
    fin = high_resolution_clock::now();

    duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;

     cout << "get() "<< endl;
    
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            inicio = high_resolution_clock::now();
            matriz->get(i,j);
            fin = high_resolution_clock::now();
        }
    }

    duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;

    cout << "remove() "<< endl;

    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            inicio = high_resolution_clock::now();
            matriz->remove(i,j);
            fin = high_resolution_clock::now();
        }
    }

    duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;

    cout<<"print"<<endl;

    for(int i=0;i<20;i++){
        
        inicio = high_resolution_clock::now();
        matriz->printStoredValues();
        fin = high_resolution_clock::now();

        duracion_micro = duration_cast<microseconds>(fin - inicio);
        cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

        duracion_nano = duration_cast<nanoseconds>(fin - inicio);
        cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;
    }

    cout<<"multiplicar"<<endl;

    for(int i=0;i<20;i++){

        inicio = high_resolution_clock::now();
        SparseMatrix* resultado = matriz->multiply(matrizB);
        fin = high_resolution_clock::now();
    }

    duracion_micro = duration_cast<microseconds>(fin - inicio);
    cout << "Tiempo en microsegundos: " << duracion_micro.count() << " µs" << endl;

    duracion_nano = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo en nanosegundos: " << duracion_nano.count() << " ns" << endl;

    delete matriz;
    delete matrizB;

    return 0;
}   