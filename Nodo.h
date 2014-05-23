/*
 * Nodo.h
 *
 *  Created on: 22/05/2014
 *      Author: root
 */

#ifndef NODO_H_
#define NODO_H_

template <class T>
class Nodo {
private:
	T contenido;
	Nodo* siguiente;
public:
	Nodo();
	virtual ~Nodo();
	T getContenido();
	Nodo* getSiguiente;

};

#endif /* NODO_H_ */
