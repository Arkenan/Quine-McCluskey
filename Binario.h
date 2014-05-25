/*
 * Binario.h
 *
 *  Created on: 25/05/2014
 *      Author: Tomás Arjovsky
 */

#ifndef BINARIO_H_
#define BINARIO_H_

#include <string>
using namespace std;

const bool MIN = false;
const bool MAX = true;

class Binario {
private:
	int num;
public:
	Binario(int decimal);
	Binario(string strBin);
	virtual ~Binario();
	int get(int posicion);
	unsigned int contar1s();
	int decimal();
	string toString();
};

#endif /* BINARIO_H_ */
