/*
Ejercicio realizado por: 
Edgar Antonio Reyes Ceron.
#Carnet: RC18050
PROGRAMACION II-2019
Última modificación: 25/04/2019
*/
#include <iostream>
#include <string.h>
#include "clase.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	 
	ISSS *isss = new ISSS();
	AFP *afp = new AFP();
	Renta *renta = new Renta();
	float salario;
	float sLiquido;
	cout<<"Ingrese su salario para calcular los respectivos descuentos (AFP, Renta e ISSS)."<<endl;
	cin>>salario;
	
	sLiquido = salario - isss->getCalculo(salario) - renta->getCalculo(salario) - afp->getCalculo(salario);
	
    cout<<"Total descuento de ISSS: $"<<isss->getCalculo(salario)<<endl;
    cout<<"Total descuento de Renta: $"<<renta->getCalculo(salario)<<endl;
    cout<<"Total descuento de AFP: $"<<afp->getCalculo(salario)<<endl;
    cout<<"Salario Liquido final: $"<<sLiquido<<endl;
    
	return 0;
}
