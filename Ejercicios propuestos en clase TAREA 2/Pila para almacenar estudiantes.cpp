/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 08/03/2019
*/

//EJERCICIO PROPUESTO EN CLASE: ALMACENAR ALUMNOS EN UNA PILA
#include <cstdlib>
#include <iostream>
#include <stack>//libreria utilizada para manejar pilas
using namespace std;

//estructura alumnos
struct alumnos{
	char due[8];
	char nombre[50];
	char apellido[50];
	char edad[3];	
};

stack<alumnos> pila;//pila de tipo alumno.....//declare estas variables aqui para que me las reconociera la funcion main
alumnos aux;//variable auxiliar de tipo alumno.
//funcion menu para pedir las opciones en la consola
void menu(){
	cout<<"Sistema de registro estudiantil Centro Escolar Sagrado Corazon."<<endl;
	cout<<"Ingrese una opcion."<<endl;
    cout<<"1 - Insertar nuevos alumnos a la lista."<<endl;
    cout<<"2 - Eliminar un alumno de la lista.\n(esta accion solo elimina el ultimo alumno ingresado)."<<endl;
    cout<<"3 - Mostrar los alumnos que estan en la lista."<<endl;
    cout<<"4 - Salir del programa..."<<endl;
}
//funcion para almacenar los alumnos
void almacenar(){
	int cant;
	cout<<"Cuantos alumnos desea almacenar en la lista: "<<endl;
	cin>>cant;
	for(int i=1; i<=cant; i++){
		cout<<"Ingrese el due del alumno: "<<endl;
		cin>>aux.due;
		cout<<"Ingrese el nombre del alumno: "<<endl;
		cin>>aux.nombre;
		cout<<"Ingrese el apellido del alumno: "<<endl;
		cin>>aux.apellido;
		cout<<"Ingrese la edad del alumno: "<<endl;
		cin>>aux.edad;
		pila.push(aux);
	}
}

//funcion principal main
int main(){
	system("color C7");
	alumnos *ptr;
    int opcion;
    
	do{
		menu();
    	cin>>opcion;
    
    	switch(opcion){
    		//almacenar un elemento en la pila
    		case 1:
		    	almacenar();
    		break;
    		
    		//eliminar elemento de la pila
    		case 2:
    			if(pila.empty() == true ){
    				cout<<"La lista esta vacia..."<<endl;
				}
				else{
					pila.pop();
					ptr = &pila.top();
					cout<<"Un alumno ha sido eliminado de la lista..."<<endl;
   				}
    		break;
    		
    		//mostrar los datos almacenados en la pila
    		case 3:
    			if(pila.empty() == true){
    				cout<<"La lista esta vacia..."<<endl;
				}
				else{
					ptr = &pila.top();
					    for(int i=1; i<=pila.size(); i++){
						    aux = *ptr;
						    cout<<"/-/-/-/-/-/-/-/-/-/"<<endl;
						    cout<<"ALUMNO "<<i<<endl;
						    cout<<aux.due<<endl;
						    cout<<aux.nombre<<endl;
						    cout<<aux.apellido<<endl;
						    cout<<aux.edad<<endl;
						    ptr--;
					    }
				}
    		break;
    		
    		//salir del programa
    		case 4:
    		break;
		}
        system("pause");  
		system("cls");
	}while(opcion != 4);
	
    return 0;
}
