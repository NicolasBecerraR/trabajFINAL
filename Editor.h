#include <vector>
using namespace std;

class Editor{
    private:
        string nombre_archivo;
        vector<string> dividir(string linea);
        void guardar(vector<string> lineas);
    public:
        Editor(string _nombre_archivo);
        void leer();
        void justificar();
        void alinear_izq();
        void alinear_der();
        void centrar();
        int buscar_palabra(string palabra_buscar); // devuelve el numero de linea
        int reemplazar_palabra(string vieja, string nueva); // devuelve el numero de palabras reemplazadas
        int contar_palabra(string palabra_buscar);
        void encriptar();
        void desencriptar();
};