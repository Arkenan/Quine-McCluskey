/*
 * pruebas.cpp
 *
 *  Created on: 12/04/2014
 *      Author: Tomás Arjovsky
 */

#include <iostream>
#include <string>
#include "utilidades.h"
#include "Binario.h"
#include "Parser.h"
using namespace std;

void probarBin(){
	char opcion;
	string strBin;
	Binario* bin;

	cout << "Desea ingresar un número binario para pasarlo a decimal? s/n" << endl;
	cin >> opcion;

	while (opcion == 's') {
		cout << "Ingrese un número: ";
		cin >> strBin;

		bin = new Binario(strBin);
		cout << strBin << " en decimal es: " << bin->decimal() << endl;
		delete bin;

		cout << "Desea ingresar otro?" << endl;
		cin >> opcion;
	}
}

void probarModulo(){
	int a = 1 << 5, b= 10;
	a = a >> 5;
	cout << "a:" << a << endl << "~a: " << ~a << endl ;
	cout << "b: " << b << endl << "~b: " << ~b << endl;
}

void probarSplit(){
	Parser* parser = new Parser("input");
	string str = "Estamos hablando de lo mismo no?";
	string* palabras;
	palabras = parser->split(str,' ');

	for (int i = 0; i < parser->cantPalabras(str, ' '); i++){
		cout << palabras[i] << endl;
	}

	delete []palabras;
	delete parser;
}

void ejecutarPruebas(){
	probarBin();
	probarModulo();
	probarSplit();
}
