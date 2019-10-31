#include <iostream>
#include "Menu.h"
#include "Editor.h"

using namespace std;

int main(){
    Menu menu;
    
    // Iniciar
    menu.mostrar_bienvenida();

    // Crear objeto editor
    string nombre_archivo = menu.preguntar_archivo();
    Editor editor(nombre_archivo);

    // Ejecutar opcion
    menu.mostrar_opciones();
    int opcion = menu.preguntar_opcion();
    string palabra;
    switch (opcion){
        case 0:{ // Leer archivo
            editor.leer();
            break;
        }
        case 1:{ // Justificar archivo
            editor.justificar();
            break;
        }
        case 2:{ // Alinear a la izquierda
            editor.alinear_izq();
            break;
        }
        case 3:{ // Alinear a la derecha
            editor.alinear_der();
            break;
        }
        case 4:{ // Centrar texto
            editor.centrar();
            break;
        }
        case 5:{ // Buscar palabra
            palabra =  menu.preguntar_palabra();
            int linea = editor.buscar_palabra(palabra);
            if (linea<0) {cout << "La palabra '"  << palabra << "' no se ha encontrado";}
            else {cout << "La palabra '" << palabra << "' se encuentra en la linea " << linea << endl;}
            break;
        }
        case 6:{ // Reemplazar palabra
            cout << "Primero ingresar la palabra a reemplazar." << endl;
            string palabra_vieja =  menu.preguntar_palabra();
            cout << "Ahora ingresar la nueva palabra por la que se reemplazara" << endl;
            string palabra_nueva =  menu.preguntar_palabra();
            int reemplazos = editor.reemplazar_palabra(palabra_vieja, palabra_nueva);
            cout << "Se ha reemplazado la palabra '" << palabra_vieja << "' por '" << palabra_nueva << "' " << reemplazos << " veces" << endl;
            break;
        }
        case 7:{ // Contar palabras
            palabra =  menu.preguntar_palabra();
            int frecuencia = editor.contar_palabra(palabra);
            cout << "La palabra '" << palabra << "' aparece " << frecuencia << " veces" << endl;
            break;
        }
        case 8:{ // Encriptar archivo
            editor.encriptar();
            break;
        }
        case 9:{ // Desencriptar archivo
            editor.desencriptar();
        }
    }
}