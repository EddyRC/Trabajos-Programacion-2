/*
Programa realizado por:
Edgar Antonio Reyes Ceron.
#Carnet: RC18050.
Programacion 2. Ciclo 01-2019

Ultima modificacion: 21/02/2019
*/

//EJERCICIO PROPUESTO EN CLASE: IMPRIMIR DE MANERA INVERSA UNA FRASE.
#include <iostream>

using namespace std;

//reutilice la funcion vista en clase
int longitud(char *cadena){
	char *ptr = cadena;
	while(ptr[0] != '\0'){
		ptr++;
	}
	return (int) (ptr-cadena);
}

//funcion principal main
int main(){
	
	char *letra;//puntero
	char arr[50];//arreglo declarado para guardar los datos introducidos en consola
	letra = arr;//inicializamos el puntero, haciendo que apunte a arr.
	
	//a continuacion pedimos una frase o palabra en consola.
	cout<<"Ingrese una frase: "<<endl;
	cin.getline(arr,50);//guardamos en arr la frase
	cout<<endl;
	
	//mostramos la longitud de la frase.
	cout<<"Esta es la longitud de su frase: "<<longitud(letra)<<endl;
	cout<<endl;
	
	//mostramos la frase pero de manera inversa.
	cout<<"Su frase de manera inversa quedaria asi: "<<endl;
	
	//ciclo for encargado de darle vuelta a la frase introducida.
	for(int i= longitud(letra) ; i>=0; i--){
		cout<<*(arr+i);//se imprime la frase segun la longitud de la misma
	}
	return 0;
}

