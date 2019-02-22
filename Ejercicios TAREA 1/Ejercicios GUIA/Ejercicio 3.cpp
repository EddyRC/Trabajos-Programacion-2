/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 22/02/2019
*/

/*EJERCICIO N3, GUIA TAD:
Escribir una función potencia(), que calcule la potencia de un número n (tipo double) elevado a 
un exponente p (tipo int). Escribir un programa que haga uso de esta función. 
*/

#include <iostream>

using namespace std;

//funcion que sirve para calcular la potencia de un numero.
double potencia(double *n, int *p){
	double acum = 1;
	
	for(int i=1;i<= *p;i++){
		acum = *n * acum;
	}
	return acum;
}

//funcion principal main
int main() {
	double base; 
	int exponente;

	cout<<"Introduzca la base del numero que desea calcular su potencia: "<<endl;
	cin>>base;
	cout<<"Introduzca el exponente: "<<endl;
	cin>>exponente;
	
	//imprimimos en pantalla el resultado. //hacemos la llamada a la funcion y le pasamos los parametros.
	cout<<"La potencia de "<<base<<" es: "<<potencia(&base, &exponente)<<endl;
	
	return 0;
}
