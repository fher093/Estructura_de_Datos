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
		int kilometraje; 
	//METODO APLICADO POLIMORFISMO
		void mostrarInfo() override {   
			cout<<"INFORMACION AUTO"<<endl;
			Vehiculo::mostrarInfo();
			cout<< "Kilometraje: " <<kilometraje<< endl;  
			
		}	
};  


//CLASE MOTO HEREDA DE VEHICULO
class Moto : public Vehiculo{
	public: 
	//ATRIBUTOS
		string frenos; 
	//METODO APLICADO POLIMORFISMO
		void mostrarInfo() override { 
			cout<<"INFORMACION MOTO"<<endl;
			Vehiculo::mostrarInfo();
			cout<< "Tipo de frenos: " <<frenos << endl; 
			
		}	
};  

int main(){ 

	//INSTANCIAS DE VEHICULO
	Auto a; 
	Moto m;  
	//ASIGNACION DE VALORES	
	a.marca="Chevolet"; 
	a.modelo="SUV";
	a.kilometraje = 12000;
	//IMPRIMIR INFORMACION
	a.mostrarInfo(); 
	
	//ASIGNACION DE VALORES
	m.marca = "Honda"; 
	m.modelo = "Deportivo";
	m.frenos = "Disco"; 
	
	//IMPRIMIR INFORMACION
	m.mostrarInfo();   
	
	return 0;
}


