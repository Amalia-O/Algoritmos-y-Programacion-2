#include "Barrio.h"

Barrio::Barrio(std::string nombre, Lista<Parada*> * paradas, unsigned int comuna) {
    //TODO validar(?)
    this->nombre = nombre;
    this->paradas = paradas;
    this->comuna = comuna;
} 

Barrio::Barrio(std::string nombre, unsigned int comuna) {
    this->nombre = nombre;
    this->paradas = new Lista<Parada*>();
    this->comuna = comuna;
}

Barrio::~Barrio() {
    delete this->paradas;
}

std::string Barrio::getNombre() {
    return this->nombre;
}

Lista<Parada*> * Barrio::getParadas() {
    return this->paradas;
}

unsigned int Barrio::getComuna() {
    return this->comuna;
}

void Barrio::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Barrio::setParadas(Lista<Parada*> * paradas) {
    delete this->paradas;
    this->paradas = paradas;
}

void Barrio::setComuna(unsigned int comuna) {
    if (comuna == 0 ) {
        throw "Comuna debe ser distinto de 0";
    }
    this->comuna = comuna;
}

void Barrio::agregarParada(Parada * parada) {
    this->paradas->agregar(parada);
}

Lista<Parada*> * Barrio::buscarParadasDeLinea(unsigned int colectivo) {
    if (colectivo == 0 ) {
        throw "Ingresar linea de colectivo distinta de 0";
    }
    Lista<Parada*> * resultado = new Lista<Parada*>();
    Parada * parada;
    this->paradas->iniciarCursor();
    while(this->paradas->avanzarCursor()) { //Recorro todas las paradas del barrio.
        parada = this->paradas->obtenerCursor();
        if (parada->colectivoEsta(colectivo)) {
            resultado->agregar(parada); //Si el colectivo frena en la parada lo agrego a la lista.
        }
    }
    return resultado;
}

unsigned int Barrio::getCantidadDeParadas() {
    return this->paradas->getTamanio();
}