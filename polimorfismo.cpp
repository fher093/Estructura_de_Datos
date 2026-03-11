#include <iostream>
using namespace std; 

class Animal{
	public: 
		virtual void hacerSonido(){
			cout<<"El animal hace un sonido" << endl;
		}
}; 

class Perro : public Animal{
	public:
	 void hacerSonido() override {
		cout << "guau guau " << endl; 
	}
}; 

class Gato : public Animal{
	public: 
	 void hacerSonido() override {
		cout << "miau miau " << endl; 
	}
}; 

int main(){
	Animal* a1; 
	
	Perro p; 
	Gato g; 
	
	a1= &p;
	a1->hacerSonido(); 
	
	
	a1= &g;
	a1->hacerSonido();   
	
	return 0;
}
