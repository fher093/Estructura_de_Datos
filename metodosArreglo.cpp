#include <iostream>
#include <vector>  
using namespace std;

// funcion para mostrar elementos
void mostrarArreglo(const vector<int>& miVector) {
    cout << "Contenido del arreglo: [ ";
    for (size_t i = 0; i < miVector.size(); i++) {
        cout << miVector[i] << " ";
    }
    cout << "]" << endl;
}

// funcion de busqueda
int buscarAsiento(const vector<int>& miVector, int numero) {  
    for (size_t i = 0; i < miVector.size(); i++) {
        if (miVector[i] == numero) return i; 
    } 
    return -1; 
}  

//funcion para insertar datos
void insertarTradicional(vector<int>& v, int pos, int valor) {
    if (pos < 0 || pos > v.size()) {
        cout << "Error: Posicion invalida para insertar." << endl;
        return;
    }
    v.push_back(0); 
    for (int i = v.size() - 1; i > pos; i--) {
        v[i] = v[i - 1];
    }
    v[pos] = valor;
    cout << "Asiento " << valor << " insertado en indice " << pos << endl;
}

//funcion para eliminar datos
void eliminarTradicional(vector<int>& v, int pos) {
    if (pos < 0 || pos >= v.size()) {
        cout << "Error: Posicion invalida para eliminar." << endl;
        return;
    }
    for (int i = pos; i < v.size() - 1; i++) {
        v[i] = v[i + 1];
    }
    v.pop_back();
    cout << "Elemento en indice " << pos << " eliminado." << endl;
}

int main() { 
    vector<int> array = {9, 12, 25, 16, 22, 19, 35, 26, 45};
    
    //imprimir arreglo
    mostrarArreglo(array);

    //insertar nuevo dato 
    insertarTradicional(array, 2, 100);
    mostrarArreglo(array);

    // eliminar dato
    eliminarTradicional(array, 4);
    mostrarArreglo(array);

    //buscar elemento
    int numeroAsiento;
    cout << "\n--- BUSQUEDA DE ASIENTO ---" << endl;
    cout << "Ingresa el numero que deseas localizar: ";
    cin >> numeroAsiento;

    int resultado = buscarAsiento(array, numeroAsiento);
    
    if (resultado != -1) {
        cout << " El numero " << numeroAsiento << " se encuentra en el indice: " << resultado << endl;
    } else {
        cout << "El numero " << numeroAsiento << " no existe en el arreglo actual." << endl;
    }

    return 0;
}
