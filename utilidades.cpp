/*
 * utilidades.cpp
 *
 *  Created on: 12/04/2014
 *      Author: root
 */
#include <iostream>
#include <fstream>
#include <string>
#include "utilidades.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

int digitoBinario(int num, int posicion){
	return (int( (num & (1 << (posicion - 1))) != 0));
}

unsigned int contar1s(int bin){
	/* Algoritmo de Brian Kernighan para contar 1s.
	 * A cada paso quita el 1 que más a la derecha está.
	 * La cantidad de pasos es la cantidad de 1s.
	 * */
	int cont;
    for (cont = 0; bin != 0; cont++){
    	bin &= bin - 1;
    }
    return cont;
}

int contarLineas(ifstream& archivo){
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

string* split(string str, char separador){
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

int cantPalabras(string str,char separador){
	short int indice = 0;
		short unsigned int cPalabras = 0;

		while (indice != -1){
			indice = str.find(separador,indice + 1);
			cPalabras++;
		}
	return cPalabras;
}

int negativo(int a){
	//esto funciona en modulo a 2.
	return (~a + 1);
}

/* Transforma un numero binario a un entero. Si no es binario devuelve -1*/
int binToInt(string bin){
	short int largo = bin.length();
	int resultado = 0;
	for (int i = 0; i < largo; i++){
		if ((bin[i] != '1') && (bin[i] != '0')){
			return -1;
		}
		resultado += (int(bin[i] - '0') * exp2(largo - i - 1));
	}
	return resultado;
}

/* Muestra las propiedades de los enteros en este sistema.*/
void arquitectura(){
	int a = 1, b = 0, i = 1;

	while (a > b){
		b = a;
		a = a << 1;
		i++;
	}

	cout << "Entero: " << i << " bits (" << i/8 << " bytes)" << endl << endl;
	cout << "CON SIGNO" << endl;
	cout << "Entero más chico: " << a << endl;
	cout << "Entero más grande: " << a-1 << endl << endl;

	unsigned int c = 0;
	c -= 1;

	cout << "SIN SIGNO" << endl;
	cout << "Entero más grande: " << c << endl << endl;

	cout << "PUNTO FLOTANTE" << endl;
}

void primeraLinea(string linea, bool& tipo, unsigned int& cantVariables){
	string* palabras;
	palabras = split(linea, ' ');

	if (palabras[0] == "min"){
		tipo = MIN;
	} else {
		if (palabras[0] == "max"){
			tipo = MAX;
		} else {
			//tengo que ver como plantear el error.
		}
	}

	cantVariables = atoi(palabras[1].c_str());
	delete []palabras;
}

void recopilarTerminos(int* terminos, unsigned int cantVariables,ifstream& input, unsigned int cantLineas){
	int termino;
	string str;

	input.clear();
	input.seekg(0);

	//la primera línea no tiene términos.
	getline(input,str);

	for (unsigned int i = 0; i < cantLineas - 1; i++){
		getline(input, str);
		//cantidad de variables correcta?
		if (str.length() != cantVariables){
			cout << "ERROR(cantidad de variables)" << endl;
		} else {
			termino = binToInt(str);
			//la string corresponde a un binario?
			if (termino == -1){
				cout << "ERROR(no es binario)" << endl;
			} else {
				terminos[i] = binToInt(str);
				cout << terminos[i] << endl;
			}
		}
	}
}
// PROPIAS DEL PROBLEMA.

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}

void ordenar(int * terminos,unsigned int * contadoresDe1s, unsigned int cantTerminos){
	//por ahora hago un bubble. Cuando tenga tiempo le pongo un merge que tengo por ahí.
	bool ordenado = false, huboCambios;
	unsigned int paso = 1, pos;
	while ((!ordenado) && (paso <= cantTerminos)){
		huboCambios = false;
		for (pos = 0; pos < cantTerminos; pos++){
			if (contadoresDe1s[pos] > contadoresDe1s[pos + 1]){
				swap(contadoresDe1s[pos],contadoresDe1s[pos + 1]);
				swap(terminos[pos],terminos[pos + 1]);
				huboCambios = true;
			}
		}
		ordenado = !huboCambios;
		paso++;
	}
}

