/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 22/02/2019
*/

/*EJERCICIO N4, GUIA TAD:
Diseñar una función area() que pueda calcular el área de un cuadrado y un cubo. 
Escribir un programa que haga uso de esta función. 
*/

#include <iostream>
#include <math.h>//para utilizar pow
#include <windows.h>

using namespace std;

//funcion para calcular el area de un cuadrado
double areaCuadrado(double *lado){
	int respuesta;
	//elevamos al cuadrado el lado y ya estaria calculada el area
	respuesta = pow(*lado, 2);
	
	return respuesta;
}

//funcion para calcular el area de un cubo.
double areaCubo(double *lado){
	int resultado;
	//elevamos al cuadrado el lado y luego lo multiplicamos por 6 y ya estaria el area
	resultado = pow(*lado, 2) * 6;
	
	return resultado;
}

int main(){
	int opcion;
	double ladito;
	
	//menu para pedirle al usuario que desea hacer
	do{
		cout<<"Que desea encontrar?"<<endl;
		cout<<"1 - Area de un cuadrado."<<endl;
		cout<<"2 - Area de un cubo."<<endl;
		cout<<"3 - Salir del programa..."<<endl;
		cin>>opcion;
		system("cls");
		switch(opcion){
			case 1:
				cout<<"Introduzca la longitud de un lado de su cuadrado: ";
				cin>>ladito;
				//hacemos la llamada a la funcion para calcular el area del cuadrado
				cout<<"El area de su cuadrado es: "<<areaCuadrado(&ladito)<<endl;
				system("pause");
				system("cls");
				break;
			case 2:
				cout<<"Introduzca la longitud de un lado de su cubo: ";
				cin>>ladito;
				//llamamos la funcion para calcular el area del cubo
				cout<<"El area de su cubo es: "<<areaCubo(&ladito)<<endl;
				system("pause");
				system("cls");
				break;
			case 3:
				break;
		}
	}while(opcion != 3);
	
	return 0;
}
