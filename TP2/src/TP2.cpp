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
#define NOMBRE_ARCHIVO "paradas-de-colectivo.csv"

#include"Lista.h"
#include"Ciudad.h"
#include"Ubicacion.h"
#include"Parada.h"
#include"Barrio.h"

using namespace std;

void incisoUno(Ciudad * ciudad) {
	//TODO implementar funcion
	// 1) Listado de cantidad de paradas por barrio
	// Falta hacer la parte de la consola donde se imprimen los resultados
	// Recorrer todos los barrios de Ciudad
	// y usar funcion Barrio->getCantidadDeParadas()
	cout << "Accediste a inciso uno" << endl;
}

void incisoDos(Ciudad * ciudad) {
	//TODO implementar funcion
	cout << "Accediste a inciso dos" << endl;
}

void incisoTres(Ciudad * ciudad) {
	//TODO implementar funcion
	//3) Listado de paradas de una linea de colectivo
	// Ya están todos los métodos de las clases programados
	// Falta hacer la parte de la consola donde se pide la linea
	// y se imprimen los resultados
	// usar funcion Ciudad->buscarParadas(u int lineaDeColectivo)
}

void incisoCuatro(Ciudad * ciudad) {
	//TODO testear funcion
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
		numeroElegido = atoi(consulta.c_str());
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
void iniciarConsola(Ciudad * ciudad) {
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
			cout << "Numero ingresado erróneo, ingresar del 1 al 5." << endl;
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

	/*
	 * inciso dos nashe
	 */
	//Parada * paradaMasCercana;
	//paradaMasCercana = buenosAires->buscarParadaMasCercana(-58.376842, -34.60700);

	//cout << paradaMasCercana->getUbicacion()->getCalle() << endl;
	//cout << paradaMasCercana->getUbicacion()->getAltitudPlano() << endl;
	//cout << paradaMasCercana->getUbicacion()->getCoordenadaX() << endl;

	/*
	 * si el test de abajo anduvo entonces anda todi
	 */
	//buenosAires->getBarrios()->iniciarCursor();
	//while(buenosAires->getBarrios()->avanzarCursor()){
	//	buenosAires->getBarrios()->obtenerCursor()->getParadas()->iniciarCursor();
	//	while(buenosAires->getBarrios()->obtenerCursor()->getParadas()->avanzarCursor())
	//	cout << buenosAires->getBarrios()->obtenerCursor()->getParadas()->obtenerCursor()->getUbicacion()->getCalle() << endl;

	//}

	delete(parada);
	delete(buenosAires);

	archivo.close();

	return 0;
}
