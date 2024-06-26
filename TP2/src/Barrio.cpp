#include "Barrio.h"
#include "Parada.h"

Barrio::Barrio(std::string nombre, Lista<Parada*> * paradas, unsigned int comuna) {
    
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

    this->paradas->iniciarCursor();
    while(this->paradas->avanzarCursor()) {
        delete this->paradas->obtenerCursor();
    }
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

unsigned int Barrio::buscarCantidadDeParadasDeLinea(unsigned int colectivo) {
   
    if (colectivo == 0 ) {
        throw "Ingresar linea de colectivo distinta de 0";
    }
   
    Lista<Parada*> * paradas = this->buscarParadasDeLinea(colectivo);
    unsigned int resultado = paradas->getTamanio();
   
    delete paradas;
    return resultado; 
}

unsigned int Barrio::getCantidadDeParadas() {
    return this->paradas->getTamanio();
}

Parada * Barrio::buscarParadaMasCercana(double coordenadaX, double coordenadaY){

	Parada * paradaMasCercana;
	Parada * parada;

	double distancia, distanciaMinima=0;
  
	this->paradas->iniciarCursor();
	while(this->paradas->avanzarCursor()){
		parada = this->paradas->obtenerCursor();
		distancia = this->paradas->obtenerCursor()->calcularDistancia(coordenadaX, coordenadaY);

		if(distancia < distanciaMinima || distanciaMinima ==0){
			distanciaMinima = distancia;
			paradaMasCercana= parada;
		}
        if (distancia == 0) { //Chequeo el caso de distancia nula.
            paradaMasCercana = parada;
            break;
        }
	}

	return paradaMasCercana;
}


Lista<Parada*> * Barrio::buscarParadas(unsigned int colectivo) {
    Lista<Parada*> * paradasEncontradas = new Lista<Parada*>();
    this->paradas->iniciarCursor();
    while (this->paradas->avanzarCursor()) {
        Parada* parada = this->paradas->obtenerCursor();
        if (parada->colectivoEsta(colectivo)) {
            paradasEncontradas->agregar(parada);
        }
    }
    return paradasEncontradas;
}
