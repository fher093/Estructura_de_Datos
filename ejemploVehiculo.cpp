#include <iostream> 
using namespace std; 

class Vehiculo{ //CLASE PADRE VEHICULO
	public: 
	//ATRIBUTOS
		string marca; 
		string modelo; 
	//METODO PRINCIPAL	
		virtual void mostrarInfo(){
			cout << "Marca: " << marca << endl; 
			cout << "Modelo: " << modelo << endl; 
		}
}; 
//CLASE AUTO HEREDA DE VEHICULO
class Auto : public Vehiculo{
	public:  
	//ATRIBUTOS
		int numeroPuertas; 
	//METODO APLICADO POLIMORFISMO
		void mostrarInfo() override {   
			cout<<"--AUTO--"<<endl;
			Vehiculo::mostrarInfo();
			cout<< "Numero de puertas: " <<numeroPuertas<< endl; 
		}	
}; 

//CLASE MOTO HEREDA DE VEHICULO
class Moto : public Vehiculo{
	public: 
	//ATRIBUTOS
		int cilindraje; 
	//METODO APLICADO POLIMORFISMO
		void mostrarInfo() override { 
			cout<<"--MOTO--"<<endl;
			Vehiculo::mostrarInfo();
			cout<< "Cilindraje: " <<cilindraje <<" cc"<< endl; 
		}	
};  

int main(){ 

	//INSTANCIAS DE VEHICULO
	Auto a; 
	Moto m;  
	//ASIGNACION DE VALORES	
	a.marca="Chevolet"; 
	a.modelo="SUV";
	a.numeroPuertas = 5;
	//IMPRIMIR INFORMACION
	a.mostrarInfo(); 
	
	//ASIGNACION DE VALORES
	m.marca = "Honda"; 
	m.modelo = "Deportivo";
	m.cilindraje = 150; 
	
	//IMPRIMIR INFORMACION
	m.mostrarInfo();   
	
	return 0;
}


