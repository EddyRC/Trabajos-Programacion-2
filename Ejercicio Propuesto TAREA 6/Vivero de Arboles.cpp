/*
Programa realizado por: 
Edgar Antonio Reyes Ceron.
#Carnet: RC18050
PROGRAMACION II-2019

Ultima modificacion: 19/04/2019
*/

#include <iostream>
#include <queue>
#include <windows.h>
#include <string.h>
using namespace std;

void menu(){
	cout<<"Vivero de arboles"<<endl;
	cout<<"Ingrese una opcion: "<<endl;
    cout<<"1 - Agregar nuevo arbol."<<endl;
    cout<<"2 - Listar arboles en existencia."<<endl;
    cout<<"3 - Buscar un arbol."<<endl;
    cout<<"4 - Eliminar un arbol."<<endl;
    cout<<"5 - Salir al menu Principal."<<endl;
}

void menuA(){
	cout<<"Que tipo de Arboles almacenara?."<<endl;
	cout<<"Ingrese una opcion: "<<endl;
    cout<<"1 - Arboles Frutales."<<endl;
    cout<<"2 - Arboles Ornamentales."<<endl;
}

class Hoja 
{
	private:
		string forma ;
	public:
		Hoja(){}
		void setforma (string f)
		{
		 this ->forma = f;
		}
		string getforma ()
		{
		 return this ->forma;
		}
		~Hoja(){}
};

class Tallo 
{
	private:
		float longitud ;
	public:
		Tallo(){}
		void setlongitud(float l)//para la longitud del tallo
		{
			this->longitud = l;
		}
		float getlongitud(){
			return this->longitud;
		}
		~Tallo(){}
};

class Arbol 
{     
	private :
		string nomComun ;
		string nomCient ;
		string familia ;
		Hoja *hoja;  //agregacion
		Tallo *tallo; //composicion
	public  :
		//constructor de la clase
		Arbol (){
			this -> nomComun ;
			this -> nomCient ;
			this -> familia ;
			this -> hoja = new Hoja();
			this -> tallo = new Tallo ();
		}
	/**********************************************************/	
		void setnomComun (string a)
		{
			this->nomComun = a;
		}
		string getnomComun ()
		{
			return this ->nomComun;
		}
	/**********************************************************/
		void setnomCient (string b)
		{
			this ->nomCient =b;
		}
		string getnomCient ()
		{
			return this ->nomCient;
		}
	/**********************************************************/
		void setfamilia (string c)
		{
			this ->familia =c;
		}
		string getfamilia ()
		{
			return this ->familia;
		}
		
	/**********************************************************/
		void sethoja (string d)
		{
			hoja->setforma(d);
		}
		string gethoja ()
		{
			return hoja->getforma();
		}
	/**********************************************************/
		void settallo (float t)
		{
			tallo->setlongitud(t);
		}
		float gettallo ()
		{
			return tallo->getlongitud();
		}
		//destructor de la clase
		~Arbol(){}
};	
/////////////////////////////////////////////////////////////////	
class ArbolFrutal:public Arbol
{
		public:
		//constructor
		ArbolFrutal(){}
		//destructor
		~ArbolFrutal(){}
};
	
////////////////////////////////////////////////////////////////	
class ArbolOrnamental:public Arbol
{
	public:
		//constructor
		ArbolOrnamental(){}
		//destructor
		~ArbolOrnamental(){}
};
//**************************************************************/

//funcion principal main
int main ()
{
	system("color 9D");
	//cola de los arboles frutales
	queue<ArbolFrutal> colaAF;
	ArbolFrutal *punt1;//puntero
	ArbolFrutal aux1;//variable auxiliar
	
	//cola de los arboles ornamentales
	queue<ArbolOrnamental> colaAO;
	ArbolOrnamental *punt2;//puntero
	ArbolOrnamental aux2;//variable auxiliar
	
	ArbolFrutal *af = new ArbolFrutal ();
	ArbolOrnamental *ao = new ArbolOrnamental ();
	
	//variables en las que se guardaran los datos que se introduzcan
	string nombre;
	string nombreCien;
	string familia;
	string hoja;
	float tallo;
	
	string dato;//variable declarada para la parte de buscar
	int opcA;//variable de seleccion del menu principal
	int opcM;//variable de seleccion del menu de datos
	
	do{
		menuA();//llamada al menu principal
		cin>>opcA;
		system("cls");
		
		switch(opcA){
			//ARBOL FRUTAL
			case 1:
				do{
					menu();//llamada al menu de datos
					cin>>opcM;
					switch(opcM){
						//AGREGAR NUEVO ARBOL
						case 1:
							cout<<"Ingrese el nombre del arbol:"<<endl;
							cin>>nombre;
							af ->setnomComun(nombre);
							cout<<"Ingrese nombre cientifico del arbol:"<<endl;
							cin>>nombreCien;
							af ->setnomCient(nombreCien);
							cout<<"Ingrese la familia a la que pertenece el arbol:"<<endl;
							cin>>familia;
							af ->setfamilia(familia);
							cout<<"Introduzca la forma de la hoja: "<<endl;
							cin>>hoja;
							af ->sethoja(hoja);
							cout<<"Introduzca la longitud del tallo: "<<endl;
							cin>>tallo;
							af ->settallo(tallo);
							colaAF.push(*af);
						
							cout<<"Arbol almacenado satisfactoriamente!"<<endl;
							system("pause");
							system("cls");
						break;
						//MOSTRAR ARBOLES
						case 2:
							if(colaAF.empty() == true){
							cout<<"Esta vacio.."<<endl;
							}
							else{
								punt1 = &colaAF.front();
								cout<<"======ARBOLES FRUTALES========"<<endl;
								for(int i=1; i<=colaAF.size(); i++){
									aux1 = *punt1;
									cout<<"Nombre del Arbol: "<<aux1.getnomComun()<<endl;
									cout<<"Nombre Cientifico: "<<aux1.getnomCient()<<endl;
									cout<<"Familia: "<<aux1.getfamilia()<<endl;
									cout<<"Forma de la hoja: "<<aux1.gethoja()<<endl;
									cout<<"Longitud del tallo: "<<aux1.gettallo()<<" cm"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<endl;
									punt1++;
								}
							}
							system("pause");
							system("cls");	
						break;
						//BUSCAR ARBOLES
						case 3:
			    			if(colaAF.empty() == true){
								cout<<"Esta vacio.."<<endl;
							}
							else{
								cout<<"Ingrese el nombre del arbol para buscarlo: "<<endl;
								cin>>dato;
								punt1 = &colaAF.front();
								for(int i=1; i<=colaAF.size(); i++){
									aux1 = *punt1;
									if(dato == aux1.getnomComun()){
										cout<<"Encontrado..."<<endl;	
									}
									else{
										cout<<"No se ha podido encontrar."<<endl;
									}
								}
								punt1++;
							}
							punt1 = &colaAF.front();
						break;
						//ELIMINAR ARBOLES
						case 4:
							if(colaAF.empty() == true ){
			    				cout<<"Esta vacio.."<<endl;
							}
							else{
								colaAF.pop();
								cout<<"El ultimo arbol guardado ha sido eliminado exitosamente.."<<endl;
			   				}	
						break;
						//SALIR
						case 5:
						break;
					}
				}while(opcM!=5);
			break;
			
			//ARBOL ORNAMENTAL
			case 2:
				do{
					menu();//llamada al menu de opciones de datos
					cin>>opcM;
					switch(opcM){
						//AGREGAR NUEVO ARBOL
						case 1:
							cout<<"Ingrese el nombre del arbol:"<<endl;
							cin>>nombre;
							ao ->setnomComun(nombre);
							cout<<"Ingrese nombre cientifico del arbol:"<<endl;
							cin>>nombreCien;
							ao ->setnomCient(nombreCien);
							cout<<"Ingrese la familia a la que pertenece el arbol:"<<endl;
							cin>>familia;
							ao ->setfamilia(familia);
							cout<<"Introduzca la forma de la hoja: "<<endl;
							cin>>hoja;
							ao ->sethoja(hoja);
							cout<<"Introduzca la longitud del tallo: "<<endl;
							cin>>tallo;
							ao ->settallo(tallo);
							colaAO.push(*ao);
						
							cout<<"Arbol almacenado satisfactoriamente!"<<endl;
							system("pause");
							system("cls");
						break;
						//MOSTRAR ARBOLES
						case 2:
							if(colaAO.empty() == true){
							cout<<"Esta vacio.."<<endl;
							}
							else{
								punt2 = &colaAO.front();
								cout<<"======ARBOLES ORNAMENTALES======="<<endl;
								for(int i=1; i<=colaAO.size(); i++){
									aux2 = *punt2;
									cout<<"Nombre del Arbol: "<<aux2.getnomComun()<<endl;
									cout<<"Nombre Cientifico: "<<aux2.getnomCient()<<endl;
									cout<<"Familia: "<<aux2.getfamilia()<<endl;
									cout<<"Forma de la hoja: "<<aux2.gethoja()<<endl;
									cout<<"Longitud del tallo: "<<aux2.gettallo()<<" cm"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<endl;
									punt2++;
								}
							}
							system("pause");
							system("cls");
						break;
						//BUSCAR ARBOLES
						case 3:
							if(colaAO.empty() == true){
								cout<<"Esta vacio.."<<endl;
							}
							else{
								cout<<"Ingrese el nombre del arbol para buscarlo: "<<endl;
								cin>>dato;
								punt2 = &colaAO.front();
								for(int i=1; i<=colaAO.size(); i++){
									aux2 = *punt2;
									if(dato == aux2.getnomComun()){
										cout<<"Encontrado..."<<endl;
										cout<<"Nombre del Arbol: "<<aux2.getnomComun()<<endl;
										cout<<"Nombre Cientifico: "<<aux2.getnomCient()<<endl;
										cout<<"Familia: "<<aux2.getfamilia()<<endl;
										cout<<"Forma de la hoja: "<<aux2.gethoja()<<endl;
										cout<<"Longitud del tallo: "<<aux2.gettallo()<<" cm"<<endl;
										cout<<endl;	
									}
									else{
										cout<<"No se ha podido encontrar."<<endl;
									}
								}
								punt2++;
							}
							punt2 = &colaAO.front();
						break;
						//ELIMINAR ARBOLES
						case 4:
							if(colaAO.empty() == true ){
			    				cout<<"Esta vacio.."<<endl;
							}
							else{
								colaAO.pop();
								cout<<"El ultimo arbol guardado ha sido eliminado exitosamente.."<<endl;
			   				}
						break;
						//SALIR
						case 5:
						break;
					}
				}while(opcM!=5);
			break;
		}
	}while(opcA!=2);
	return 0;
}
