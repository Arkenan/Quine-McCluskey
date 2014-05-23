/*
 * Lista.h
 *
 *  Created on: 22/05/2014
 *      Author: root
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

template <class T>
class Lista{
private:
	Nodo<T> * nodoP;
	Nodo<T> * indice;
public:
	Lista();
	virtual ~Lista();
};

#endif /* LISTA_H_ */
