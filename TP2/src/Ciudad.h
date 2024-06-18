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
#include "Parada.h"

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
    bool barrioEnLista(std::string nombre);

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

    /*
     * PRE: parametro no nulo.
     * POS: devuelve la cantidad de paradas de la linea de colectivos en todos los barrios.
    */
    unsigned int buscarCantidadDeParadasDeLinea(unsigned int colectivo);

    /*
     * PRE: el barrio a agregar no esta en la lista.
     * POS: agrega el barrio al final de la lista.
    */
    void agregarParadaAlBarrio(std::string barrio, unsigned int comuna, Parada *parada);
     
    /*
     * PRE: parada, barrio y comuna no nula.
     * POS: si el barrio esta en la lista, agrega la parada, sino crea el barrio al final de la lista y le agrega
     * la parada.
    */
    void ubicarParada(std::string barrio, unsigned int comuna, Parada *parada);

    /*
     * PRE: coordenadas validas.
     * POS: devuelve la parada mas cercana a las coordenadas.
    */
    Parada * buscarParadaMasCercana(double coordX, double coodY);
    
};

#endif /* CIUDAD_H_ */
