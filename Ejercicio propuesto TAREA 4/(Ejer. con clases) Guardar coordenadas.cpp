/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 17/03/2019
*/
#include <iostream>
#include <windows.h>
using namespace std;

class Cola{
//por principios de encapsulamiento las propiedades de una clase siempre seran privadas.
	private:
		//ATRIBUTOS DE LA CLASE
	//estructura O tipo de datos de la clase.
		class Nodo{
			public:
				int x;
				int y;
				int z;
				//puntero que apunta al siguiente nodo.
				Nodo *sig;	
		};
		Nodo *raiz;//ultimo elemento que ingreso a la cola
		Nodo *fondo;//primer elemento que ingreso a la cola
		//METODOS DE LA CLASE
	public:
		Cola();//constructor de la clase. Se ejecuta cuando se crea una instancia(o se crea un objeto) de una clase
		~Cola();//destructor de la clase
		void insertar(int x, int y, int z);
		int extraer();//esta en int porque retorna un valor entero al main, es decir manda al main el numero que se extrajo
		void imprimir();
		void promedio();
		bool vacia();//metodo para ver si la cola esta vacia o no
};
//llamando a la clase :: (los dos puntos son una referencia a la misma clase) metodo al que se le quiere llamar
Cola::Cola(){
	//cada vez que se cree un objeto, raiz y fondo estaran seteados por default a NULL (nulo)
	raiz = NULL;
	fondo = NULL;
}

//llamamos al metodo destructor de la clase
Cola::~Cola(){
	//puntero de tipo nodo  apuntando al ultimo elemento de la cola
	Nodo *reco = raiz;
	//puntero auxiliar
	Nodo *bor;
	//ver si hay elementos o no en la cola
	while(reco != NULL){
		//bor apuntara a reco
		bor = reco;
		//pasamos reco al siguiente nodo
		reco = reco->sig;
		//y eliminamos bor
		delete bor;
	}
}

void Cola::insertar(int x, int y, int z){
	//nodo auxiliar que permite ir colocando los datos en la cola
	Nodo *nuevo;
	//le diremos ahora a nuevo que nos reserve un espacio en memoria es decir que nos aparte un NODO
	nuevo = new Nodo();
	//accedemos a la parte destinada a "x" "y" y "z" del nodo para guardar los datos
	nuevo->x = x;
	nuevo->y = y;
	nuevo->z = z;
	//accedemos a la parte destinada a siguiente y lo igualamos a NULL
	nuevo->sig = NULL;
	
	if(vacia()){

		raiz = nuevo;
		fondo = nuevo;
	}
	
	else{
		fondo->sig = nuevo;
		fondo = nuevo;
	}
}

int Cola::extraer(){
	if(!vacia()){
		int coord1 = raiz->x;
		int coord2 = raiz->y;
		int coord3 = raiz->z;
		
		Nodo *bor = raiz;
		if(raiz == fondo){
			raiz = NULL;
			fondo = NULL;
		}
		else{
			raiz = raiz->sig;
		}
		delete bor;
		return coord1, coord2, coord3;
	}
	else{
		return -1;
	}
}

void Cola::imprimir(){
	int count = 0;
	Nodo *reco = raiz;
	cout<<"Listado de las coordenadas almacenadas en la cola: "<<endl;
	while(reco != NULL){
		cout<<"COORDENADA X: "<<reco->x<<endl;;
		cout<<"COORDENADA Y: "<<reco->y<<endl;
		cout<<"COORDENADA Z: "<<reco->z<<endl;
		reco = reco->sig;
		cout<<"-------------------"<<endl;
		count++;
	}
	//mostrando el espacio ocupado en memoria por los nodos
	cout<<"Espacio ocupado en memoria hasta ahora: "<<count*12<<" bytes"<<endl;
	cout<<endl;
}

//funcion de la clase que se encarga de promediar las coordenadas
void Cola::promedio(){
	Nodo *reco = raiz;
	double counter = 0;
	double aux1, aux2, aux3;
	double resx, resy, resz;
	cout<<"Promedio de las coordenadas almacenadas en la cola: "<<endl;
	
	while(reco != NULL){
		aux1 = aux1 + reco->x;
		aux2 = aux2 + reco->y;
		aux3 = aux3 + reco->z;
		reco = reco->sig;
		counter++;//contador que da la longitud de la cola
	}
		resx = (aux1/counter);
		resy = (aux2/counter);
		resz = (aux3/counter);	
	cout<<"COORDENADA X: "<<resx<<endl;;
	cout<<"COORDENADA Y: "<<resy<<endl;
	cout<<"COORDENADA Z: "<<resz<<endl;
	aux1 = 0;
	aux2 = 0;
	aux3 = 0;
	cout<<endl;
	cout<<endl;
}

bool Cola::vacia(){
	if(raiz == NULL){
		return true;
	}
	else{
		return false;
	}
}

//funcion menu para pedir las opciones en la consola
void menu(){
	cout<<"Sistema de registro de coordenadas."<<endl;
	cout<<"Ingrese una opcion."<<endl;
    cout<<"1 - Insertar nuevas coordenadas."<<endl;
    cout<<"2 - Mostrar las coordenas almacenadas."<<endl;
    cout<<"3 - Eliminar un grupo de coordenas de la cola."<<endl;
    cout<<"4 - Mostrar promedio general de cada coordenada almacenada."<<endl;
    cout<<"5 - Salir del programa..."<<endl;
}

int main(){
	int opc;
	int datox, datoy, datoz;
	Cola *cola1 = new Cola();
	do{
		//llamada a la funcion menu
		menu();
		cin>>opc;
		switch(opc){
			//INSERTAR COORDENADAS
			case 1:
				cout<<"Ingresa la coordenada X: "<<endl;
				cin>>datox;
				cout<<"Ingresa la coordenada Y: "<<endl;
				cin>>datoy;
				cout<<"Ingresa la coordenada Z: "<<endl;
				cin>>datoz;
				
				cola1->insertar(datox, datoy, datoz);
			break;
			
			//MOSTRAR COORDENADAS
			case 2:
				cola1->imprimir();
			break;
			
			//ELIMINAR COORDENADAS
			case 3:
				cola1->extraer();
			break;
			
			//PROMEDIO COORDENADAS
			case 4:
				cola1->promedio();
			break;
			
			//SALIR DEL PROGRAMA
			case 5:
			break;
		}
		system("pause");
		system("cls");
	}while(opc!=5);
	delete cola1;
	return 0;
}
