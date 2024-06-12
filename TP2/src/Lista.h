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

private:

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el nodo en la posición indicada.
     */
	Nodo<T> * obtenerNodo(unsigned int posicion);

	void validarPosicion(unsigned int posicion);
};




#endif /* LISTA_H_ */
