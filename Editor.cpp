#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "Editor.h"

Editor::Editor(string _nombre_archivo){
    nombre_archivo = _nombre_archivo;
}

vector<string> Editor::dividir(string linea){
    vector<string> palabras;
    stringstream linea_stream(linea);
    string palabra;
    while (getline(linea_stream, palabra, ' ')){
        palabras.push_back(palabra);
    }
    return palabras;
}

void Editor::guardar(vector<string> lineas){
    ofstream archivoout(nombre_archivo);
    for (int i=0; i<lineas.size(); i++){
        archivoout << lineas[i] << endl;
    }
}

void Editor::leer(){
    ifstream archivo(nombre_archivo);

    cout << "Contenido de " << nombre_archivo << endl;
    string linea;
    while(getline(archivo, linea)){ 
     cout << linea << endl;
    }

    cout << endl << "Fin del archivo" << endl;
}

void Editor::justificar(){
    ifstream archivoin(nombre_archivo);
    vector<string> lineas;

    // Obtener linea con mas caracteres
    string linea;
    int max = 0;
    while(getline(archivoin, linea)){ 
        lineas.push_back(linea);
        if (linea.length()>max) {max = linea.length();}
    }

    archivoin.close();

    cout << "Maximo: " << max << endl;

    ofstream archivoout(nombre_archivo);
    for (int i=0; i<lineas.size(); i++){
        int num_espacios = std::count (lineas[i].begin(), lineas[i].end(), ' ');
        int espacios_necesarios = max - (lineas[i].length() - num_espacios); // obtener espacios necesarios para justificar
        vector<string> palabras = Editor::dividir(lineas[i]); 
        for (int j=0; j<palabras.size(); j++){
            archivoout << palabras[j];
            for (int k=0; k< espacios_necesarios/num_espacios; k++){
                archivoout << " ";
            }
        }
        archivoout << endl;
    }
}

void Editor::alinear_izq(){
    ifstream archivoin(nombre_archivo);
    vector<string> lineas;

    // Obtener posicion de primer caracter no blanco
    string linea;
    int max = 0;
    while(getline(archivoin, linea)){ 
        for (int i=0; i<linea.length(); i++){
            if (linea[i]!=' '){
                linea.erase(0, i);
                lineas.push_back(linea);
                break;
            }
        }
    }
    archivoin.close();

    // Guardar lineas modificadas en archivo
    Editor::guardar(lineas);

    cout << "El archivo " << nombre_archivo << " ha sido alineado a la izquierda" << endl;
}

void Editor::alinear_der(){
    ifstream archivoin(nombre_archivo);
    vector<string> lineas;

    // Obtener linea con mas caracteres para determinar el espacio para alinear a la derecha y guardar las lineas
    string linea;
    int max = 0;
    while(getline(archivoin, linea)){ 
        lineas.push_back(linea);
        if (linea.length()>max) {max = linea.length();}
    }

    archivoin.close();

    // Abrir archivo en modo escribir para sobreescribirlo
    ofstream archivoout(nombre_archivo);
    for (int i=0; i<lineas.size(); i++){
        archivoout << setw(max) << lineas[i] << endl;
    }

    cout << "El archivo " << nombre_archivo << " ha sido alineado a la derecha" << endl;
}

void Editor::centrar(){
    cout << "Se ha seleccionado la opcion de centrado" << endl;
}

int Editor::buscar_palabra(string palabra_buscar){
    ifstream archivoin(nombre_archivo);

    string linea;
    int num_linea = 1;
    while(getline(archivoin, linea)){ // recorrer cada linea
        vector<string> palabras = Editor::dividir(linea); // dividir linea en palabras
        for (int i=0; i<palabras.size(); i++){ // recorrer cada palabra
            if (palabras[i].compare(palabra_buscar)==0){
                return num_linea;
            }
        }
        num_linea++;
    }

    return -1;
}

int Editor::reemplazar_palabra(string vieja, string nueva){
    ifstream archivoin(nombre_archivo);
    vector<string> lineas;
    int palabras_reemplazadas = 0;
    int num_linea = 1;

    // Recorrer cada linea y modificar cada palabra
    string linea;
    int max = 0;
    while(getline(archivoin, linea)){
        string palabras_unidas = "";
        vector<string> palabras = Editor::dividir(linea); // dividir linea en palabras
        for (int i=0; i<palabras.size(); i++){ // recorrer cada palabra
            if (palabras[i].compare(vieja)==0){
                palabras[i] = nueva;
                palabras_reemplazadas++;
                cout << "Palabra reemplazada en linea " << num_linea << endl;
            }
            palabras_unidas += " " + palabras[i];
        }
        palabras_unidas.erase(0,1); // borrar espacio del principio
        linea = palabras_unidas;
        lineas.push_back(linea); // guardar linea
        num_linea++;
    }
    archivoin.close();

    // Guardar lineas modificadas en archivo
    Editor::guardar(lineas);

    return palabras_reemplazadas;
}

int Editor::contar_palabra(string palabra_buscar){
    ifstream archivoin(nombre_archivo);
    string linea;
    int contador = 0;

    while(getline(archivoin, linea)){ // recorrer cada linea
        vector<string> palabras = Editor::dividir(linea); // dividir linea en palabras
        for (int i=0; i<palabras.size(); i++){
            if (palabras[i].compare(palabra_buscar)==0){
                contador++;
            }
        }
    }
    return contador;
}

void Editor::encriptar(){
    ifstream archivoin(nombre_archivo);
    string linea;
    vector<string> lineas;
    int contador = 0;

    while(getline(archivoin, linea)){ // recorrer cada linea
        for (int i=0; i<linea.length(); i++){ // recorrer cada caracter
            linea[i] = char(linea[i]+1);
        }
        lineas.push_back(linea);
    }

    Editor::guardar(lineas);
}

void Editor::desencriptar(){
    ifstream archivoin(nombre_archivo);
    string linea;
    vector<string> lineas;
    int contador = 0;

    while(getline(archivoin, linea)){ // recorrer cada linea
        for (int i=0; i<linea.length(); i++){ // recorrer cada caracter
            linea[i] = char(linea[i]-1);
        }
        lineas.push_back(linea);
    }

    Editor::guardar(lineas);
}