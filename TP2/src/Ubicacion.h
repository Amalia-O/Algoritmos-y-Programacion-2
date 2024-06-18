/*
 * Ubicacion.h
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#ifndef UBICACION_H_
#define UBICACION_H_

#include <string>

class Ubicacion {
private:
    double coordenadaX;
    double coordenadaY;
    std::string calle;
    unsigned int altitudPlano;

public:
    /*
     * PRE: parametros no nulos. Calle escrita todo en mayuscula.
     * POS: construye el objeto.
    */
    Ubicacion(double coordenadaX, double coordenadaY, std::string calle, unsigned int altitudPlano);

    /*
     * PRE: -
     * POS: libera memoria.
    */
    ~Ubicacion();

    /*
     * PRE: -
     * POS: devuelve el valor de coordenadaX.
    */
    double getCoordenadaX();

    /*
     * PRE: -
     * POS: devuelve el valor de coordenadaY
    */
    double getCoordenadaY();

    /*
     * PRE: -
     * POS: devuelve el valor de calle
    */
    std::string getCalle();

    /*
     * PRE: -
     * POS: devuelve el valor de altitudPlano
    */
    unsigned int getAltitudPlano();

    /*
     * PRE: parametro no nulo
     * POS: cambia el valor de coordenadaX
    */
    void setCoordenadaX(double coordenadaX);

    /*
     * PRE: parametro no nulo
     * POS: cambia el valor de coordenadaX
    */
    void setCoordenadaY(double coordenadaY);

    /*
     * PRE: parametro no nulo y escrito en mayuscula
     * POS: cambia el valor de calle
    */
    void setCalle(std::string calle);

    /*
     * PRE: parametro no nulo
     * POS: cambia el valor de altitudPlano
    */
    void setAltitudPlano(unsigned int altitudPlano);

    /*
     * PRE: parametros no nulo
     * POS: devuelve la distancia en modulo
    */
    double calcularDistancia(double coordX, double coordY);
} ;

#endif /* UBICACION_H_*/
