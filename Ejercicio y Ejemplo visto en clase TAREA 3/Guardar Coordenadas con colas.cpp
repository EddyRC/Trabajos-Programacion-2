/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 14/03/2019
*/
#include <iostream>
#include <queue>//para usar colas
#include <windows.h>

using namespace std;

//estructura que guarda las coordenadas solicitadas al usuario
struct coordenadas{
	int cx;
	int cy;
	int cz;
};

//funcion menu para pedir las opciones en la consola
void menu(){
	cout<<"Sistema de registro de coordenadas."<<endl;
	cout<<"Ingrese una opcion."<<endl;
    cout<<"1 - Insertar nuevas coordenadas."<<endl;
    cout<<"2 - Mostrar las coordenas almacenadas."<<endl;
    cout<<"3 - Mostrar promedio general de cada coordenada almacenada."<<endl;
    cout<<"4 - Salir del programa..."<<endl;
}

//funcion principal main
int main() {
	//creamos una cola de tipo coordenadas
	queue<coordenadas> cola;
	coordenadas aux;//variable auxiliar de tipo coordenadas
	coordenadas *punt;//puntero de tipo coordenadas
	int opc;

	do{
		//hacemos la llamda al menu
		menu();
		cin>>opc;
		system("cls");
		//hacemos el debido procesamiento de las opciones el en menu siguiente
		switch(opc){
			//INSERTAR NUEVAS COORDENADAS A LA COLA
			case 1:
				cout<<"Ingrese coordenada X :"<<endl;
				cin>>aux.cx;
				cout<<"Ingrese coordenada Y :"<<endl;
				cin>>aux.cy;
				cout<<"Ingrese coordenada Z :"<<endl;
				cin>>aux.cz;
				cola.push(aux);
				cout<<"Coordenadas almacenadas con exito!..."<<endl;
				system("pause");
				system("cls");
			break;
			
			//MOSTRAR COORDENADAS ALMACENDAS EN LA COLA
			case 2:
				if(cola.empty() == true){
					cout<<"La lista de coordenadas esta vacia..."<<endl;
				}
				else{
					punt = &cola.front();
					for(int i=1; i<=cola.size(); i++){
						aux = *punt;
						cout<<"Coordenada X: "<<aux.cx<<endl;
						cout<<"Coordenada Y: "<<aux.cy<<endl;
						cout<<"Coordenada Z: "<<aux.cz<<endl;
						cout<<endl;
						punt++;
					}
					//MOSTRAMOS EL ESPACIO OCUPADO EN MEMORIA
					cout<<"Espacio ocupado en memoria hasta ahorita: "<<cola.size()*12<<" bytes"<<endl;
				}
				system("pause");
				system("cls");
			break;
			
			//CALCULAR EL PROMEDIO DE LAS COORDENADAS
			case 3:
				float promx;
				float promy;
				float promz;
				punt = &cola.front();//PUNTERO AL INICIO DE LA COLA
				for(int i=0; i<=cola.size(); i++){
					aux = *punt;
					//LE SUMAMOS A PROM LOS INICIOS DE CADA NODO
					promx += aux.cx;
					promy += aux.cy;
					promz += aux.cz;
					punt++;
				}
				//MOSTRAMOS EN PANTALLA EL PROMEDIO
				cout<<"Promedio de Coordenadas X = "<<promx/cola.size()<<endl;
				cout<<"Promedio de Coordenadas Y = "<<promy/cola.size()<<endl;
				cout<<"Promedio de Coordenadas Z = "<<promz/cola.size()<<endl;
				//IGUALAMOS A CERO LAS VARIABLES DE PROM PARA QUE NO AUMENTEN CADA VEZ QUE SE EJECUTE EL FOR
				promx=0;
				promy=0;
				promz=0;
				system("pause");
				system("cls");
			break;
			case 4:
			break;
		}
		system("cls");
	}while(opc!=4);
	
	return 0;
}
