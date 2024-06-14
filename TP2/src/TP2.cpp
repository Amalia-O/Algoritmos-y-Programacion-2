//============================================================================
// Name        : TP2.cpp
// Author      : Amalia Ochoa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "paradas-de-colectivo.csv"

#include"LecturaParadas.h"
#include "Ubicacion.h"

using namespace std;

void incisoUno() {
	//TODO implementar funcion
	cout << "Accediste a inciso uno" << endl;
}

void incisoDos() {
	//TODO implementar funcion
	cout << "Accediste a inciso dos" << endl;
}

void incisoTres() {
	//TODO implementar funcion
	cout << "Accediste a inciso tres" << endl;
}

void incisoCuatro() {
	//TODO implementar funcion
	cout << "Accediste a inciso cuatro" << endl;
}

void incisoCinco() {
	//TODO implementar funcion
	cout << "Accediste a inciso cinco" << endl;
}

/*
POS: muestra por consola las distintas consultas posibles para realizar. 
	 Se devuelve la consulta elegida.
*/
int consultaConsola() {
	//Mensaje de consulta
	cout << "============================================================================" << endl;
	cout << "Ingrese un numero del 1 al 5 para elegir alguna de las siguientes consultas:" << endl;
	cout << "1) Listado de cantidad de paradas por barrio" << endl;
	cout << "2) Parada más cercana a una coordenada ingresada por teclado" << endl;
	cout << "3) Listado de paradas de una línea de colectivo" << endl;
	cout << "4) Listado de cantidad de paradas por linea de colectivo" << endl;
	cout << "5) Dado un barrio y una línea de colectivo, imprimir las paradas ordenadas por distancia." << endl;
	cout << "" << endl;
	cout << "Ingrese un numero (-1 si desea salir): ";
	string consulta;
	int numeroElegido;
	cin >> consulta;
	try { //Intento castear la consulta a int. 
		numeroElegido = stoi(consulta);
	}
	catch (...){ 
		//Si no puedo castear a int, devuelvo -2 para volver a realizar la consulta.
		numeroElegido = -2;
	}
	return numeroElegido;
}

/*
POS : inicia la consola, por este medio se interactua con el usuario y aquí podrá este realizar sus consultas.
*/
void iniciarConsola() {
	//Mensaje de inicio
	cout << "+================================================+" << endl;
	cout << "+           Algoritmos y Programación 2          +" << endl;
	cout << "+               Trabajo Práctico 2               +" << endl;
	cout << "+     Autores: Iñaki Teira y Amalia Ochoa        +" << endl;
	cout << "+================================================+" << endl;
	cout << "" << endl;

	bool seguirConsultando = true;
	int numeroElegido;
	while (seguirConsultando) {
		numeroElegido = consultaConsola();
		switch (numeroElegido)
		{
		case -1: //Dejar de buscar
			seguirConsultando = false;
			break;
		case 1:
			incisoUno();
			break;
		case 2:
			incisoDos();
			break;
		case 3:
			incisoTres();
			break;
		case 4:
			incisoCuatro();
			break;
		case 5:
			incisoCinco();
			break;
		default:
			cout << "Numero ingresado erróneo, ingresar del 1 al 5." << endl;
			cout << "" << endl;
			break;
		}

	}
	
}

int main() {

	//iniciarConsola();

	ifstream archivo(NOMBRE_ARCHIVO);
	char delimitador = ',';
	string linea, calle, direccion, barrio, barrioControl, coordX, coordY, altPlano, comuna, L1, l1Sen;


	//Lista<Barrio*> * indice = new Lista<Barrio*>();

	//lectura del encabezado
	getline(archivo,linea);

	Barrio * barrioLista;
	Parada * parada;

	barrioControl = "";

	while(getline(archivo, linea)){
		stringstream stream(linea); //convierto cadena en stream

		//extraigo todos los valores
		getline(stream, calle, delimitador);
		getline(stream, altPlano, delimitador);
		getline(stream, direccion, delimitador);
		getline(stream, coordX, delimitador);
		getline(stream, coordY, delimitador);
		getline(stream, comuna, delimitador);
		getline(stream, barrio, delimitador);

		if(barrioControl != barrio){
			//indice->agregar(barrioLista);
			//barrioLista = new Barrio(barrio, (unsigned int)atof(comuna.c_str()));
			barrioControl = barrio;
		}

		//parada = new Parada( (float)atof(coordX.c_str()), (float)atof(coordY.c_str()), calle, (float)atof(altPlano.substr(1, altPlano.size()-2).c_str()));

		for(unsigned int i=0; i< 6; i++){
			getline(stream, L1, delimitador);
			getline(stream, l1Sen, delimitador);
			if(L1 != ""){
				L1 = L1.substr(1, L1.size()-2);
				//parada->agregarColectivo((unsigned int)atof(L1.c_str()));
			}
		}

		//barrioLista->agregarParada(parada);

	}

	//delete(barrioLista);
	//delete(parada);
	//delete(indice);

	archivo.close();
	return 0;
}
