/*
 * Implicante.h
 *
 *  Created on: 22/05/2014
 *      Author: root
 */

#ifndef IMPLICANTE_H_
#define IMPLICANTE_H_
#include "Lista.h"

template <class T>

class Implicante {
private:
	Lista<T> lista;
public:
	Implicante();
	virtual ~Implicante();
};

#endif /* IMPLICANTE_H_ */
