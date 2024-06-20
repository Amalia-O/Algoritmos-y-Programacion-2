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
	//TODO falta agregar el barrio de cada parada (hay que cambiar las funciones para eso).
	//y tal vez coordenadas y comuna
	//Habría que buscar en cada carrio las paradas dentro de acá...
	//(o sea 2 while anidados pero podría modularizar...)
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
	//TODO implementar funcion
	cout << "Accediste a inciso cinco" << endl;
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

	char delimitador = ',';

	string linea, calle, direccion, nombreBarrio, barrioControl, coordX,
		coordY, altPlano, comuna, L1, l1Sen;


	Ciudad * buenosAires = new Ciudad();

	//lectura del encabezado
	getline(archivo,linea);

	Parada * parada ;

	while(getline(archivo, linea)){
		stringstream stream(linea); //convierto cadena en stream

		//extraigo todos los valores
		getline(stream, calle, delimitador);
		getline(stream, altPlano, delimitador);
		getline(stream, direccion, delimitador);
		getline(stream, coordX, delimitador);
		getline(stream, coordY, delimitador);
		getline(stream, comuna, delimitador);
		getline(stream, nombreBarrio, delimitador);

		if(altPlano ==""){

			if(isdigit(direccion[0])){
				for( int i =0; (i < direccion.size()) &&  (direccion[i]!= ' '); i++){
					if(isdigit(direccion[i])){
						altPlano+= direccion[i];
					}
				}
			}else if(isdigit(direccion[direccion.size()-1])){
				for( int i =direccion.size()-1 ; (i>0) &&  (direccion[i]!= ' '); i--){
					if(isdigit(direccion[i])){
						altPlano.insert(0,1, direccion[i]);
					}
				}
			}
		}

		parada = new Parada( atof(coordX.c_str()), atof(coordY.c_str()), calle, atof(altPlano.c_str()));

		for(unsigned int i=0; i< 6; i++){
			getline(stream, L1, delimitador);
			getline(stream, l1Sen, delimitador);
			if(L1 != ""){
				parada->agregarColectivo((unsigned int)atof(L1.c_str()));
			}
		}


		if(nombreBarrio != ""){
			buenosAires->ubicarParada(nombreBarrio, (unsigned int)atoi(comuna.c_str()), parada);
		}

	}

	iniciarConsola(buenosAires);

	delete(parada);
	delete(buenosAires);

	archivo.close();

	return 0;
}
