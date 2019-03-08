/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 08/03/2019
*/
#include <iostream>
#include <queue>//para trabajar con colas
#include <string.h>//para usar strlen y leer la longitud del numero de ticket

using namespace std;
//estructura que guarda los datos del ahorrante
struct cuenta{
	char ticket[5];
	int numCuenta;
	int edad;
};
//menu que se muestra en pantalla para pedir las opciones
void menu(){
	cout<<"Sistema de almacenamiento de ahorrantes de Banco Rojo."<<endl;
	cout<<"Ingrese una opcion."<<endl;
    cout<<"1 - Agregar un nuevo ahorrante."<<endl;
    cout<<"2 - Eliminar un ahorrante"<<endl;
    cout<<"3 - Mostrar Clientes"<<endl;
    cout<<"4 - Salir"<<endl;
}
//funcion principal main
int main(){
	system("color 6B");
	int opcion;
	int cant;
	int c = 1;
	queue<cuenta> colita;
	cuenta aux;
	cuenta *ptr;

	do{	
	menu();
	cin>>opcion;
		switch(opcion){
			//AGREGAR AHORRANTE
			case 1:
				cout<<"Cuantos ahorrantes desea ingresar?.."<<endl;
				cin>>cant;
				
				for(int i=1; i<=cant; i++){
					//validamos la longitud del numero del ticket
					do{
						cout<<"Ingrese el numero de ticket: "<<endl;
						cin>>aux.ticket;
					}while(strlen(aux.ticket)!=4);
					
					cout<<"Ingrese el numero de cuenta del ahorrante: "<<endl;
					cin>>aux.numCuenta;
					cout<<"Ingrese la edad del ahorrante: "<<endl;	
					cin>>aux.edad;
					colita.push(aux);
				}
			break;
			
			//ELIMINAR AHORRANTE
			case 2:
				if(colita.empty() == true ){
    				cout<<"La lista esta vacia..."<<endl;
				}
				else{
					colita.pop();
					cout<<"El ultimo cliente ingresado ha sido eliminado exitosamente de la lista..."<<endl;
   				}	
			break;
			
			//MOSTRAR AHORRANTES
			case 3:
				if(colita.empty() == true){
					cout<<"La lista esta vacia..."<<endl;
				}
				else{
					ptr = &colita.front();
					for(int i=1; i<=colita.size(); i++){
						aux = *ptr;
						cout<<"CLIENTE "<<i<<endl;
						cout<<aux.ticket<<endl;
						cout<<aux.numCuenta<<endl;
						cout<<aux.edad<<endl;
						ptr++;
					}
				}
			break;
			//SALIR DEL PROGRAMA
			case 4:
			break;		
		}
		system("pause");  
		system("cls");
	}while(opcion != 4);
	return 0; 
	
}
