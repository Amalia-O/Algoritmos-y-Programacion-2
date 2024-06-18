/*
 * Lista.h
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

template <typename T>
class Lista {

private:
	Nodo<T> * primero;
	unsigned int tamanio;
	Nodo<T>* cursor;

public:

	/**
	 * pre:
	 * pos: crea una lista vacia
	 */
	Lista();

	/**
	 * pre:
	 * pos: elimina la memoria de la lista, no de los datos
	 */
	virtual ~Lista();

	/**
	 * pre:
	 * pos: indica si la Lista tiene algún elemento.
	 */
	bool estaVacia();

    /*
	 * post: devuelve la cantidad de elementos que tiene la Lista.
	 */
	unsigned int getTamanio();

	/**
	 * pre: -
	 * pos: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
	 */
	void agregar(T elemento);

	/**
	 * pre: posición pertenece al intervalo: [1, contarElementos() + 1]
	 * pos: agrega el elemento en la posición indicada.
	 */
	void agregar(T elemento, unsigned int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
	void remover(unsigned int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: devuelve el dato de la posicion
	 */
	T obtener(unsigned int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: cambia el elemento de la posicion
	 */
	void cambiar(T elemento, unsigned int posicion);

    /*
	 * post: deja el cursor de la Lista preparado para hacer un nuevo
	 *       recorrido sobre sus elementos.
	 */
	void iniciarCursor();

	/*
	 * pre : se ha iniciado un recorrido (invocando el método
	 *       iniciarCursor()) y desde entonces no se han agregado o
	 *       removido elementos de la Lista.
	 * post: mueve el cursor y lo posiciona en el siguiente elemento
	 *       del recorrido.
	 *       El valor de retorno indica si el cursor quedó posicionado
	 *       sobre un elemento o no (en caso de que la Lista esté vacía o
	 *       no existan más elementos por recorrer.)
	 */
	bool avanzarCursor();

	/*
	 * pre : el cursor está posicionado sobre un elemento de la Lista,
	 *       (fue invocado el método avanzarCursor() y devolvió true)
	 * post: devuelve el elemento en la posición del cursor.
	 *
	 */
	T obtenerCursor();

	//TODO probar con valgrind que esta función no dé memory leaks (la programe para que no los tenga, pero talvez tiene...)
	/*
	 * pre : se proporciona una lista no vacia.
	 * post: concatena los contenidos de la lista parámetro al final de
	 * 		 la lista en cuestión. La lista parámetro es eliminada.
	 */
	void concatenarLista(Lista<T> * lista);

	/*
	 * pre : -
	 * post: Borra de memoria la lista pero NO sus contenidos.
	 * 		 Útil si los contenidos de la lista1 pertenecen a otra lista2, y no se quiere eliminar
	 * 		 los contenidos de la otra lista2, sino solo la referencia a esta lista1.
	 */
	void eliminarListaNoContenidos();

private:

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el nodo en la posición indicada.
     */
	Nodo<T> * obtenerNodo(unsigned int posicion);

	void validarPosicion(unsigned int posicion);
};

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
	this->tamanio = 0;
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
    	nuevo->setSiguiente(this->primero);
    	this->primero = nuevo;
    } else {
    	Nodo<T> * anterior = this->obtenerNodo(posicion-1);
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
        this->cursor = this->cursor->getSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {
    T elemento;
    if (this->cursor != NULL) {
        elemento = this->cursor->getDato();
    }
    return elemento;
}

template<class T> void Lista<T>::concatenarLista(Lista<T> * lista) {
	if (this->estaVacia()) {
		//Si esta vacia simplemente reemplazo una lista por la otra.
		this->primero = lista->primero;
	}
	else {
		//Voy al ultimo nodo de la lista y hago que apunte al primero de la lista parametro -> concateno!
		this->obtenerNodo(this->tamanio)->setSiguiente(lista->primero);
	}
	this->tamanio = this->tamanio + lista->getTamanio();
	//Hago que la lista parametro apunte a NULL para no borrar sus contenidos, solo su referencia.
	lista->primero = NULL;
	delete lista;
}

template<class T> void Lista<T>::eliminarListaNoContenidos() {
	this->primero = NULL;
	delete this;
}

#endif /* LISTA_H_ */
