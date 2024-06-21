#include "Ciudad.h"
#include <iostream>
#include"Barrio.h"
#include "Parada.h"

Ciudad::Ciudad() {
    
    this->barrios = new Lista<Barrio*>();
}

Ciudad::~Ciudad() {
    
    this->barrios->iniciarCursor();
    
    while(this->barrios->avanzarCursor()) {
    
        delete this->barrios->obtenerCursor();
    }
    
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

unsigned int Ciudad::buscarCantidadDeParadasDeLinea(unsigned int colectivo) {
    
    unsigned int resultado = 0;
    this->barrios->iniciarCursor();
    
    while(this->barrios->avanzarCursor()) {
    
        //Busco para cada barrio la cantidad de paradas de la linea y sumo
        resultado += this->barrios->obtenerCursor()->buscarCantidadDeParadasDeLinea(colectivo);
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

		if(this->getBarrios()->obtenerCursor()->getNombre()== barrio){
			this->getBarrios()->obtenerCursor()->agregarParada(parada);
		}
	}
}

void Ciudad:: ubicarParada(std::string barrio, unsigned int comuna, Parada *parada){
    if (parada == NULL) {
        throw "Proporcionar parada no nula";
    }
    if (barrio == "") {
        barrio = "Sin nombre";
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


Parada* Ciudad::buscarParadaMasCercana(double coordX, double coordY){

    if (coordX == 0 || coordY == 0) {
        throw "Proporcionar coordenadas validas";
    }

    Parada * paradaAux = NULL;
    Parada * paradaMasCercana;
    double distancia = 0;
    double distanciaMinima = 0;
    bool seguirBuscando = true;
    
    this->barrios->iniciarCursor();
    while(this->barrios->avanzarCursor() && seguirBuscando) {
        paradaAux = this->barrios->obtenerCursor()->buscarParadaMasCercana(coordX, coordY);
        if (paradaAux != NULL) {
            
        	distancia = paradaAux->calcularDistancia(coordX, coordY);
        	if (distanciaMinima == 0 || distancia < distanciaMinima) {
                distanciaMinima = distancia;
                paradaMasCercana = paradaAux;
            }
            if (distancia == 0) {
                paradaMasCercana = paradaAux;
                seguirBuscando = false;
            }
        }
    }
    return paradaMasCercana;
}


Barrio* Ciudad::buscarBarrio(std::string nombre) {
    
    this->barrios->iniciarCursor();
    while (this->barrios->avanzarCursor()) {
        if (nombre == this->barrios->obtenerCursor()->getNombre()) {
            return this->barrios->obtenerCursor();
        }
    }
    return NULL; // Barrio not found
}




