/*
 * Ciudad.h
 *
 *  Created on: 14/06/2024
 *      Author: algo2
 */

#ifndef CIUDAD_H_
#define CIUDAD_H_

#include "Barrio.h"
#include "Lista.h"

class Ciudad {
private:
    Lista<Barrio*> * barrios;
public:
    /*
     * PRE: -
     * POS: construye el objeto con lista de barrios vacia.
    */
    Ciudad();

    /*
     * PRE: -
     * POS: libera la memoria.
    */
    ~Ciudad();

    /*
     * PRE: -
     * POS: devuelve la lista de barrios.
    */
    Lista<Barrio*> * getBarrios();

    /*
     * PRE: -
     * POS: cambia la lista de barrios por la nueva. La vieja lista es borrada.
    */
    void setBarrios(Lista<Barrio*> * barrios);

    /*
     * PRE: -
     * POS: devuelve true si el nombre del barrio ya esta en la lista.
    */
    bool barrioEnLista(Barrio * barrio);

    /*
     * PRE: el barrio a agregar no esta en la lista.
     * POS: agrega el barrio al final de la lista.
    */
    void agregarBarrio(Barrio * barrio);

    /*
     * PRE: parametro no nulo.
     * POS: devuelve una lista con las paradas de la linea de colectivo en todos los barrios.
     *      Si no hay ninguna devuelve una lista vacia.
    */
    Lista<Parada*> * buscarParadas(unsigned int colectivo);
     

};

#endif /* CIUDAD_H_ */