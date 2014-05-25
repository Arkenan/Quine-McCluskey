/* Input: Archivo sin extensión llamado Input.
 * 	- Primera línea: 	- "min" o "max" según maxiterminos o miniterminos.
 * 						- Cantidad de variables.
 * 						- Palabras que reperesentan a cada variable, separadas por coma.
 * 	- Siguientes líneas: términos.
 * Output: Archivo sin extención llamado Output.
 * 	- Línea con la función mínima escrita en las letras indicadas.
 */

#include <iostream>
#include <string>
#include "Binario.h"
#include "Parser.h"
#include "pruebas.h"
#include "utilidades.h"
using namespace std;


int main(){
	Parser* parser = new Parser("input");
	list<Binario*>* terminos = new list<Binario*>;
	parser->recopilarTerminos(terminos);

	for (int i = 0; i < parser->getCantTerminos(); i++){
		cout << terminos->front()->toString() << endl;
		terminos->pop_front();
	}

	delete parser;
	delete terminos;
	return 0;
}

