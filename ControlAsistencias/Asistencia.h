#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include <iostream>
#include <string>
#include <iomanip>  // Para que las tablas salgan alineadas y bonitas
#include "Estudiante.h"
using namespace std;

class GestionAsistencia{
	private:
		// Array fijo con los días de la semana para no escribirlos cada vez
		string dias[5] = {"lunes", "martes", "miercoles", "jueves", "viernes"};

	public:

		// Función para marcar quién vino y quién no en un día específico
		void tomarLista(GestionEstudiante& gestion){
			// Traemos la lista de estudiantes real usando el getter que definiste antes
			vector<Estudiante>& lista = gestion.getLista();

			if(lista.empty()){
				cout << "No hay estudiantes registrados." << endl;
				return;
			}

			// Menú para elegir qué día es hoy
			cout << "Seleccione el dia:" << endl;
			for(int i = 0; i < 5; i++){
				cout << i+1 << "-" << dias[i] << endl;
			}
			int diaOpcion;
			cin >> diaOpcion;

			if(diaOpcion < 1 || diaOpcion > 5){
				cout << "Dia invalido." << endl;
				return;
			}

			int diaIndex = diaOpcion - 1; // Restamos 1 porque los arrays empiezan en 0
			cout << "\n--- TOMANDO LISTA: " << dias[diaIndex] << " ---" << endl;

			// Recorremos a todos los alumnos y preguntamos uno por uno
			for(int i = 0; i < (int)lista.size(); i++){
				string estado;
				cout << "Estudiante: " << lista[i].nombre << " (a = asiste / f = falta): ";
				cin >> estado;
				
				// Filtro para que no metan cualquier letra
				while(estado != "a" && estado != "f"){
					cout << "Ingrese solo 'a' o 'f': ";
					cin >> estado;
				}
				// Guardamos el estado en el día correspondiente de ese estudiante
				lista[i].asistencia[diaIndex] = estado;
			}
			cout << "Lista tomada correctamente." << endl;
		}

		// Imprime una tabla con todos los nombres y sus marcas ("a", "f", "-")
		void verAsistencia(GestionEstudiante& gestion){
			vector<Estudiante>& lista = gestion.getLista();

			if(lista.empty()){
				cout << "No hay estudiantes registrados." << endl;
				return;
			}

			// Encabezado de la tabla usando setw (width) para que todo cuadre
			cout << "\n--- LISTA DE ASISTENCIA ---" << endl;
			cout.width(20); cout << left << "Nombre";
			for(int d = 0; d < 5; d++){
				cout.width(12); cout << left << dias[d];
			}
			cout << endl;

			// Imprime cada fila: Nombre y luego sus 5 estados
			for(int i = 0; i < (int)lista.size(); i++){
				cout.width(20); cout << left << lista[i].nombre;
				for(int d = 0; d < 5; d++){
					cout.width(12); cout << left << lista[i].asistencia[d];
				}
				cout << endl;
			}
		}

		// Por si alguien llegó tarde o te equivocaste de tecla
		void modificarAsistencia(GestionEstudiante& gestion){
			vector<Estudiante>& lista = gestion.getLista();

			if(lista.empty()){
				cout << "No hay estudiantes registrados." << endl;
				return;
			}

			gestion.listarEstudiantes(); // Mostramos quiénes hay para ver el ID
			int id;
			cout << "Ingrese ID del estudiante a modificar: ";
			cin >> id;

			// Buscamos la posición del estudiante en el vector
			int index = -1;
			for(int i = 0; i < (int)lista.size(); i++){
				if(lista[i].id == id){
					index = i;
					break;
				}
			}

			if(index == -1){
				cout << "ID no encontrado." << endl;
				return;
			}

			// Preguntamos qué día quieres cambiar
			cout << "Seleccione el dia a modificar:" << endl;
			for(int i = 0; i < 5; i++){
				cout << i+1 << "-" << dias[i] 
				     << " (actual: " << lista[index].asistencia[i] << ")" << endl;
			}
			int diaOpcion;
			cin >> diaOpcion;

			if(diaOpcion < 1 || diaOpcion > 5){
				cout << "Dia invalido." << endl;
				return;
			}

			string estado;
			cout << "Nuevo valor (a = asiste / f = falta): ";
			cin >> estado;
			while(estado != "a" && estado != "f"){
				cout << "Ingrese solo 'a' o 'f': ";
				cin >> estado;
			}

			// Sobrescribimos el dato anterior
			lista[index].asistencia[diaOpcion - 1] = estado;
			cout << "Asistencia modificada correctamente." << endl;
		}

		// El resumen final con cálculos matemáticos
		void generarReporte(GestionEstudiante& gestion){
		    vector<Estudiante>& lista = gestion.getLista();
		
		    if(lista.empty()){
		        cout << "No hay estudiantes registrados." << endl;
		        return;
		    }
		
		    cout << "\n--- REPORTE DE ASISTENCIA ---" << endl;
		    cout.width(20); cout << left << "Nombre";
		    cout.width(12); cout << left << "Asistencias";
		    cout.width(12); cout << left << "Faltas";
		    cout.width(12); cout << left << "Porcentaje"; 
		    cout << endl;
		
		    for(int i = 0; i < (int)lista.size(); i++){
		        int asistencias = 0, faltas = 0;
		        // Contamos cuántas 'a' y cuántas 'f' tiene el alumno
		        for(int d = 0; d < 5; d++){
		            if(lista[i].asistencia[d] == "a") asistencias++;
		            else if(lista[i].asistencia[d] == "f") faltas++;
		        }
		
		        // Calculamos el porcentaje (asistencias / total de días * 100)
		        double porcentaje = (asistencias * 100.0) / 5; 
		
		        cout.width(20); cout << left << lista[i].nombre;
		        cout.width(12); cout << left << asistencias;
		        cout.width(12); cout << left << faltas;
		        // setprecision(1) hace que salga con un solo decimal (ej: 80.0%)
		        cout.width(12); cout << left << fixed << setprecision(1) << porcentaje << "%"; 
		        cout << endl;
		    }
		}
};
#endif
