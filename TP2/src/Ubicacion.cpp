#include "Ubicacion.h"
#include <cmath>

Ubicacion::Ubicacion(float coordenadaX, float coordenadaY, std::string calle, unsigned int altitudPlano) {
    //TODO validar(?)
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->calle = calle;
    this->altitudPlano = altitudPlano;
}

Ubicacion::~Ubicacion() {

}

float Ubicacion::getCoordenadaX() {
    return this->coordenadaX;
}

float Ubicacion::getCoordenadaY() {
    return this->coordenadaY;
}

std::string Ubicacion::getCalle() {
    return this->calle;
}

unsigned int Ubicacion::getAltitudPlano() {
    return this->altitudPlano;
}

void Ubicacion::setCoordenadaX(float coordenadaX) {
    this->coordenadaX = coordenadaX;
}

void Ubicacion::setCoordenadaY(float coordenadaY) {
    this->coordenadaY = coordenadaY;
}

void Ubicacion::setCalle(std::string calle) {
    this->calle = calle;
}

void Ubicacion::setAltitudPlano(unsigned int altitudPlano) {
    this->altitudPlano = altitudPlano;
}

float Ubicacion::calcularDistancia(float coordX, float coordY) {
    float x1 = this->coordenadaX;
    float y1 = this->coordenadaY;

    return sqrt(pow(coordX - x1, 2) + pow(coordY - y1, 2));
}