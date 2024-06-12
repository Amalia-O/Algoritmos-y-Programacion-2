/*
 * Nodo.cpp
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#include"Nodo.h"
#include <iostream>

template <typename T> Nodo<T>::Nodo(T dato) {
	this->dato = dato;
	this->siguiente = NULL;
}

template <typename T> Nodo<T>::~Nodo() {}


template <typename T> T Nodo<T>::getDato() {
	return this->dato;
}

template <typename T> void Nodo<T>::setDato(T dato) {
	this->dato = dato;
}

template <typename T> Nodo<T>* Nodo<T>::getSiguiente() {
	return this->siguiente;
}

template <typename T> void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
	this->siguiente = siguiente;
}
