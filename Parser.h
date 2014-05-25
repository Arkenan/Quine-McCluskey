/*
 * Parser.h
 *
 *  Created on: 25/05/2014
 *      Author: Tomás Arjovsky
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Binario.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Parser {
private:
	ifstream input;
	int cantLineas;
	bool tipo;
	unsigned int cantVariables;
public:
	Parser(string nombreInput);
	virtual ~Parser();
	void recopilarTerminos(list<Binario*>* terminos);
	void primeraLinea();
	void setInput(string nombreInput);
	int contarLineas(ifstream& archivos);
	string* split(string str, char separador);
	int cantPalabras(string str,char separador);
	int getCantTerminos();
};
#endif /* PARSER_H_ */
