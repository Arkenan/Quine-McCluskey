/*
 * utilidades.cpp
 *
 *  Created on: 12/04/2014
 *      Author: Tomás Arjovsky
 */
#include <iostream>
#include <fstream>
#include <string>
#include "utilidades.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

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

