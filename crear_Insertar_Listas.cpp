#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para insertar al inicio
void insertarInicio(Nodo* &lista, int n) {
    Nodo* nuevo_nodo = new Nodo(); // 1. Crear espacio en memoria
    nuevo_nodo->dato = n;          // 2. Asignar el dato
    nuevo_nodo->siguiente = lista; // 3. Apuntar al que antes era el primero
    lista = nuevo_nodo;            // 4. El nuevo nodo es ahora la cabeza
}

// Función para mostrar la lista
void mostrarLista(Nodo* lista) {
    Nodo* actual = lista; 
    while (actual != nullptr) {    // Recorrer hasta llegar al final
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    Nodo* lista = nullptr; // Lista inicialmente vacía

    insertarInicio(lista, 10);
    insertarInicio(lista, 20);
    insertarInicio(lista, 30);

    cout << "Elementos de la lista: ";
    mostrarLista(lista); // Salida: 30 -> 20 -> 10 -> NULL

    return 0;
}
