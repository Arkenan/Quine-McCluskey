/* Input: Archivo sin extensión llamado Input.
 * 	- Primera línea: 	- "min" o "max" según maxiterminos o miniterminos.
 * 						- Cantidad de variables.
 * 						- Palabras que reperesentan a cada variable, separadas por coma.
 * 	- Siguientes líneas: términos.
 * Output: Archivo sin extención llamado Output.
 * 	- Línea con la función mínima escrita en las letras indicadas.
 */

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "pruebas.h"
#include "utilidades.h"
using namespace std;

//Primero lo hago para minterminos. Despues veo como generalizar.
//Debería devolver una lista con implicantes (objeto).
void QMC(int* terminos, unsigned int cantTerminos){
	//Primero hay que ordenar los terminos según la cantidad de unos que tienen.
	//Con este objetivo hago un vector paralelo con los
	unsigned int* contadoresDe1s = new unsigned int[cantTerminos];

	for (unsigned int i = 0; i < cantTerminos; i++){
		contadoresDe1s[i] = contar1s(terminos[i]);
	}

	ordenar(terminos, contadoresDe1s, cantTerminos);
	/* Se buscan implicantes primos.*/
	//Hay que comparar numeros lugar a lugar y ver si coinciden en alguno.


}

void parsear(){

	ifstream input; input.open("input");
	ofstream output; output.open("output");
	string str;
	unsigned int cantVariables, cantLineas;
	bool tipo;
	int * terminos;

	cantLineas = contarLineas(input);

	getline(input, str);
	primeraLinea(str,tipo, cantVariables);
	terminos = new int[cantLineas - 1];
	recopilarTerminos(terminos, cantVariables, input, cantLineas);

	delete []terminos;

	input.close();
	output.close();

}

int main(){
	//parsear();
	probarSplit();
	return 0;
}

