/*
 * Parada.h
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#ifndef PARADA_H_
#define PARADA_H_

#include "Ubicacion.h"
#include "Lista.h"
#include <string>

class Parada {
private:
    Ubicacion * ubicacion;
    Lista<unsigned int> * colectivos;
public:
    /*
     * PRE: parametros no nulos.
     * POS: inicia el objeto.
    */
    Parada(Ubicacion * ubicacion, Lista<unsigned int>  * colectivos);

    /*
     * PRE: ubicacion no nula
     * POS: inicia el objeto con ubicacion, y lista de colectivos vacía.
    */
    Parada(Ubicacion * ubicacion);

    /*
     * PRE: parametros no nulos.
     * POS: inicia el objeto con ubicacion segun parametros, y lista de colectivos vacia
    */
    Parada(float coordenadaX, float coordenadaY, std::string calle, unsigned int altitudPlano);
    
    /*
     * PRE: -
     * POS: libera la memoria.
    */
    ~Parada();

    /*
     * PRE: -
     * POS: devuelve la ubicacion
    */
    Ubicacion * getUbicacion();

    /*
     * PRE: -
     * POS: devuelve la lista de colectivos
    */
    Lista<unsigned int> * getColectivos();

    /*
     * PRE: ubicacion no nula
     * POS: cambia el valor de la ubicacion
    */
   void setUbicacion(Ubicacion * ubicacion);

    /*
     * PRE: lista no nula
     * POS: cambia la lista por otra
    */
   void setColectivos(Lista<unsigned int> * colectivos);

    /*
     * PRE: numero no nulo
     * POS: agrega el colectivo al final de la lista de colectivos.
    */
   void agregarColectivo(unsigned int colectivo);


} ;

#endif /* PARADA_H_*/