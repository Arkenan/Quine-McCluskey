/*
 * pruebas.cpp
 *
 *  Created on: 12/04/2014
 *      Author: Tomás Arjovsky
 */

#include <iostream>
#include <string>
#include "utilidades.h"
using namespace std;

void probarBin(){
	char opcion;
	string bin;
	cout << "Desea ingresar un número binario para pasarlo a decimal? s/n" << endl;
	cin >> opcion;
	while (opcion == 's') {
		cout << "Ingrese un número: ";
		cin >> bin;
		cout << bin << " en decimal es: " << binToInt(bin) << endl;
		cout << "Desea ingresar otro?" << endl;
		cin >> opcion;
	}
}

void probarModulo(){
	int a = 1 << 5, b= 10;
	a = a >> 5;
	cout << "a:" << a << endl << "~a: " << ~a << endl ;
	cout << "b: " << b << endl << "~b: " << ~b << endl;
	if (~a == b){}
	int c = 50;
	cout << "c: " << c << endl << "-c: " << negativo(c) << endl;
}

void probarSplit(){
	string str = "Estamos hablando de lo mismo no?";
	string* palabras;
	palabras = split(str, ' ');

	for (int i = 0; i < cantPalabras(str, ' '); i++){
		cout << palabras[i] << endl;
	}

	delete []palabras;
}

void probarOrden(){
	int * terminos = new int[10];
	unsigned int * conts = new unsigned int[10];

	for (int i = 0; i < 10; i++){
		terminos[i] = i + 1;
		conts[i] = contar1s(terminos[i]);
	}

	ordenar(terminos, conts, 10);

	for (int i = 0; i < 10; i++){
		cout << terminos[i] << ": " << conts[i] << " 1s." << endl;
	}
	delete []terminos;
	delete []conts;
}
