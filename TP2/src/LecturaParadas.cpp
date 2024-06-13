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
	int contador = 10;
	while(getline(archivo, linea) && contador != 0){

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

		//PRUEBA:
		std::cout << "===================="<< std::endl;
		std::cout << "Entrada: " << 10-contador << std::endl;
		std::cout << "Calle: " << calle << std::endl;
		std::cout << "altPlano: " << altPlano << std::endl;
		std::cout << "Direccion: " << direccion << std::endl;
		std::cout << "CoordX: " << coordX << std::endl;
		std::cout << "CoordY: " << coordY << std::endl;
		std::cout << "Comuna: " << comuna << std::endl;
		std::cout << "Barrio: " << barrio << std::endl;
		std::cout << "L1: " << L1 << std::endl;
		std::cout << "L1_sen: " << l1Sen << std::endl;
		std::cout << "L2: " << L2 << std::endl;
		std::cout << "L2_sen: " << l2Sen << std::endl;
		std::cout << "L3: " << L3 << std::endl;
		std::cout << "L3_sen: " << l3Sen << std::endl;
		std::cout << "L4: " << L4 << std::endl;
		std::cout << "L4_sen: " << l4Sen << std::endl;
		std::cout << "L5: " << l5Sen << std::endl;
		std::cout << "L6: " << L6 << std::endl;
		std::cout << "L6_sen: " << l6Sen << std::endl;
		contador--;
	}

	archivo.close();
}

LecturaParadas::~LecturaParadas() {
	// TODO Auto-generated destructor stub
}

