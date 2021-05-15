#include <string>
#include "Hora.h"
using namespace std;

class Funcion {

public:

	Funcion();
	Funcion(string, int, int, Hora);
	void setCveFuncion(string);
	void setNumPeli(int);
	void setHora(Hora);
	void setSala(int);
	void printFuncion();
	string getCveFuncion() { return cveFuncion; }
	int getNumPeli() { return numPeli; }
	Hora getHora() { return hora; }
	int getSala() { return sala; }

private:

	string cveFuncion;
	int numPeli;
	Hora hora;
	int sala;
};

Funcion::Funcion() {
	cveFuncion = "";
	numPeli = 0;
	Hora hh;
	hora = hh;
	sala = 0;
}


Funcion::Funcion(string clave, int num, int sNum, Hora hh) {

	cveFuncion = clave;
	numPeli = num;
	sala = sNum;
	hora = hh;
}


void Funcion::setCveFuncion(string clave) {

	cveFuncion = clave;
}

void Funcion::setHora(Hora hh) {

	hora = hh;
}

void Funcion::setNumPeli(int num) {

	numPeli = num;
}

void Funcion::setSala(int salaNum) {

	sala = salaNum;
}

void Funcion::printFuncion() {


	cout << "Clave de la funcion: " << cveFuncion << endl;
	cout << "Numero de pelicula: " << numPeli << endl;
	cout << "Hora: " << getHora().getHora() << endl;
	cout << "Sala # " << sala;

}