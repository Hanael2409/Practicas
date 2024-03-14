//Chavez Garcia
#include <iostream>
#include <fstream>
#include <ostream>
#include "../miBiblioteca/ListaSimple.h"

using namespace std;

void generaLista(ListaSimple& LS);
void guardaArchivo(ListaSimple& LS, string NombreArchivo);

int main(){
    ListaSimple LS;
    generaLista(LS);
    LS.insertaUnNodoAlFinal(10);
    LS.insertaUnNodoAlFinal(30);
    LS.insertaUnNodoAlFinal(40);
    LS.insertaUnNodoAlFinal(30);
    LS.insertaUnNodoAlFinal(10);
    LS.insertaUnNodoAlFinal(30);
    LS.insertaUnNodoAlFinal(10);
    LS.insertaUnNodoAlFinal(30);

    cout << "Datos que quedaron en la lista:" << endl;
    LS.muestraTusDatos();
    cout << endl;

    guardaArchivo( LS, "C:\\Users\\mostr\\OneDrive\\Documentos\\Estructuras\\miBiblioteca\\ListaSimple.txt");
    return 0;
}

void generaLista(ListaSimple& LS) {
    int numero, dato;
    numero = rand() % 41 + 10;
    for ( int i = 0; i < numero; i++ ) {
        dato = rand() % 21;
        LS.insertaUnNodoAlFinal(dato);
    }
}

void guardaArchivo(ListaSimple& LS, string NombreArchivo) {
    Nodo* aux;
    ofstream ArchivoSalida;
    ArchivoSalida.open(NombreArchivo.c_str());
    if (!ArchivoSalida.good()) {
        cout << "El archivo no se pudo abrir" << endl;
        system ("pause");
        exit (-1);
    }
    while(aux != NULL) {
        ArchivoSalida << aux->dameTuDato() << endl;
        aux = aux->dameTuSiguiente();
    }
    ArchivoSalida.close();
}
