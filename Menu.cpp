#include <iostream>
#include <fstream>
#include "Menu.h"

void Menu::mostrar_bienvenida(){
    cout << "EDITOR DE TEXTOS" << endl;
    cout << "===============================================" << endl;
}

string Menu::preguntar_archivo(){
    string nombre;
    cout << "Ingrese el nombre de su archivo. Si el archivo es invalido (no existe) se volvera a pedir." << endl;

    ifstream archivo(nombre);
    while(!archivo){ // si el archivo no se ha podido abrir, repetir
        cout << "Nombre: ";
        cin >> nombre;

        archivo.close();
        archivo.open(nombre);
    }

    return nombre;
}

void Menu::mostrar_opciones(){
    cout << endl << "Menu" << endl;
    cout << "-----------" << endl;
    cout << "0. Leer archivo" << endl;
    cout << "1. Aplicar formato justificado y guardar" << endl;
    cout << "2. Aplicar alineado a la izquierda y guardar" << endl;
    cout << "3. Aplicar alineado a la derecha y guardar" << endl;
    cout << "4. Aplicar centrado y guardar" << endl;
    cout << "5. Buscar palabra" << endl;
    cout << "6. Reemplazar palabra" << endl;
    cout << "7. Contar palabra" << endl;
    cout << "8. Encriptar" << endl;
    cout << "9. Desencriptar" << endl;
    cout << "-----------" << endl;
}

int Menu::preguntar_opcion(){
    int opcion;
    cout << endl << "Ingresar el numero de opcion. Si la opcion es invalida se volvera a preguntar" << endl;
    
    do{
        cout << "# de opcion: ";
        cin >> opcion;
    }while(0>opcion && opcion>=10); // si la opcion es invalida, repetir
    cout << endl;

    return opcion;
}

string Menu::preguntar_palabra(){
    string palabra;
    cout << "Ingresar palabra: ";
    cin >> palabra;
    cout << endl;

    return palabra;
}