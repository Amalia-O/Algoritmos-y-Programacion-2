/*
 * Barrio.h
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include <iostream>
#include "Lista.h"
#include "Parada.h"

class Barrio {

private:
    std::string nombre;
    Lista<Parada*> * paradas;
    unsigned int comuna;
public:
    /*
     * PRE: parametros no nulos.
     * POS: construye el objeto.
    */
    Barrio(std::string nombre, Lista<Parada*> * paradas, unsigned int comuna);

    /*
     * PRE: parametros no nulos.
     * POS: construye el objeto, iniciando la lista de paradas vacia.
    */
    Barrio(std::string nombre, unsigned int comuna);

    /*
     * PRE: -
     * POS: libera memoria
    */
    ~Barrio();

    /*
     * PRE: -
     * POS: devuelve el nombre
    */
    std::string getNombre();

    /*
     * PRE: -
     * POS: devuelve la lista de paradas
    */
    Lista<Parada*> * getParadas();

    /*
     * PRE: -
     * POS: devuelve la comuna
    */
    unsigned int getComuna();

    /*
     * PRE: -
     * POS: cambia el nombre
    */
    void setNombre(std::string nombre);

    /*
     * PRE: -
     * POS: borra la lista anterior y la cambia por la nueva.
    */
    void setParadas(Lista<Parada*> * paradas);

    /*
     * PRE: comuna distinto de 0.
     * POS: cambia la comuna
    */
    void setComuna(unsigned int comuna);

    /*
     * PRE: parametro no nulo.
     * POS: agrega la parada al final de la lista de paradas.
    */
    void agregarParada(Parada * parada);

    /*
     * PRE: parametro no nulo.
     * POS: devuelve una lista con todas las paradas de la linea de colectivo en el barrio.
     *      Si no hay ninguna devuelve una lista vacia.
    */
    Lista<Parada*> * buscarParadasDeLinea(unsigned int colectivo);

    /*
     * PRE: parametro no nulo.
     * POS: devuelve la cantidad de paradas de la linea de colectivo en el barrio.
    */
    unsigned int buscarCantidadDeParadasDeLinea(unsigned int colectivo);

    /*
     * PRE: -
     * POS: devuelve la cantidad total de paradas en el barrio.
    */
    unsigned int getCantidadDeParadas();

    /*
     * PRE: -
     * POS: devuelve la parada más cercana en el barrio a las coordenadas proporcionadas.
    */
    Parada * buscarParadaMasCercana(double coordenadaX, double coordenadaY);

    /*
     * PRE: parametro no nulo.
     * POS: devuelve una lista con todas las paradas de la linea de colectivo en el barrio.
     *      Si no hay ninguna devuelve una lista vacia.
    */
    Lista<Parada*> * buscarParadas(unsigned int colectivo);
} ;

#endif /* BARRIO_H_ */
