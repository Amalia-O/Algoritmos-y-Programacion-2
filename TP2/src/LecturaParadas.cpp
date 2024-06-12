/*
 * LecturaParadas.cpp
 *
 *  Created on: 12/06/2024
 *      Author: algo2
 */

#include "LecturaParadas.h"
#include<iostream>
#include<sstream>
#include <fstream>


LecturaParadas::LecturaParadas() {
	std::ifstream archivo(NOMBRE_ARCHIVO);
	char delimitador = ',';
	std::string linea, calle, direccion, barrio, coordX,
		coordY, altPlano, comuna, L1, L2, L3, L4,L5,L6,
		l1Sen, l2Sen, l3Sen, l4Sen, l5Sen, l6Sen;

	//lectura del encabezado
	getline(archivo,linea);

	while(getline(archivo, linea)){

		std::stringstream stream(linea); //convierto cadena en stream

		//extraigo todos los valores
		getline(stream, calle, delimitador);
		getline(stream, altPlano, delimitador);
		getline(stream, direccion, delimitador);
		getline(stream, coordX, delimitador);
		getline(stream, coordY, delimitador);
		getline(stream, comuna, delimitador);
		getline(stream, barrio, delimitador);
		getline(stream, L1, delimitador);
		getline(stream, l1Sen, delimitador);
		getline(stream, L2, delimitador);
		getline(stream, l2Sen, delimitador);
		getline(stream, L3, delimitador);
		getline(stream, l3Sen, delimitador);
		getline(stream, L4, delimitador);
		getline(stream, l4Sen, delimitador);
		getline(stream, L5, delimitador);
		getline(stream, l5Sen, delimitador);
		getline(stream, L6, delimitador);
		getline(stream, l6Sen, delimitador);
		}

	archivo.close();
}

LecturaParadas::~LecturaParadas() {
	// TODO Auto-generated destructor stub
}

