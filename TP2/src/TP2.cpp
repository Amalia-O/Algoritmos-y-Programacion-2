//============================================================================
// Name        : TP2.cpp
// Author      : Amalia Ochoa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include <iomanip>
#define NOMBRE_ARCHIVO "paradas-de-colectivo.csv"

#include"Lista.h"
#include"Ciudad.h"
#include"Ubicacion.h"
#include"Parada.h"
#include"Barrio.h"

using namespace std;

/*
POS: muestra por consola las distintas consultas posibles para realizar.
	 Se devuelve la consulta elegida.
*/
int consultaConsola(unsigned int mensajeDeConsulta) {
	/*
	 * mensajeDeConsulta = 0 -> Elegir inciso a ejecutar
	 * mensajeDeConsulta = 3 -> Ingresar linea de colect para inciso 3)
	 * mensajeDeConsulta = 5 -> Ingresar Barrio y linea de colect para inciso 5)
	*/
	if (mensajeDeConsulta == 0) {
		//Mensaje de consulta
		cout << "============================================================================" << endl;
		cout << "Ingrese un numero del 1 al 5 para elegir alguna de las siguientes consultas:" << endl;
		cout << "1) Listado de cantidad de paradas por barrio" << endl;
		cout << "2) Parada mas cercana a una coordenada ingresada por teclado" << endl;
		cout << "3) Listado de paradas de una linea de colectivo" << endl;
		cout << "4) Listado de cantidad de paradas por linea de colectivo" << endl;
		cout << "5) Dado un barrio y una linea de colectivo, imprimir las paradas ordenadas por distancia." << endl;
		cout << "" << endl;
		cout << "Ingrese un numero (-1 si desea salir): ";
	}
	else if (mensajeDeConsulta == 3) {
		cout << "============================================================================" << endl;
		cout << "Ingrese una linea de colectivo para ejecutar inciso 3): ";
	}
	else if (mensajeDeConsulta == 5) {
		//TODO implementar mensaje de consulta inciso 5)
	}
	string consulta;
	int numeroElegido;
	cin >> consulta;
	try { //Intento castear la consulta a int.
		numeroElegido = atoi(consulta.c_str());
	}
	catch (...){
		//Si no puedo castear a int, devuelvo -2 para volver a realizar la consulta.
		numeroElegido = -2;
	}
	return numeroElegido;
}

void incisoUno(Ciudad * ciudad) {
	// 1) Listado de cantidad de paradas por barrio
	Barrio * barrio;
	ciudad->getBarrios()->iniciarCursor();
	while(ciudad->getBarrios()->avanzarCursor()) {
		barrio = ciudad->getBarrios()->obtenerCursor();
		cout << "Barrio: " << barrio->getNombre() << "\t" << "Paradas: " << barrio->getCantidadDeParadas() << endl;
	}
}

void incisoDos(Ciudad * ciudad) {
	// 2) Parada más cercana a una coordenada ingresada por teclado
	cout << "============================================================================" << endl;
	
	//Primero pido las coordenadas que se busquen.
	bool seguirPreguntando = true;
	unsigned int cantidadDeNumeros = 0;
	double coordenadas[2];
	char nombreCoordenada;
	
	while (cantidadDeNumeros < 2) {
		if (cantidadDeNumeros == 0){
			nombreCoordenada = 'X';
		}
		else if (cantidadDeNumeros == 1) {
			nombreCoordenada = 'Y';
		}
	
		cout << "Ingrese la coordenada " << nombreCoordenada << " (punto decimal): ";
		string consulta;
		cin >> consulta;
		try { //Intento castear la consulta a double.
			coordenadas[cantidadDeNumeros] = atof(consulta.c_str());
		}
		catch (...){
			//Si no puedo castear a double, salgo de la funcion.
			cout << "Numero ingresado incorrecto." << endl;
		}
		cantidadDeNumeros++;
	}
	
	//Busco la parada mas cercana a las coordenadas introducidas.
	Parada * paradaMasCercana = ciudad->buscarParadaMasCercana(coordenadas[0], coordenadas[1]);
	
	//Con las siguientes 2 lineas, cout imprime hasta 6 decimales.
	std::cout << std::fixed;
    std::cout << std::setprecision(6);
	cout << " " << endl;
	
	//Imprimo por consola la informacion relevante.
	cout << "Parada mas cercana (a x=" << coordenadas[0] << ", y=" << coordenadas[1] << "):" << endl;
	cout << "Direccion: " << paradaMasCercana->getUbicacion()->getCalle() << " " << paradaMasCercana->getUbicacion()->getAltitudPlano() << endl;
	cout << "Sus coordenadas son x=" << paradaMasCercana->getUbicacion()->getCoordenadaX() << " e y=" << paradaMasCercana->getUbicacion()->getCoordenadaY() << "." << endl;
	cout << "Linea/s de colectivo: ";
	
	paradaMasCercana->getColectivos()->iniciarCursor();
	
	while(paradaMasCercana->getColectivos()->avanzarCursor()) { //Imprimo todas las lineas de colectivo de la parada
		cout << paradaMasCercana->getColectivos()->obtenerCursor() << " ";
	}
	cout << endl;
}

void incisoTres(Ciudad * ciudad) {
	//3) Listado de paradas de una linea de colectivo

	int lineaDeColectivo = consultaConsola(3); //Pido al usuario la linea de colectivo.
	if (lineaDeColectivo <= 0) {
		cout << "Linea de colectivo ingresada erronea. Debe ser mayor a 0" << endl;
	}
	else {
		Lista<Parada*> * paradas = ciudad->buscarParadas(lineaDeColectivo);
		Parada * parada;
		paradas->iniciarCursor();
		while (paradas->avanzarCursor()) {
			parada = paradas->obtenerCursor();
			cout << "Calle: " << parada->getUbicacion()->getCalle() << "\t" << "AltPlano: " << parada->getUbicacion()->getAltitudPlano() << "\t" << endl;
		}
		delete paradas;
	}
	
}

void incisoCuatro(Ciudad * ciudad) {
	//4) Listado de cantidad de paradas por linea de colectivo
	/*
	 * Es bien sabido que numéricamente las líneas de colectivo más alta y baja
	 * en la Ciudad de Buenos Aires es la 195 y 1 respectivamente.
	 * Se buscará luego entre esos límites.
	*/
	unsigned int LINEA_BAJA = 1;
	unsigned int LINEA_ALTA = 195;
	unsigned int cantidad;

	for (unsigned int i = LINEA_BAJA; i <= LINEA_ALTA; i++)
	{
		cantidad = ciudad->buscarCantidadDeParadasDeLinea(i);
		if (cantidad != 0) { //Si la cantidad es 0, no la imprimo.
			cout << "Linea: " << i << "\t" << "Cantidad: " << cantidad << endl;
		}
	}
	
}

void incisoCinco(Ciudad * ciudad) {
	//5) Dado un barrio y una linea de colectivo, imprimir las paradas ordenadas por distancia.
	cout << "Accediste a inciso cinco" << endl;

	string nombreBarrio;
	int lineaColectivo;
	double coordenadaX, coordenadaY;

	cout << "Ingrese el nombre del barrio: ";
	cin >> nombreBarrio;

	cout << "Ingrese la coordednada X de referencia ";
	cin >> coordenadaX;

	cout << "Ingrese la coordednada Y de referencia ";
	cin >> coordenadaY;

	cout << "Ingrese la línea de colectivo: ";
	cin >> lineaColectivo;

	Barrio* barrio = ciudad->buscarBarrio(nombreBarrio);
	if (barrio == NULL) {
		cout << "El barrio ingresado no existe." << endl;
		return;
	}

	Lista<Parada*>* paradas = barrio->buscarParadas(lineaColectivo);
	if (paradas->estaVacia()) {
		cout << "No se encontraron paradas para la línea de colectivo en el barrio." << endl;
		return;
	}
	Lista <Parada*> * paradasOrdenadas = new Lista<Parada*>();
	//Ordenar paradas por distancia

	double distanciaReferencia, distanciaMinima;
	unsigned int pos, posMasCercana;

	while(!paradas->estaVacia()){

		paradas->iniciarCursor();
		pos =1;
		distanciaMinima =0;

		while(paradas->avanzarCursor()){

			distanciaReferencia = paradas->obtenerCursor()->getUbicacion()->calcularDistancia(coordenadaX, coordenadaY);

			if(distanciaReferencia < distanciaMinima || distanciaMinima ==0){
				distanciaMinima = distanciaReferencia;
				posMasCercana = pos;
			}
			pos++;
			if(distanciaReferencia == 0){
				break;
			}
		}

		paradasOrdenadas ->agregar(paradas->obtener(posMasCercana));
		paradas->remover(posMasCercana);
	}

	delete(paradas);

	cout << "Paradas ordenadas por distancia: " << endl;
	paradasOrdenadas->iniciarCursor();
	while(paradasOrdenadas->avanzarCursor()){
		cout << "Direccion: " << paradasOrdenadas->obtenerCursor()->getUbicacion()->getCalle() <<" " << paradasOrdenadas->obtenerCursor()->getUbicacion()->getAltitudPlano() << endl;
	}
	delete(paradasOrdenadas);
	
	
}

/*
POS : inicia la consola, por este medio se interactua con el usuario y aquí podrá este realizar sus consultas.
*/
void iniciarConsola(Ciudad * ciudad) {
	//Mensaje de inicio
	cout << "+================================================+" << endl;
	cout << "+           Algoritmos y Programacion 2          +" << endl;
	cout << "+               Trabajo Practico 2               +" << endl;
	cout << "+     Autores: Inaki Teira y Amalia Ochoa        +" << endl;
	cout << "+================================================+" << endl;
	cout << "" << endl;

	bool seguirConsultando = true;
	int numeroElegido;
	while (seguirConsultando) {
		numeroElegido = consultaConsola(0); //Pido al usuario el inciso a ejecutar.
		switch (numeroElegido)
		{
		case -1: //Dejar de buscar
			seguirConsultando = false;
			break;
		case 1:
			incisoUno(ciudad);
			break;
		case 2:
			incisoDos(ciudad);
			break;
		case 3:
			incisoTres(ciudad);
			break;
		case 4:
			incisoCuatro(ciudad);
			break;
		case 5:
			incisoCinco(ciudad);
			break;
		default:
			cout << "Numero ingresado erroneo, ingresar del 1 al 5." << endl;
			cout << "" << endl;
			break;
		}

	}

}

int main() {

	
	/*	Se inicia por leer el archivo .csv y armar una lista con indice de barrios	
		donde cada uno tiene una lista de paradas de colectivo						*/
	ifstream archivo(NOMBRE_ARCHIVO);

	char delimitador = ','; //delimitador de campos

	string linea, calle, direccion, nombreBarrio, barrioControl, coordX,
		coordY, altPlano, comuna, L1, l1Sen, buffer;
	
	Ciudad * buenosAires = new Ciudad();

	//lectura del encabezado
	getline(archivo,linea);

	Parada * parada ;

	while(getline(archivo, linea)){
		
		stringstream stream(linea); //conversion cadena en stream

		getline(stream, calle, delimitador); //lectura de calle

		if(calle[0] == char(34)){ //si el campo tiene comillas
			
			getline(stream, buffer, char(34)); //se lee el campo completo
			calle.append(buffer.erase(0,1)); //se elimina la primer comilla y se concatena el resto de la calle
			getline(stream, buffer, delimitador); //se lee la coma delimitadora
			
		}
		
		getline(stream, altPlano, delimitador); //lectura de la altura

		if(altPlano != ""){
			altPlano.substr(1, altPlano.size()-2); //se elimina la primer y ultima comilla
		
		}

		getline(stream, direccion, delimitador); //lectura de la direccion
		if(direccion[0] == char(34)){ //si el campo tiene comillas
			
			getline(stream, buffer, char(34)); //se lee el campo completo
			direccion.append(buffer.erase(0,1)); //se elimina la primer comilla y se concatena el resto de la direccion
			getline(stream, buffer, delimitador); //se lee la coma delimitadora
			
		}

		if(calle == ""){
			for(int i = 0; i < direccion.size(); i++){
				if(!isdigit(direccion[i])){
					calle+= direccion[i];
				
				}
			}
		}else if(altPlano ==""){
			for(int i = 0; i < direccion.size(); i++){
				if(isdigit(direccion[i])){
					altPlano+= direccion[i];
				
				}
			}
		}

		getline(stream, coordX, delimitador); //lectura de la coordenada x
		getline(stream, coordY, delimitador); //lectura de la coordenada y
		getline(stream, comuna, delimitador); //lectura de la comuna
		if(comuna != ""){
			comuna.substr(1, comuna.size()-2); //se elimina la primer y ultima comilla
		
		}
		getline(stream, nombreBarrio, delimitador); //lectura del nombre del barrio

		parada = new Parada(atof(coordX.c_str()), atof(coordY.c_str()), calle, atoi(altPlano.c_str())); //creacion de la parada

		for(unsigned int i=0;i <6 ; i++){
			getline(stream, L1, delimitador); //lectura de la linea de colectivo
			getline(stream, l1Sen, delimitador); //lectura de la direccion de la linea de colectivo
			if(L1 != ""){
				L1.substr(1, L1.size()-2); //se elimina la primer y ultima comilla
				parada->agregarColectivo(atoi(L1.c_str())); //se agrega la linea de colectivo a la parada
			}
		}

		buenosAires->ubicarParada(nombreBarrio, atoi(comuna.c_str()), parada); //se ubica la parada en el barrio correspondiente

	}

	iniciarConsola(buenosAires);

	
	delete(buenosAires);

	archivo.close();

	return 0;
}
