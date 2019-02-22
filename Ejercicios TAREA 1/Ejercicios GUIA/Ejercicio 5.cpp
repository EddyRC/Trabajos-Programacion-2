/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 22/02/2019
*/

/*EJERCICIO N5, GUIA TAD:
Escribir una función menorAcero() al que se pasan dos argumentos int por referencia y a 
continuación fijar el menor de los dos números a 0. Escribir un programa que utilice esta función.
*/
#include <iostream>

using namespace std;

//funcion encargada de fijar a cero un dato menor de una pareja de datos.
void menorAcero(int *numero1, int *numero2){
		//hacemos las respectivas evaluaciones...
	if (*numero1 > *numero2){
		*numero2 = 0;
		cout<<"El numero mayor introducido es: "<<*numero1<<endl;
		cout<<"El numero menor introducido ahora ha cambiado a: "<<*numero2;
	}
	else if (*numero2 > *numero1){
		*numero1 = 0;
		cout<<"El numero mayor introducido es: "<<*numero2<<endl;
		cout<<"El numero menor introducido ahora ha cambiado a: "<<*numero1;
	}
	//pasara a esta parte si ambos numeros son iguales
	else{
		cout<<"Ambos numeros son iguales.";
	}
}
int main(){
	int numerito1;
	int numerito2;
	//pedimos los numeros en consola
	cout<<"Introduzca un numero: "<<endl;
	cin>>numerito1;
	cout<<"Introduzca otro numero mas: "<<endl;
	cin>>numerito2;
	//hacemos la llamada a la funcion
	menorAcero(&numerito1, &numerito2);
	
	return 0;
}
