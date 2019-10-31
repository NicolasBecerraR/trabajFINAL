#include <string>

using namespace std;

class Menu{
    public:
        void mostrar_bienvenida();
        string preguntar_archivo();
        void mostrar_opciones();
        int preguntar_opcion();
        string preguntar_palabra();
};