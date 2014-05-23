/*
 * Nodo.cpp
 *
 *  Created on: 22/05/2014
 *      Author: root
 */

#include "Nodo.h"

template <class T>
Nodo<T>::~Nodo() {}

template <class T>
Nodo<T>::Nodo(){
	this->setSig(0);
}

template <class T>
	Nodo<T>::~Nodo(){
}

template <class T>
T Nodo<T>::getContenido(){
	return contenido;
}

template <class T>
Nodo* Nodo<T>::getSig(){
	return siguiente;
}

template <class T>
void Nodo<T>::setcontenido(T nuevacontenido){
	contenido = nuevacontenido;
}

template <class T>
void Nodo<T>::setSig(Nodo* nuevoSig){
	siguiente = nuevoSig;
}
