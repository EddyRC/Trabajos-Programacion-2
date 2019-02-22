/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 21/02/2019
*/

/*EJERCICIO N2, GUIA TAD:
Escribir una función que multiplique un valor por 10 
y devuelva el valor modificado. Hacer un programa que la utilice. 
*/

#include <iostream>

using namespace std;

//funcion que multiplica el valor solicitado en consola por 10
int modify(int *n){
	int res;
	res = *n * 10;
	return res;
}

//funcion principal main
int main() {
	int num;
	//solicitamos el numero en consola...
	cout<<"Introduce un numero: "<<endl;
	cin>>num;
	
	cout<<"El resultado de multiplicar tu numero por 10 es: "<<modify(&num);//Mandamos a llamar la funcion...
	return 0;
}
