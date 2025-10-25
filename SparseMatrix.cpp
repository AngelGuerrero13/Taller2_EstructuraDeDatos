#include "SparseMatrix.hpp"

SparseMatrix::SparseMatrix(){
    start = new Nodo(0,-1,-1);
    start->setDerecho(start);
    start->setIzquierdo(start);
    start->setAbajo(start);
    start->setArriba(start);
    ceros = 0;
    maxFilas = -1;
    maxColumnas = -1;

}

void SparseMatrix::add(int dato, int fila, int columna){
    
    if (fila < 0 || columna < 0) { return;}//Si la fila o columna es negativa no se pueden poner datos

    if (dato == 0) {//Si el dato es cero no se guarda
        
        remove(fila, columna);//se elimina ese dato de la memoria
        return;
    }

    //Fila:
    Nodo* prevFila = start;             //Apunta al nodo anteriro a la cabecera (start)
    Nodo* cabFila  = start->getAbajo(); //Aputanta a la cabecera de fila

    
    while (cabFila != start && cabFila->getFila() < fila) { //Mientras la cabecera de la fila sea distinto a start y la fila actual sea menor a la fila buscada
        prevFila = cabFila;
        cabFila  = cabFila->getAbajo();
    }


    if (cabFila == start || cabFila->getFila() != fila) { //Si la cabecera de la fila es start o la fila actual es distinta a la fila buscada
        Nodo* nuevaFila = new Nodo(0, fila, -1); //Se crea cabecera de fila en (fila,-1)

        
        nuevaFila->setAbajo(cabFila);//abajo de la nueva fila apunta a la cabecera de la fila
        nuevaFila->setArriba(prevFila);//arriba de la nueva fila apunta al nodo anterior a la cabecera
        prevFila->setAbajo(nuevaFila);//abajo del nodo anterior apunta abajo de la nueva fila
        cabFila->setArriba(nuevaFila);//arriba de la cabecera de la fila apunta a nueva fila

        
        nuevaFila->setDerecho(nuevaFila);//la derecha de nuevaFila apunta a nueva fila
        nuevaFila->setIzquierdo(nuevaFila);//la izquierda de nuevaFila apunta a nueva fila
        
        cabFila = nuevaFila; //la cabecera de la fila ahora es nuevaFila
    }
    
    //Columna:
    Nodo* prevColumna = start;              // Apunta al nodo anterior a la cabecera actual
    Nodo* cabColumna  = start->getDerecha(); // Apunta a la primera cabecera de columna

    
    while (cabColumna != start && cabColumna->getColumna() < columna) { //Mientras la cabecera de la columna sea distinto a start y la columna actual sea menor a la columna buscada
        prevColumna = cabColumna;
        cabColumna  = cabColumna->getDerecha(); //Seguimos bajando
    }

    
    if (cabColumna == start || cabColumna->getColumna() != columna) { //Si la cabecera de la columna es start o la columna actual es distinta a la columna buscada
        Nodo* nuevaColumna = new Nodo(0, -1, columna); //Se crea cabecera de columna en (-1,columna)

        
        nuevaColumna->setDerecho(cabColumna);//Derecha de la nueva columna apunta a la cabecera de la columna
        nuevaColumna->setIzquierdo(prevColumna);//Izquierda de la nueva columna apunta al nodo anterior a la cabecera
        prevColumna->setDerecho(nuevaColumna);//Derecha del nodo anterior apunta abajo de la nueva columna
        cabColumna->setIzquierdo(nuevaColumna);//Izquierda de la cabecera de la columna apunta a nueva columna

        
        nuevaColumna->setAbajo(nuevaColumna);//Abajo de nuevaColumna apunta a nueva columna
        nuevaColumna->setArriba(nuevaColumna);//Arriba de nuevaColumna apunta a nueva columna
        
        cabColumna = nuevaColumna; //la cabecera de la columna ahora es nuevaColumna
    }


    Nodo* anteriorFila = cabFila;            // Nodo anterior en la fila
    Nodo* cursorFila   = cabFila->getDerecha(); // Primer nodo de la fila

    
    while (cursorFila != cabFila && cursorFila->getColumna() < columna) { //Mientras el cursor de la fila sea distinto a la cabecera de la fila y la columna actual sea menor a la columna buscada
        anteriorFila = cursorFila;
        cursorFila   = cursorFila->getDerecha();
    }

    // Si ya existe el nodo solo actualizamos el valor
    if (cursorFila != cabFila && cursorFila->getColumna() == columna) {
        cursorFila->setDato(dato);
        if (fila > maxFilas) maxFilas = fila;
        if (columna > maxColumnas) maxColumnas = columna;
        return;
    }



    Nodo* nuevo = new Nodo(dato, fila, columna);

    // Insertar en la fila
    nuevo->setDerecho(cursorFila);
    nuevo->setIzquierdo(anteriorFila);
    anteriorFila->setDerecho(nuevo);
    cursorFila->setIzquierdo(nuevo);

    // Insertar en la columna
    Nodo* anteriorCol = cabColumna;
    Nodo* cursorCol   = cabColumna->getAbajo();

    while (cursorCol != cabColumna && cursorCol->getFila() < fila) {
        anteriorCol = cursorCol;
        cursorCol   = cursorCol->getAbajo();
    }

    //Actualizar datos de la matriz
    nuevo->setAbajo(cursorCol);
    nuevo->setArriba(anteriorCol);
    anteriorCol->setAbajo(nuevo);
    cursorCol->setArriba(nuevo);

    
    ceros++; // aumenta el número de nodos no nulos

    if (fila > maxFilas) maxFilas = fila;
    if (columna > maxColumnas) maxColumnas = columna;
}

int SparseMatrix::get(int fila, int columna){
    if(fila < 0 || columna < 0){//Si la fila o columna es negativa no hay datos
        return 0;
    }

    Nodo* cabFila = start->getAbajo();

    while(cabFila != start && cabFila->getFila() < fila){//Mientras la cabecera de la fila sea distinto a start y la fila actual sea menor a la fila buscada
        cabFila = cabFila->getAbajo();//Seguimos bajando
    }

    if(cabFila == start || cabFila->getFila() != fila){//Si la cabecera de la fila es start o la fila actual es distinta a la fila buscada
        return 0;
    }

    Nodo* cursorFila = cabFila->getDerecha();

    while(cursorFila != cabFila && cursorFila->getColumna() < columna){//Mientras el cursor de la fila sea distinto a la cabecera de la fila y la columna actual sea menor a la columna buscada
        cursorFila = cursorFila->getDerecha();//Seguimos avanzando
    }

    if(cursorFila != cabFila && cursorFila->getColumna() == columna){//Si el cursor de la fila es distinto a la cabecera de la fila y la columna actual es igual a la columna buscada
        return cursorFila->getDato();//Retornamos el dato
    }

    return 0;//Si no se encuentra el valor retorna cero
}

void SparseMatrix::remove(int fila, int columna){
     if(fila < 0 || columna < 0){ //Si la fila o columna es negativa no se pueden acceder a los datos
        return;
    }

    Nodo* prevFila = start;              //Apunta al nodo anterior a la cabecera (start)
    Nodo* cabFila = start->getAbajo();   //Apunta a la primera cabecera de fila

    while(cabFila != start && cabFila->getFila() < fila){ //Mientras la cabecera de la fila sea distinta de start y la fila actual sea menor a la buscada
        prevFila = cabFila;
        cabFila = cabFila->getAbajo();   //Seguimos bajando
    }

    if(cabFila == start || cabFila->getFila() != fila){ //Si llegamos a start o la fila actual no coincide con la buscada
        return; //No hay fila
    }

    Nodo* prevNodo = cabFila;              //Apunta al nodo anterior dentro de la fila actual
    Nodo* actual = cabFila->getDerecha();  //Apunta al primer nodo de la fila actual

    while(actual != cabFila && actual->getColumna() < columna){ //Mientras no volvamos a la cabecera y la columna actual sea menor a la buscada
        prevNodo = actual;
        actual = actual->getDerecha();     //Avanzamos por la fila (a la derecha)
    }

    if(actual == cabFila || actual->getColumna() != columna){ //Si volvimos a la cabecera o no encontramos la columna
        return; //No hay columna (no existe el nodo a eliminar)
    }

    prevNodo->setDerecho(actual->getDerecha());           //El nodo anterior apunta al siguiente (saltando el nodo eliminado)
    actual->getDerecha()->setIzquierdo(prevNodo);         //El siguiente nodo apunta atrás al anterior

    Nodo* prevColumna = start;               //Apunta a la cabecera anterior de columna
    Nodo* cabColumna = start->getDerecha();  //Apunta a la primera cabecera de columna

    while(cabColumna != start && cabColumna->getColumna() < columna){ //Mientras no lleguemos a start y la columna actual sea menor a la buscada
        prevColumna = cabColumna;
        cabColumna = cabColumna->getDerecha(); //Avanzamos hacia la derecha (siguiente columna)
    }

    if(cabColumna != start && cabColumna->getColumna() == columna){ //Si encontramos la cabecera de la columna correspondiente

        Nodo* prevNodoColumna = cabColumna;           //Apunta al nodo anterior dentro de la columna
        Nodo* actualColumna = cabColumna->getAbajo(); //Apunta al primer nodo de la columna actual

        while(actualColumna != cabColumna && actualColumna->getFila() < fila){ //Mientras no volvamos a la cabecera y la fila actual sea menor a la buscada
            prevNodoColumna = actualColumna;
            actualColumna = actualColumna->getAbajo(); //Avanzamos hacia abajo
        }

        if(actualColumna == actual){ //Si el nodo actual de la columna coincide con el que vamos a eliminar
            prevNodoColumna->setAbajo(actualColumna->getAbajo());        //El nodo anterior apunta hacia abajo al siguiente
            actualColumna->getAbajo()->setArriba(prevNodoColumna);       //El siguiente apunta hacia arriba al anterior
        }
    }

    // Eliminar el nodo encontrado

    delete actual; //Eliminamos el nodo de la memoria
    ceros--;   //Reducimos el contador de nodos no nulos

    // Si la fila quedó vacía, eliminar su cabecera

    if(cabFila->getDerecha() == cabFila){ //Si la cabecera apunta a sí misma (sin nodos a la derecha)
        cabFila->getArriba()->setAbajo(cabFila->getAbajo()); //Desconectamos la cabecera de la fila del anillo vertical
        cabFila->getAbajo()->setArriba(cabFila->getArriba());
        delete cabFila; //Eliminamos la cabecera de la fila
    }

    // Si la columna quedó vacía, eliminar su cabecera

    if(cabColumna != start && cabColumna->getAbajo() == cabColumna){ //Si la cabecera de la columna existe y apunta a sí misma (sin nodos abajo)
        cabColumna->getIzquierda()->setDerecho(cabColumna->getDerecha()); //Desconectamos la cabecera del anillo horizontal
        cabColumna->getDerecha()->setIzquierdo(cabColumna->getIzquierda());
        delete cabColumna; //Eliminamos la cabecera de la columna
    }

    // Recalcular los límites (filas y columnas máximas)

    if(fila == maxFilas || columna == maxColumnas){ //Si fila ingresada es igual a maximo de filas o columna ingresada es igual al maximo de columnas

        int nuevaMaxFila = -1;
        int nuevaMaxColumna = -1;

        //Recorremos toda la matriz para encontrar los nuevos valores máximos

        for(Nodo* f = start->getAbajo(); f != start; f = f->getAbajo()){ //Recorremos todas las filas
            for(Nodo* c = f->getDerecha(); c != f; c = c->getDerecha()){ //Recorremos cada nodo dentro de la fila
                if(c->getFila() > nuevaMaxFila){ 
                    nuevaMaxFila = c->getFila(); //Actualizamos la fila máxima
                }
                if(c->getColumna() > nuevaMaxColumna){ 
                    nuevaMaxColumna = c->getColumna(); //Actualizamos la columna máxima
                }
            }
        }

        maxFilas = nuevaMaxFila;       //Actualizamos el valor máximo de fila
        maxColumnas = nuevaMaxColumna; //Actualizamos el valor máximo de columna
    }

}

void SparseMatrix::printStoredValues(){

    cout<<"Elementos de la matriz:"<<endl;

    Nodo* cabeceraFila = start->getAbajo();//Recorrer las cabecelas de la fila de arriba a abajo

    while(cabeceraFila != start){//Mientras la cabecera de la fila sea distinta a start

        Nodo* actual = cabeceraFila->getDerecha();//Recorrer la fila de izquierda a derecha

        while(actual != cabeceraFila){//Mientras el actual de la fila sea distinto a la cabecera de la fila

            cout<<"("<<actual->getFila()<<","<<actual->getColumna()<<") --> "<<actual->getDato()<<endl;//Imprimir coordenadas y el dato con el formato: (fila,columna) --> dato

            actual = actual->getDerecha();//Pasamos al siguiente nodo, avanzamos a la siguiente columna
        }

        cabeceraFila = cabeceraFila->getAbajo();//Pasamos a la siguiente fila, Seguimos bajando
    }
}

int SparseMatrix::density(){
    if(start == nullptr) return 0;

    int count = 0;
    int maxFila = -1, maxCol = -1;

    Nodo* filacabeza = start->getAbajo(); //filacabeza recorre las filas usando abajo
    while(filacabeza != start){
        Nodo* columnaActual  = filacabeza->getDerecha();// columnaActual recorre los nodos de la fila usando derecha
        while(columnaActual  != filacabeza){
            count++; // cuenta los nodos no nulos
            if(columnaActual ->getFila()> maxFila) maxFila = columnaActual ->getFila();
            if(columnaActual ->getColumna() > maxCol) maxCol = columnaActual ->getColumna();
            columnaActual  = columnaActual ->getDerecha();
        }
        filacabeza = filacabeza->getAbajo();
    }
    
    if(maxFila == -1 || maxCol == -1) return 0;

    int total = (maxFila + 1) * (maxCol + 1); // tamaño maximo actual de la matriz

    if(total == 0) return 0;

    double dens = double(count) / double(total); // densidad como valor decimal
    int porcentaje = int(dens * 100.0 + 0.5);

    return porcentaje; // retorna la densidad en porcentaje
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    if (!second) return nullptr;

    SparseMatrix* C = new SparseMatrix();

    // Si alguna no tiene datos, el resultado es vacío
    if (this->start->getAbajo() == this->start || second->start->getDerecha() == second->start) {
        return C;
    }

    // Recorremos cada FILA de A (cabeceras de fila cuelgan "abajo" desde start)
    for (Nodo* filaA = this->start->getAbajo(); filaA != this->start; filaA = filaA->getAbajo()) {

        // Recorremos cada COLUMNA de B (cabeceras de columna cuelgan "derecha" desde start)
        for (Nodo* colB = second->start->getDerecha(); colB != second->start; colB = colB->getDerecha()) {

            int suma = 0;

            // Dos punteros:
            // a recorre la fila i de A (a la derecha) -> elementos (i, k)
            // b recorre la columna j de B (hacia abajo) -> elementos (k, j)
            Nodo* a = filaA->getDerecha();
            Nodo* b = colB->getAbajo();

            while (a != filaA && b != colB) {
                int kA = a->getColumna(); // k en (i,k)
                int kB = b->getFila();    // k en (k,j)

                if (kA == kB) {
                    suma += a->getDato() * b->getDato();
                    a = a->getDerecha();
                    b = b->getAbajo();
                } else if (kA < kB) {
                    a = a->getDerecha();
                } else { // kA > kB
                    b = b->getAbajo();
                }
            }

            if (suma != 0) {
                C->add(suma, filaA->getFila(), colB->getColumna());
            }
        }
    }

    return C;
}


SparseMatrix::~SparseMatrix(){
    Nodo* r = start->getAbajo();
    while (r != start) {
        Nodo* fila = r;
        r = r->getAbajo();
        Nodo* it = fila->getDerecha();
        while (it != fila) {
            Nodo* del = it;
            it = it->getDerecha();
            delete del;
        }
        delete fila;
    }
    // borrar cabeceras de columna
    Nodo* c = start->getDerecha();
    while (c != start) {
        Nodo* del = c;
        c = c->getDerecha();
        delete del;
    }
    delete start;
    start = nullptr;

}