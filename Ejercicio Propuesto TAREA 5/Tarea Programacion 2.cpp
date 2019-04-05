//Este programa fue hecho por: Edgar Antonio Reyes Ceron.
//#Carnet: RC18050
//Ultima Modificacion 04/04/2019
#include<iostream>
#include <math.h>

using namespace std;

//Clase Padre figura
class Figura{
	private:
		float base;
		float altura;
	
	public:
		Figura(){
			this->base = 0;
			this->altura = 0;
		}
		Figura(float b, float h){
			this->base = b;
			this->altura = h;
		}
		~Figura(){
		}
		
		void setBase(float b){
			this->base = b;
		}
		float getBase(){
			return this->base;
		}
		
		void setAltura(float h){
			this->altura = h;
		}
		float getAltura(){
			return this->altura;
		}
		
		virtual float area() = 0;
		virtual float perimetro() = 0;
			
};

//Clase "hijo" de Clase Figura
class Rectangulo:public Figura{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
	void imprimirR (){
		for (int i=0 ; i<getAltura (); i++){
			cout <<endl;
			for (int j=0 ; j<getBase (); j++){
				cout <<("**");
			}
		}
	}
};

//Clase "hijo" de Clase Figura
class Cuadrado:public Figura{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
	void imprimirCd (){
		for (int j=0; j<getAltura(); ++j) {
	      for (int i=0; i<getBase(); ++i) {
	         cout <<"*";
	      }
	      cout << endl;
	   }
	}	
};

//Clase "hijo" de Clase Figura
class Triangulo: public Figura{
	private: 
		float l1, l2;
	public :
		void setl1(float l){
			this->l1 = l;
		}
		float getl1(){
			return this->l1;
		}
		
		void setl2(float l){
			this->l2 = l;
		}
		float getl2(){
			return this->l2;
		}
		
		float area (){
		 return ((getBase()*getAltura())/2);
		}	
		float perimetro(){
		 return (l1+l2+getBase()); 
		}
		
	void imprimirTr (){
		for(int i=1; i<=getAltura(); i++){
			for(int n=1; n<=i; n++){
				cout<<"*";
			}
			cout<<endl;
		}
	}
};

//Clase en donde se instancian objetos de cada una de las clases hijo
class Principal{
	public:
		Principal (){  
			//AREA DEL RECTANGULO  
			Rectangulo *rt = new Rectangulo ();
			rt->setBase (6);
			rt->setAltura(4);
			cout<<"base: "<<rt->getBase()<<" altura: "<<rt->getAltura()<<endl;
			cout<<"Area del rectangulo:"<<rt->area()<<endl;
			cout<<"Perimetro del rectangulo:"<<rt->perimetro()<<endl;
			cout<<"RECTANGULITO"<< endl;
			rt->imprimirR();
			cout<< endl ;

			cout<<endl;
			//AREA DEL CUADRO
			Cuadrado *cd = new Cuadrado ();
			cd->setBase (8);
			cd->setAltura(5);
			cout<<"base: "<<cd->getBase()<<" altura: "<<cd->getAltura()<<endl;
			cout<<"Area del cuadrado:"<<cd->area()<<endl;
			cout<<"Perimetro del cuadrado:"<<cd->perimetro()<<endl;
			cout<<"CUADRADITO"<< endl;
			cd->imprimirCd();
			cout<< endl ;

			cout<<endl;
			//AREA DEL TRIANGULO
			Triangulo *tr = new Triangulo ();
			tr->setBase (7);
			tr->setAltura(6);  
			cout<<"base: "<<tr->getBase()<<" altura: "<<tr->getAltura()<<endl;
			cout<<"Area del Triangulo:"<<tr->area()<<endl;
			cout<<"Perimetro del Triangulo:"<<tr->perimetro()<<endl;
			cout<<"TRIANGULITO"<< endl;
			tr->imprimirTr();
			cout<< endl ;
		}		
	
		
} ;

int main(){
	system ("color 5B");
	//instanciamos un nuevo objeto de la clase Principal()
	Principal *pro = new Principal();
	return 0;
}

