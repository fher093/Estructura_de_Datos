#ifndef GESTION_ESTUDIANTE_H    
#define GESTION_ESTUDIANTE_H 
#include <iostream> 
#include <vector> // Para usar listas dinámicas (vectores)
#include <string>  
using namespace std;

// La "ficha" de cada alumno
struct Estudiante{
    int id;
    string nombre;
    string asistencia[5]; // Un array de 5 espacios para Lunes a Viernes ("a", "f" o "-")
};  
 
class GestionEstudiante{
    private: 
        vector<Estudiante> lista; // Aquí se guardan todos los alumnos como en una lista de Excel
    
    public: 
    
        // Función para meter gente nueva al sistema
        void registarEstudiante(string _nombre){
            Estudiante nuevo;
            nuevo.id = lista.size() + 1; // El ID es el tamaño actual + 1 (autoincremental sencillo)
            nuevo.nombre = _nombre;
            
            // Cuando recién entra, le ponemos "-" en todos los días (vacío)
            for(int i = 0; i < 5; i++){
                nuevo.asistencia[i] = "-";
            }
            lista.push_back(nuevo); // Lo mete al final del vector
            cout << "Estudiante registrado con exito" << endl;
        }  
        
        // Borra a alguien usando su número de ID
        void eliminarEstudiante(int id){
            for(int i = 0; i < (int)lista.size(); i++){
                if(lista[i].id == id){
                    lista.erase(lista.begin() + i); // Borra la posición específica
                    cout << "Estudiante eliminado." << endl;
                    return; // Sale de la función de una vez
                }
            }
            cout << "ID no encontrado." << endl;
        } 
        
        // Lo mismo, pero busca por el nombre exacto
        void eliminarEstudiantePorNombre(string nombre){
            for(int i = 0; i < (int)lista.size(); i++){
                if(lista[i].nombre == nombre){
                    lista.erase(lista.begin() + i);
                    cout << "Estudiante eliminado." << endl;
                    return;
                }
            }
            cout << "Estudiante no encontrado." << endl;
        }       
        
        // Recorre el vector y muestra a todos los registrados
        void listarEstudiantes(){
            if(lista.empty()){
                cout << "La lista esta vacia" << endl; 
                return;
            } 
            cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
            for (int i = 0; i < (int)lista.size(); i++) {
                cout << "ID: " << lista[i].id << " | Nombre: " << lista[i].nombre << endl;
            }
        } 
        
        // Busca a alguien y muestra su info si lo encuentra
        void buscarEstudiante(string nombre){
            bool encontrado = false;
            for(int i = 0; i < (int)lista.size(); i++){
                if(lista[i].nombre == nombre){
                    cout << "ID: " << lista[i].id << " | Nombre: " << lista[i].nombre << endl;
                    encontrado = true;
                }
            }
            if(!encontrado){
                cout << "Estudiante no encontrado." << endl;
            }
        }

        // ¡Clave! Esta función suelta la lista completa (por referencia)
        // Se usa para que la clase Asistencia pueda entrar y modificar los datos
        vector<Estudiante>& getLista(){
            return lista;
        }
};
#endif
