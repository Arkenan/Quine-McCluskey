/*
 * Parser.cpp
 *
 *  Created on: 25/05/2014
 *      Author: Tomás Arjovsky
 */

#include <stdlib.h>
#include "Parser.h"
#include "Binario.h"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

void Parser::primeraLinea(){
	string linea;
	string* palabras;

	input.clear();
	input.seekg(0);
	getline(input,linea);
	palabras = split(linea, ' ');

	if (palabras[0] == "min"){
		tipo = MIN;
	} else {
		if (palabras[0] == "max"){
			tipo = MAX;
		} else {
			//tengo que ver como plantear el error.
			cout << "Error en el Tipo de términos" << endl;
		}
	}

	cantVariables = atoi(palabras[1].c_str());

	delete []palabras;
	input.clear();
	input.seekg(0);
}


void Parser::recopilarTerminos(list<Binario*>* terminos){
	input.clear();
	input.seekg(0);

	string str;
	terminos->clear();

	//la primera línea no tiene términos.
	getline(input,str);

	for (int i = 0; i < cantLineas - 1; i++){
		getline(input, str);
		//cantidad de variables correcta?
		if (str.length() != cantVariables){
			cout << "ERROR(cantidad de variables)" << endl;
		} else {
			terminos->push_back(new Binario(str));
			//acá habría que atajar la excepción (o dejarla pasar) si no representa un nro binario.
		}
	}

	input.clear();
	input.seekg(0);
}


int Parser::contarLineas(ifstream& archivo){
	archivo.clear();
	archivo.seekg(0);

	string strAux;
	int cantLineas = 0;
	while (getline(archivo,strAux)){
		cantLineas++;
	}

	archivo.clear();
	archivo.seekg(0);

	return cantLineas;
}

string* Parser::split(string str, char separador){
	string* resultado;
	short int indice = 0;
	short unsigned int cPalabras = 0;

	while (indice != -1){
		indice = str.find(separador,indice + 1);
		cPalabras++;
	}

	//ahora que tengo la cantidad de palabras tendría que separarlas.
	resultado = new string[cPalabras];

	indice = 0;
	for (int i = 0; i < cPalabras - 1; i++){
		indice = str.find(separador);
		resultado[i] = str.substr(0,indice);
		str.erase(0,indice + 1);
	}
	resultado[cPalabras - 1] = str;

	return resultado;
}

int Parser::cantPalabras(string str,char separador){
	short int indice = 0;
		short unsigned int cPalabras = 0;

		while (indice != -1){
			indice = str.find(separador,indice + 1);
			cPalabras++;
		}
	return cPalabras;
}

int Parser::getCantTerminos(){
	return (cantLineas - 1);
}

void Parser::setInput(string nombreInput){
	string linea;
	input.open(nombreInput.c_str());
	cantLineas = contarLineas(input);
	primeraLinea();
}

Parser::Parser(string nombreInput) {
	setInput(nombreInput);
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}
