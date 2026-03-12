//vector de estrucutura   
//Un vector de estructuras en C++ es una colección dinámica 
//(usando std::vector) donde cada elemento es una estructura (struct).
#include <iostream>  
#include <vector> //Importa la estructura de datos "Vector", que es un arreglo dinámico
#include <string> // Permite usar el tipo de dato string para cadenas de texto.
using namespace std; 

//definimos una estructura  
struct Estudiante{ 
	string nombre; 
	int edad; 
	double promedio; 
};   

//crear el vector  

int main(){
	//crear el vector de estrucutra  
	vector<Estudiante> alumnos; // este vector almacenara datos de tipo estudiante   
	
	//Agregar elementos con el metodo push back propio de struct 
    alumnos.push_back({"Ana",  20, 9.5});
    alumnos.push_back({"Luis", 22, 8.3});
    alumnos.push_back({"María",19, 9.8});

    //Recorrer e imprimir con un for each
    for (const Estudiante& e : alumnos) {
        cout << e.nombre << " | Edad: " << e.edad
             << " | Promedio: " << e.promedio << endl;
    }

    return 0;
}



