#include <iostream>
#include <vector>
#include <fstream>

#define ESTADO_COMPRAR 1
#define ESTADO_AGREGAR 2
#define ESTADO_VER 3

using namespace std;

class ropa
{
    public:
        string color;
        string tela;
        string talle;
    ropa(string col, string tel, string tal) {
        this->color = col;
        this->tela = tel;
        this->talle = tal;
    };
};

vector<ropa> prendas;

void menu ();
void agregar();
void stock ();
void comprar();

int main() {
    cout << "Hola! Bienvenido a mi tienda! Que queres hacer hoy?" << endl;
    int confirm = 1;
    do {
        cout << "MENU: " << endl;
        menu();
        cout << "Continuar? (si=1/no=2)" << endl;
        cin >> confirm;
        system("@cls||clear");
    } while(confirm == 1);
    
    return 0;
}
void menu () {
    
    cout << "1. Comprar" << endl;
    cout << "2. Agregar stock" << endl;
    cout << "3. Ver stock" << endl;
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case ESTADO_COMPRAR:
            cout << "Elegiste la opcion Comprar" << endl;
            comprar();
            
            break;
        case ESTADO_AGREGAR:
            cout << "Elegiste la opcion Agregar stock" << endl;
            agregar ();
            break;
        case ESTADO_VER:
            cout << "Este es el stock:" << endl;
            stock();
            break;
    }
}
    void comprar() {
        string nombreArchivo = "ropa.txt";
        ifstream archivo(nombreArchivo.c_str());
        string linea;
        string compra;
        
        cout << "Escriba una caracteristica del producto que quiere comprar:" << endl;
        cin >> compra;
        
        string temp = "";        
        while (getline(archivo, linea)) {
            for (int i = 0; i < linea.length(); i++) {
                char letra = linea[i];
                cout << letra << endl;
                if (letra == compra[i]) {
                    int x = 1;
                    temp += letra;
                    do {
                        if (letra == compra[x] && x < compra.length()) {
                            cout << "Next" << endl;
                            temp += linea[x];
                            x++;
                        } else if(letra == compra[x] && x >= compra.length()) {
                            cout << "TEMP" << temp << endl;
                        } else {
                            x = 0;
                            temp = "";
                        }
                    } while(x > 0);
                    
                    cout << "FOR" << temp << endl;
                }
            }
        }
        cout << temp;
        
        archivo.close();
    }
    void agregar () {
        string newcolor;
        string newtela;
        string newtalle;
        fstream pf("ropa.txt", ios::out | ios::in);
        
        cout << "Ingrese el color del producto:" << endl;
        cin >> newcolor;
        cout << "Ingrese la tela del producto:" << endl;
        cin >> newtela;
        cout << "Ingrese el talle del producto:" << endl;
        cin >> newtalle;
        pf<<"color: "<<newcolor << " | tela: " << newtela << " | talle: " << newtalle << endl;
        prendas.push_back(ropa(newcolor, newtela, newtalle));
        cout << "Nuevo objeto creado! Sus caracteristicas son:"<< endl << newcolor << endl << newtela << endl << newtalle << endl;
    
        pf.close();
    }
    
    void stock () {
        string nombreArchivo = "ropa.txt";
        ifstream archivo(nombreArchivo.c_str());
        string linea; 
        
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
