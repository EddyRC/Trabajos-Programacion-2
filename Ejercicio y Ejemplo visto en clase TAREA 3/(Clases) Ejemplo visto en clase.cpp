/*
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 14/03/2019
*/
#include <iostream>
#include <conio.h>

using namespace std;

class Paciente{
    private:
    	int cor;
    	char nom[20];
    	char ape[20];
		int edad;
		char s[2]; 
		char ec[50];
    public:
    	Paciente();
    	void Mostrar();
    	void Pedir();
    	~Paciente();
};

Paciente::Paciente(){
}

Paciente::~Paciente(){
}

void Paciente::Mostrar(){
   cout<<"-------"<<endl;
   cout<<cor<<endl;
   cout<<nom<<endl;
   cout<<ape<<endl;
   cout<<edad<<endl;
   cout<<s<<endl;
   cout<<ec<<endl;
   cout<<"-------"<<endl;
}

void Paciente::Pedir(){
  cout<<"Numero Correlativo de paciente:"<<endl;
  cin>>cor;
  cout<<"Nombre del paciente:"<<endl;
  cin>>nom;
  cout<<"Apellido del paciente:"<<endl;
   cin>>ape;
  cout<<"Edad del paciente:"<<endl;
  cin>>edad;
  cout<<"Sexo del paciente:"<<endl;
   cin>>s;
  cout<<"Enfermedad Cronica:"<<endl;
   cin>>ec;
}

int main() {
	Paciente *p1;
	Paciente *p2;
	p1=new Paciente();
	p1->Pedir();
	p1->Mostrar();
	p2=new Paciente();
	p2->Pedir();
	p2->Mostrar();
	getch();
	return 0;

}
