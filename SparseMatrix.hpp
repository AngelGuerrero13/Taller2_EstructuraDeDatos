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
        void add(int value, int xPos, int yPos);
        int get(int xPos, int yPos);
        void remove(int xPos, int yPos);
        void printStoredValues();
        int density();
        SparseMatrix* multiply(SparseMatrix* second);
        ~SparseMatrix();
};