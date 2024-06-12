/*
 * Lista.cpp
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#include"Lista.h"
#include <iostream>

template <typename T> Lista<T>::Lista() {
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

template <typename T> Lista<T>::~Lista() {
	while (this->primero != NULL) {
		Nodo<T> * aBorrar = this->primero;
		this->primero = aBorrar->getSiguiente();
		delete aBorrar;
	}
}

template <typename T> bool Lista<T>::estaVacia() {
	//return (this->primero == NULL);
	return (this->tamanio == 0);
}

template <typename T> unsigned int Lista<T>::getTamanio() {
	return this->tamanio;
}

template <typename T> void Lista<T>::agregar(T elemento) {
	this->agregar(elemento, this->getTamanio() + 1);
}

template <typename T> void Lista<T>::agregar(T elemento, unsigned int posicion) {
	validarPosicion(posicion);
    Nodo<T> * nuevo = new Nodo<T>(elemento);
    if (posicion == 1) {
    	nuevo->setSiguiente( this->primero);
    	this->primero = nuevo;
    } else {
    	Nodo<T> * anterior = this->obtenerNodo(posicion -1);
    	nuevo->setSiguiente( anterior->getSiguiente());
    	anterior->setSiguiente( nuevo );
    }
    this->tamanio++;
}

template <typename T> Nodo<T> * Lista<T>::obtenerNodo(unsigned int posicion) {
	//validarPosicion(posicion);
	Nodo<T> * actual = this->primero;
	for(unsigned int i = 1; i < posicion; i++) {
		actual = actual->getSiguiente();
	}
	return actual;
}

template <typename T> void Lista<T>::validarPosicion(unsigned int posicion) {
    if ((posicion < 1) ||
    	(posicion > this->tamanio + 1)) {
    	throw "La posicion debe estar entre 1 y tamaño + 1";
    }
}

template <typename T> void Lista<T>::remover(unsigned int posicion) {
	validarPosicion(posicion);
	Nodo<T> * removido;
	if (posicion == 1) {
		removido = this->primero;
		this->primero = removido->getSiguiente();
	} else {
		Nodo<T> * anterior = this->obtenerNodo(posicion -1);
		removido = anterior->getSiguiente();
		anterior->setSiguiente( removido->getSiguiente());
	}
	delete removido;
	this->tamanio--;
}

template <typename T> T Lista<T>::obtener(unsigned int posicion) {
	validarPosicion(posicion);
	return this->obtenerNodo(posicion)->getDato();
}

template <typename T> void Lista<T>::cambiar(T elemento, unsigned int posicion) {
	validarPosicion(posicion);
	this->obtenerNodo(posicion)->setDato(elemento);
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {
    if (this->cursor == NULL) {
        this->cursor = this->primero;
    } else {
        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {
    T elemento;
    if (this->cursor != NULL) {
        elemento = this->cursor->obtenerDato();
    }
    return elemento;
}


