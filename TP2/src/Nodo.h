/*
 * Nodo.h
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#ifndef NODO_H_
#define NODO_H_

template <typename T>
class Nodo {
private:
	T dato;
	Nodo<T> * siguiente;

public:
	/**
	 * pre: -
	 * pos: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
	 */
	Nodo(T dato);

	/**
	 * pre:
	 * pos: elimina la memoria
	 */
	virtual ~Nodo(); //no hago delete

	/**
	 * pre:
	 * pos: devuelve el dato del nodo
	 */
	T getDato();

	/**
	 * pre:
	 * pos: cambia el dato del nodo
	 */
	void setDato(T dato);

	/**
	 * pre:
	 * pos: devuelve el siguiente nodo
	 */
	Nodo<T>* getSiguiente();

	/**
	 * pre:
	 * pos: cambia el nodo siguiente
	 */
	void setSiguiente(Nodo<T>* siguiente);
};

#endif /* NODO_H_ */
