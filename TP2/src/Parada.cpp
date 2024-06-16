#include "Parada.h"


Parada::Parada(Ubicacion * ubicacion, Lista<unsigned int> * colectivos) {
    if (ubicacion == NULL || colectivos == NULL || colectivos->estaVacia()) {
        throw "Proporcionar ubicacion y colectivos no vacía.";
    }
    this->ubicacion = ubicacion;
    this->colectivos = colectivos;
}

Parada::Parada(Ubicacion * ubicacion) {
    this->ubicacion = ubicacion;
    this->colectivos = new Lista<unsigned int>();
}

Parada::Parada(float coordenadaX, float coordenadaY, std::string calle, unsigned int altitudPlano) {
    Ubicacion * ubicacion = new Ubicacion(coordenadaX, coordenadaY, calle, altitudPlano);
    this->ubicacion = ubicacion;
    this->colectivos = new Lista<unsigned int>();
}

Parada::~Parada() {
    delete this->ubicacion;
    delete this->colectivos;
}

Ubicacion * Parada::getUbicacion() {
    return this->ubicacion;
}

Lista<unsigned int> * Parada::getColectivos() {
    return this->colectivos;
}

void Parada::setUbicacion(Ubicacion * ubicacion) {
    if (ubicacion == NULL) {
        throw "Proporcionar ubicacion no nula.";
    }
    this->ubicacion = ubicacion;
}

void Parada::setColectivos(Lista <unsigned int> * colectivos) {
    if (colectivos == NULL || colectivos->estaVacia()) {
        throw "Proporcionar lista no nula o no vacía.";
    }
    this->colectivos = colectivos;
}

void Parada::agregarColectivo(unsigned int colectivo) {
    if (colectivo == 0) {
        throw "Proporcionar colectivo no nulo.";
    }
    this->colectivos->agregar(colectivo);
}

bool Parada::colectivoEsta(unsigned int colectivo) {
    if (colectivo == 0) {
        throw "Proporcionar colectivo no nulo.";
    }
    bool resultado = false;
    this->colectivos->iniciarCursor();
    while(this->colectivos->avanzarCursor() && (!resultado)) //Recorro hasta que se termine la lista o encuentre el colectivo.
    {
        if (colectivo == this->colectivos->obtenerCursor()) {
            resultado = true;
        }
    }
    return resultado;
}

float Parada::calcularDistancia(float coordX, float coordY) {
    if (coordX == 0 || coordY == 0) {
        throw "Proporcionar coordenadas no nulas.";
    }

    return this->ubicacion->calcularDistancia(coordX, coordY);   

}
