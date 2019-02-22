/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 21/02/2019
*/

/*EJERCICIO N1, GUIA TAD:
Escribir una función mayor() que intercambie dos valores cuando 
el primero sea mayor que el segundo. Hacer un programa que la utilice.
*/

#include <iostream>

using namespace std;

//funcion que intercambia los valores
void mayor(int *nA, int *nB){
	//hacemos las respectivas evaluaciones...
	if (*nA > *nB){
		cout<<"El numero mayor introducido es: "<<*nA<<endl;
		cout<<"El numero menor introducido es: "<<*nB;
	}
	else if (*nB > *nA){
		cout<<"El numero mayor introducido es: "<<*nB<<endl;
		cout<<"El numero menor introducido es: "<<*nA;
	}
	//pasara a esta parte si ambos numeros son iguales
	else{
		cout<<"Ambos numeros son iguales.";
	}
}

int main() {
	int n1;
	int n2;//variables que guardan los numeros
	
	//solicitamos en consola ambos numeros...
	cout<<"Introduzca un numero: ";
	cin>>n1;
	cout<<"Introduca otro numero: ";
	cin>>n2;
	
	//hacemos la llamada a la funcion...
	mayor(&n1, &n2);
	
	return 0;
}
