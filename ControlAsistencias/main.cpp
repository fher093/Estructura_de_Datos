#include <iostream>  
#include "Estudiante.h" // Trae la lógica de los alumnos
#include "Asistencia.h" // Trae la lógica de las faltas/asistencias
using namespace std; 

int main(){
    int opcion; 
    // Creamos los objetos que manejan la lógica de cada cosa
    GestionEstudiante gestion;
    GestionAsistencia asistencia; 
    
    do {
        // --- Interfaz del Menú ---
        cout << "\n--MENU--" << endl; 
        cout << "1-Registar estudiante" << endl;
        cout << "2-Eliminar estudiante" << endl; 
        cout << "3-Ver lista de estudiantes" << endl; 
        cout << "4-Tomar Lista" << endl;
        cout << "5-Ver Lista de asistencia" << endl;  
        cout << "6-Buscar Estudiante" << endl;
        cout << "7-Modificar asistencia" << endl;  
        cout << "8-Generar reporte" << endl;
        cout << "9-SALIR" << endl;  
         
        cin >> opcion; // Captura la elección del usuario
        
        switch(opcion){
            
            case 1: {
                cout << "REGISTRO DE ESTUDIANTES" << endl;
                int cantidad;
                cout << "Cuantos estudiantes desea registrar? ";
                cin >> cantidad;
                cin.ignore(); // Limpia el buffer (evita que el siguiente getline se salte)

                for(int i = 0; i < cantidad; i++){
                    string nombre;
                    cout << "Ingrese nombre del estudiante " << i+1 << ": ";
                    getline(cin, nombre); // Lee el nombre completo con espacios
                    gestion.registarEstudiante(nombre); // Lo guarda en el sistema
                }
                break;
            }
            
            case 2: {
                cout << "ELIMINAR ESTUDIANTE" << endl;
                gestion.listarEstudiantes(); // Muestra quiénes hay para saber a quién borrar
                cout << "Como desea eliminar?" << endl;
                cout << "1-Por ID  2-Por Nombre: ";
                int opEliminar;
                cin >> opEliminar;
            
                if(opEliminar == 1){
                    int id;
                    cout << "Ingrese ID a eliminar: ";
                    cin >> id;
                    gestion.eliminarEstudiante(id); // Borra usando el número de ID
                } else if(opEliminar == 2){
                    string nombre;
                    cout << "Ingrese nombre a eliminar: ";
                    cin.ignore(); 
                    getline(cin, nombre);
                    gestion.eliminarEstudiantePorNombre(nombre); // Borra buscando el texto
                } else {
                    cout << "Opcion invalida." << endl;
                }
                break;              
            }
            
            case 3: {
                cout << "LISTA DE ESTUDIANTES" << endl; 
                gestion.listarEstudiantes(); // Solo imprime la lista actual
                break;
            }
            
            case 4: {
                cout << "TOMAR LISTA" << endl;
                // Le pasamos 'gestion' para que sepa a qué alumnos pasarles falta
                asistencia.tomarLista(gestion); 
                break;
            }
            
            case 5: {
                cout << "VER LISTA DE ASISTENCIA" << endl;
                asistencia.verAsistencia(gestion); 
                break;
            }
            
            case 6: {
                cout << "BUSCAR ESTUDIANTE" << endl;
                string nombre;
                cout << "Ingrese nombre a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                gestion.buscarEstudiante(nombre); // Busca si el alumno está registrado
                break;
            }
            
            case 7: {
                cout << "MODIFICAR ASISTENCIA" << endl;
                asistencia.modificarAsistencia(gestion); // Para corregir errores en la lista
                break;
            }
            
            case 8: {
                cout << "GENERAR REPORTE" << endl;
                asistencia.generarReporte(gestion); // Resumen de faltas y asistencias
                break;
            }
             
            case 9: {
                cout << "SALIENDO DEL PROGRAMA........" << endl; 
                break;
            }

            default: {
                cout << "Opcion invalida." << endl; // Por si el usuario mete un número que no es
                break;
            }
        }   
        
    } while(opcion != 9); // Se repite el menú mientras no elijan salir
    
    return 0;
}
