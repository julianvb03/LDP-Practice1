#include <iostream>
#include "Stack.h"
#include "vector"

using namespace std;

int main() {
    bool repeat = true;
    cout << "\n ***** Instrucciones *****" << endl;
    cout << "       ****************  \n" << endl;
    cout << "-Ingresar por terminal la expresion a calcular." << endl;
    cout << "-Si el numero es de mas de una cifra ingresarlo entre parentesis." << endl;
    cout << "-Si el numero es negativo ingresar el numero dentro de parentesis." << endl;
    cout << "-Ingresar la expresion sin espacios." << endl;
    cout << "Ejemplo de expresion valida, Para notacion polaca inversa (12)6-31+(-2)*/." << endl;
    cout << "Ejemplo de expresion valida, Para notacion polaca +*(19)2*1(21)." << endl;
    do {
        string validez;
        int opcion;
        cout << "\n ***** Opciones *****\n" << endl;
        cout << "1. Calcular una expresion en notacion polaca inversa." << endl;
        cout << "2. Calcular una expresion en notacion polaca." << endl;
        cout << "3. Finalizar programa." << endl;
        cout << "Elija una opcion:  ";
        cin >> validez;
        try {
            opcion = stoi(validez);
        }
        catch (invalid_argument) {
            cout << "Debiste elegir una opcion valida. ";
            break;
        }
        switch (opcion) {
            case 3: {
                repeat = false;
                cout << "\nPrograma finalizado. " << endl;
                break;
            }
            case 1: {
                string cosa;
                cout << "Ingrese la expresion: ";
                cin >> cosa;
                vector<string> vector = operation(cosa);
                cout << " El Resultado es:  " << calculatePI(vector).substr(0, 4) << endl;
                break;
            }
            case 2: {
                string cosa;
                cout << "Ingrese la expresion: ";
                cin >> cosa;
                vector<string> vector = operation(cosa);
                cout << " El Resultado es:  " << calculateP(vector).substr(0, 4) << endl;
                break;
            }
        }
    } while (repeat);
    return 0;
}
