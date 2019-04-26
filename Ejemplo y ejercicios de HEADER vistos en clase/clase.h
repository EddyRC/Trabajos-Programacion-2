/*
Ejercicio realizado por: 
Edgar Antonio Reyes Ceron.
#Carnet: RC18050
PROGRAMACION II-2019
Última modificación: 25/04/2019
*/
#include <iostream>
#include <string.h>
#ifndef CLASE_H
#define CLASE_H
using namespace std;

class Deducciones{
	private:
		int cod;
		string tipo;
		float total;
	public:
		//constructor
		Deducciones(){}
		void setCod(int Cod){
			this->cod = Cod;
		}
		
		int getCod(){
			return this->cod;
		}
		
		void setTipo(string t){
			this->tipo = t;
		}
		
		string getTipo(){
			return this->tipo;
		}
		
		void setTotal(float tot){
			this->total = tot;
		}
		
		float getTotal(){
			return this->total;
		}
		
		virtual float getCalculo(float salario) = 0;
		
		//destructor
		~Deducciones(){}	
};

class Interface{
	public:
		//constructor
		Interface(){}
		virtual float getCalculo(float salario) = 0;
		//destructor
		~Interface(){}
};

class ISSS:public Interface{
	public:
		//constructor
		ISSS(){}
		float getCalculo(float salario){
			float isss=0;
			
			if(salario>600){
				isss=600*0.03f;
				
			}
			else{
				isss=salario*0.03f;
			} 
			return isss;
		}
		//destructor
		~ISSS(){}
};

class Renta:public Interface{
	public:
		//constructor
		Renta(){}
		float getCalculo(float salario){
			float renta=0;
			
			if(salario>=0.01 && salario<= 472){
	 			renta = salario;
			}
			else if(salario > 472 && salario <= 895.24){
				renta = salario*0.10f;
			}
			else if(salario > 895.24 && salario <= 2038.10){
				renta = salario*0.20f;
			}
			else if(salario > 2038.10){
				renta = salario*0.30f;
			}
		
			return renta;
		}
		//destructor
		~Renta(){}
};

class AFP:public Interface{
	public:
		//constructor
		AFP(){}
		float getCalculo(float salario){
			float afp=0;
	 
			afp = salario*0.0725f;
	
			return afp;
		}
		//destructor
		~AFP(){}
};
#endif

