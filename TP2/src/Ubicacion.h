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
    float coordenadaX;
    float coordenadaY;
    std::string calle;
    unsigned int altitudPlano;

public:
    /*
     * PRE: parametros no nulos. Calle escrita todo en mayuscula.
     * POS: construye el objeto.
    */
    Ubicacion(float coordenadaX, float coordenadaY, std::string calle, unsigned int altitudPlano);

    /*
     * PRE: -
     * POS: libera memoria.
    */
    ~Ubicacion();

    /*
     * PRE: -
     * POS: devuelve el valor de coordenadaX.
    */
    float getCoordenadaX();

    /*
     * PRE: -
     * POS: devuelve el valor de coordenadaY
    */
    float getCoordenadaY();

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
    void setCoordenadaX(float coordenadaX);

    /*
     * PRE: parametro no nulo
     * POS: cambia el valor de coordenadaX
    */
    void setCoordenadaY(float coordenadaY);

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
     * PRE: parametros no nulos
     * POS: devuelve la distancia en modulo entre las coordenadas y la ubicacion
    */
    float calcularDistancia(float coordX, float coordY);
} ;

#endif /* UBICACION_H_*/