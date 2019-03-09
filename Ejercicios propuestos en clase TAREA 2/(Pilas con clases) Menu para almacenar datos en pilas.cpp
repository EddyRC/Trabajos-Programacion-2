/*
Programa modificado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 08/03/2019
*/
#include <iostream>

using namespace std;

class Pila {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

Nodo *raiz;

public:
    Pila();
    ~Pila();
    void buscar();
    void insertar(int x);
    int extraer();
    void imprimir();
};

Pila::Pila(){
    raiz = NULL;
}

void Pila::insertar(int x){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    if (raiz == NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void Pila::imprimir(){
    Nodo *reco = raiz;
    cout << "Listado de todos los elementos de la pila.\n";
    while (reco != NULL){
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}

int Pila::extraer(){
    if (raiz != NULL){
        int informacion = raiz->info;
        Nodo *bor = raiz;
        raiz = raiz->sig;
        delete bor;
        return informacion;
    }
    else{
        cout<<"No hay mas datos en la pila..."<<endl;
    }
}

//funcion implementada para buscar datos
void Pila::buscar(){
	
	//verificamos si el nodo contiene datos
	if (raiz != NULL){
		//si tiene datos pasaremos a pedir el dato a buscar
		int buscardatos;
	    cout<<"Ingrese dato a buscar"<<endl;
	    cin>>buscardatos;
	    
	    //comparamos el dato que ingreso con el primer dato del nodo
	    if(buscardatos == raiz->info){ 
	    	//lo mostramos en pantalla
            cout<<"Encontrado, el elemento es: "<<raiz->info<<endl;
		}
		else{
			//si no se encuentra mostramos esto
			cout<<"El elemento ingresado no esta en la pila"<<endl;
		}
	}
	else{
		//si la pila no contiene  nada mostramos este mensaje
		cout<<"La pila esta vacia...."<<endl;
	}
}

Pila::~Pila(){
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

//funcion menu encargada de pedir datos al usuario
void menu(){
	cout<<"Sistema de almacenamiento en pilas."<<endl;
	cout<<"Ingrese una opcion."<<endl;
    cout<<"1 - Agregar un nuevo elemento a la pila."<<endl;
    cout<<"2 - Mostrar datos de la pila"<<endl;
    cout<<"3 - Extraer un elemento de la pila"<<endl;
    cout<<"4 - Buscar un elemento en la pila"<<endl;
    cout<<"5 - Salir"<<endl;
}

int main(){
    Pila *pila1;
    pila1= new Pila();
    int opc;
    int ingreso;
    
    
    do{
		
	    menu();
	    cin>>opc;
	    
	    switch(opc){
	    	
	    	//INGRESO DE DATOS A LA PILA
	    	case 1:
	    		char res;
	    		do{
		    		cout<<"Ingrese el dato que desea almacenar en la pila (dato numerico)"<<endl;
		    		cin>>ingreso;
		    		pila1->insertar(ingreso);
		    		cout<<"Desea ingresar mas datos a la cola? (y/n)"<<endl;
		    		cin>>res;
				}while(res == 'y' || res == 'Y');
	    	break;
	    	
	    	//MOSTRAR LOS DATOS QUE ESTAN EN LA PILA
	    	case 2:
	    		pila1->imprimir();
	    	break;
	    	
	    	//ELIMINAR DATOS DE LA PILA
	    	case 3:
	    		cout<<"Extraemos de la pila:" <<pila1->extraer()<<"\n";
	    	break;
	    	
	    	//BUSCAR DATOS EN LA PILA
	    	case 4:
	    		pila1->buscar();
	    	break;
	    	
	    	//SALIR DEL PROGRAMA
	    	case 5:
	    	break;
		}
		system("pause");
		system("cls");
    }while(opc!=5);
	
	
		
    return 0;
}
