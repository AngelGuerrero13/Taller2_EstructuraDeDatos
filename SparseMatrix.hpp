#pragma once
#include <iostream>
#include "Nodo.hpp"

class SparseMatrix {
    private:
        Nodo* start;
        int ceros;
        int maxFilas;
        int maxColumnas;
    public:
        SparseMatrix();
        void add(int value, int fila, int columna);
        int get(int fila, int columna);
        void remove(int fila, int columna);
        void printStoredValues();
        int density();
        SparseMatrix* multiply(SparseMatrix* second);
        ~SparseMatrix();
};