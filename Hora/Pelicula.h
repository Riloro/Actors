#include<string>
using namespace std;

class Pelicula {

public:
	Pelicula();
	void setNumPeli(int);
	int getNumPeli() { return numPeli; }
	void setTitulo(string);
	string getTitulo() { return titulo; }
	void setAño(int);
	int getAño() { return año; }
	void setDuracion(int);
	int getDuracion() { return duracion; }
	void setGenero(string);
	string getGenero() { return genero; }
	int getCantidadActores() { return cantidadActores; }
	int getListaActores(int);
	bool agregarActor(int);
private:
	int numPeli;
	string titulo;
	int año;
	int duracion;
	string genero;
	int cantidadActores;
	int listaActores[10];

};

Pelicula::Pelicula() {

	numPeli = 0;
	titulo = "";
	año = 0;
	duracion = 0;
	genero = "";
	cantidadActores = 0;

}

void Pelicula::setNumPeli(int peli) {

	numPeli = peli;
}

void Pelicula::setTitulo(string title) {

	titulo = title;

}

void Pelicula::setAño(int an) {

	año = an;
}

void Pelicula::setDuracion(int dura) {

	duracion = dura;
}

void Pelicula::setGenero(string gen) {

	genero = gen;
}

int Pelicula::getListaActores(int i) {

	return listaActores[i];
}

bool Pelicula::agregarActor(int id) {


	//agregar un actor al array
	for (int i = 0; i <cantidadActores; i++) {

		if (listaActores[i] == id) {


			return false;

		}
	}

	if (cantidadActores < 11) {

		listaActores[cantidadActores++] = id;
		return true;
	}
	else {

		return false;
	}


	//regresal un bool de confirmacion 

}