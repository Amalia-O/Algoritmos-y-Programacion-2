#include "Ubicacion.h"
#include <cmath>
#include<iostream>

Ubicacion::Ubicacion(double coordenadaX, double coordenadaY, std::string calle, unsigned int altitudPlano) {
    //TODO validar(?)
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->calle = calle;
    this->altitudPlano = altitudPlano;
}

Ubicacion::~Ubicacion() {

}

double Ubicacion::getCoordenadaX() {
    return this->coordenadaX;
}

double Ubicacion::getCoordenadaY() {
    return this->coordenadaY;
}

std::string Ubicacion::getCalle() {
    return this->calle;
}

unsigned int Ubicacion::getAltitudPlano() {
    return this->altitudPlano;
}

void Ubicacion::setCoordenadaX(double coordenadaX) {
    this->coordenadaX = coordenadaX;
}

void Ubicacion::setCoordenadaY(double coordenadaY) {
    this->coordenadaY = coordenadaY;
}

void Ubicacion::setCalle(std::string calle) {
    this->calle = calle;
}

void Ubicacion::setAltitudPlano(unsigned int altitudPlano) {
    this->altitudPlano = altitudPlano;
}

double Ubicacion::calcularDistancia(double coordX, double coordY) {
    double x1 = this->coordenadaX;
    double y1 = this->coordenadaY;
    
    return sqrt(pow(coordX - x1, 2) + pow(coordY - y1, 2));
}
