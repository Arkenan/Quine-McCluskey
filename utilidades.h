/*
 * utilidades.h
 *
 *  Created on: 12/04/2014
 *      Author: Tomás Arjovsky
 */

#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include <climits>
#include <fstream>
#include <bitset>
using namespace std;

const bool MAX = true;
const bool MIN = false;

//BINARIOS

/* Devuelve el dígito en "posicion" (de derecha a izquierda) del entero "num" */
int digitoBinario(int num, int posicion);

/* Niega un número binario*/
int negativo(int a);

/* Transforma una string de 0s y 1s en un número entero.*/
int binToInt(string bin);

/* Muestra la arquitectura de la computadora.*/
void arquitectura();


//STRINGS Y ARCHIVOS.

/* Cuenta las líneas de un archivo de texto de entrada */
int contarLineas(ifstream& archivo);

/* Devuelve la dirección de un array con las diferentes palabras de un string
 * separadas por el caracter separador.*/
string* split(string str, char separador);

/* Cuenta la cantidad de palabras en una string. Puede ser de utilidad con split */
int cantPalabras(string str, char separador);

/* Procesa la primera línea y devuelve si el algoritmo se aplica sobre
 * minitérimos o maxitérminos (tipo, MIN o MAX), y cantidad de variables*/
void primeraLinea(string linea, bool& tipo, unsigned int& cantVariables);

/* Llena el vector terminos con los valores de input.*/
void recopilarTerminos(int* terminos,unsigned int cantVariables, ifstream& input, unsigned int cantLineas);

/* Cuanta los 1s en la representación binaria de un entero*/
unsigned int contar1s(int bin);

/* intercambia el contenido de dos variables enteras.*/
void swap(int& a, int& b);

/* Ordena el contenido de "terminos" segun sus contadores de 1s. */
void ordenar(int * terminos,unsigned int * contadoresDe1s, unsigned int cantTerminos);

#endif /* UTILIDADES_H_ */
