/*
 * Binario.cpp
 *
 *  Created on: 25/05/2014
 *      Author: Tomás Arjovsky
 */

#include "Binario.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

Binario::Binario(int decimal){
	num = decimal;
}

Binario::Binario(string bin){
	short int largo = bin.length();
	int resultado = 0;
	for (int i = 0; i < largo; i++){
		if ((bin[i] != '1') && (bin[i] != '0')){
			//TODO acá iría una excepción. La string no es un nro binario.
			cout << "Error: se intentó construir un número binario con la cadena '" + bin + "'" << endl;
		}
		resultado += (int(bin[i] - '0') * exp2(largo - i - 1));
	}
	num = resultado;
}

Binario::~Binario() {
	// TODO Auto-generated destructor stub
}

int Binario::get(int posicion){
	return (int((num & (1 << (posicion - 1))) != 0));
}


unsigned int Binario::contar1s(){
	/* Algoritmo de Brian Kernighan para contar 1s.
	 * A cada paso quita el 1 que más a la derecha está.
	 * La cantidad de pasos es la cantidad de 1s.
	 * */
	int cont;
    for (cont = 0; num != 0; cont++){
    	num &= num - 1;
    }
    return cont;
}

/* Transforma un numero binario a un entero. Si no es binario devuelve -1*/
int Binario::decimal(){
	return num;
}

string Binario::toString(){
	//debe haber una forma mejor de hacer esto, por ahora aprovecho lo que ya hay hecho.
	string str = "";
	char digito;
	for (int i = 32; i >= 1; i--){
		digito = '0'+ get(i);
		str += digito;
	}
	return str;
}
