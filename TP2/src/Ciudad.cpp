#include "Ciudad.h"
#include <iostream>
#include"Barrio.h"
#include "Parada.h"

Ciudad::Ciudad() {
    this->barrios = new Lista<Barrio*>();
}

Ciudad::~Ciudad() {
    delete this->barrios;
}

Lista<Barrio*> * Ciudad::getBarrios() {
    return this->barrios;
}

void Ciudad::setBarrios(Lista<Barrio*> * barrios) {
    delete this->barrios;
    this->barrios = barrios;
}

bool Ciudad::barrioEnLista(std::string nombre) {

    bool resultado = false;
    this->barrios->iniciarCursor();
    while(this->barrios->avanzarCursor() && (!resultado)) {
        if (nombre == this->barrios->obtenerCursor()->getNombre()) { 
            //TODO si no funciona con ==, probar con lo siguiente:
            //nombre.compare(this->barrios->obtenerCursor()->getNombre()) == 0
            //.compare() devuelve 0 si ambos strings son iguales
            resultado = true;
        }
    }
    return resultado;
}

void Ciudad::agregarBarrio(Barrio * barrio) {

	if (this->barrioEnLista(barrio->getNombre())) {
        throw "El barrio ya esta en la lista";
    }
    this->barrios->agregar(barrio);
}

Lista<Parada*> * Ciudad::buscarParadas(unsigned int colectivo) {
    if (colectivo == 0) {
        throw "Proporcionar linea de colectivo distinta de 0"; 
    }
    Lista<Parada*> * resultado = new Lista<Parada*>();
    Lista<Parada*> * paradasParaAgregar;
    this->barrios->iniciarCursor();
    while(this->barrios->avanzarCursor()) {
        paradasParaAgregar = this->barrios->obtenerCursor()->buscarParadasDeLinea(colectivo); //Busco todas las paradas de la linea en el barrio.
        resultado->concatenarLista(paradasParaAgregar);
    }
    return resultado;
}


void Ciudad::agregarParadaAlBarrio(std::string barrio, unsigned int comuna, Parada * parada){
    if (parada == NULL) {
        throw "Proporcionar parada no nula";
    }
    if (barrio == "") {
        throw "Proporcionar nombre de barrio no vacio";
    }
    if (comuna == 0) {
        throw "Proporcionar comuna distinta de 0";
    }

	this->getBarrios()->iniciarCursor();
	while(this->getBarrios()->avanzarCursor()){

		if(this->getBarrios()->obtenerCursor()->getNombre()== barrio  && this->getBarrios()->obtenerCursor()->getComuna()== comuna ){
			this->getBarrios()->obtenerCursor()->agregarParada(parada);
		}
	}
}

void Ciudad:: ubicarParada(std::string barrio, unsigned int comuna, Parada *parada){
    if (parada == NULL) {
        throw "Proporcionar parada no nula";
    }
    if (barrio == "") {
        throw "Proporcionar nombre de barrio no vacio";
    }
    if (comuna == 0) {
        throw "Proporcionar comuna distinta de 0";
    }

    if(this->barrioEnLista(barrio)){
        this->agregarParadaAlBarrio(barrio, comuna, parada);
    }else{
        Barrio * nuevoBarrio = new Barrio(barrio, comuna);
        nuevoBarrio->agregarParada(parada);
        this->agregarBarrio(nuevoBarrio);
    }
}


 Parada* Ciudad::buscarParadaMasCercana(float coordX, float coordY){

    if (coordX == 0 || coordY == 0) {
        throw "Proporcionar coordenadas validas";
    }

    Parada * paradaAux = NULL;
    Parada * paradaMasCercana;
    double distancia = 0;
    double distanciaMinima = 0;
    this->barrios->iniciarCursor();
    while(this->barrios->avanzarCursor()) {
        paradaAux = this->barrios->obtenerCursor()->buscarParadaMasCercana(coordX, coordY);
        if (paradaAux != NULL) {

        	distancia = paradaAux->calcularDistancia(coordX, coordY);
        	//std::cout << distancia << std::endl;
        	std::cout << "distancia =" << distancia << std::endl;
        	if (distanciaMinima == 0 || distancia < distanciaMinima) {
                distanciaMinima = distancia;
                paradaMasCercana = paradaAux;
            }

        }
    }
    return paradaMasCercana;
 }





