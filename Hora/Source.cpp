/*
	Proyecto 2
	Ricardo López Rodríguez A01066515

	03/02/2018

	Descripción:
	Este programa tomara dos archivos de texto
	para llenar un arreglo de tipo Actor con 20 actores,
	dichos actores necesitan id y nombre del actor. Después 
	se llenara un arreglo de tipo Pelicula con el segundo
	archivo de texto. Todo lo anterior nos permitira la consultación
	de datos, ver las películas de la lista y consultar a todas las funciones

	
*/

#include <iostream>
#include <string>
#include "Pelicula.h"
#include"Actor.h"
#include"Funcion.h"
#include <fstream>
#include <iomanip>

/* Nombre: validacionNumPeli
Parametros: peli[], num, contadorPeliculas
Descripcion: valida que el numero de pelicula dado exista en el archivo
Return: bool pelicula 
*/
bool validacionNumPeli(Pelicula peli[], int num, int contadorPeliculas ) {
	bool pelicula = true;

	for (int i = 0; i < contadorPeliculas; i++) {

		if (num == peli[i].getNumPeli()) {

			return pelicula;
		}
	}

	return pelicula = false;

	
}
/* Nombre: validacionHora
Parametros: hh, mm
Descripcion: se valida que la hora dada por el usuario tenga valores reales
Return: false or true
*/
bool validacionHora(int hh, int mm) {

	if (hh>0 && hh<=23 && mm > 0 && mm <=59) {
		
		return true;
	}

	cout << "LA HORA NO ES VALIDA, INTENTALO DE NUEVO"<<endl;
	return false;

}
/* Nombre: mostrarPelicula
Parametros: funciones [], peliculas[], iteracion, contadorPeliculas
Descripcion: Esta funcion se encarga de de mostrar la pelicula 
Return: string peli
*/
string mostrarPelicula(Funcion funciones[], Pelicula peliculas[],int iteracion,int contadorPeliculas) {

	string pelicula{ "" };

	for (int j = 0; j < contadorPeliculas; j++) {

		if (peliculas[j].getNumPeli() == funciones[iteracion].getNumPeli()) {

			pelicula = peliculas[j].getTitulo();
		}
	}

	return pelicula;
}
/* Nombre: validacionClave
Parametros: funciones[], numFunciones, clave
Descripcion: Esta funcion se encarga de validar la clave dada por el usuario
Return: true or false
*/
bool validacionClave(Funcion funciones[],int numFunciones,string clave) {

	for (int i = 0; i < numFunciones; i++) {

		if (clave == funciones[i].getCveFuncion()) {

			return true;
		}

	}

	cout << "LA CLAVE INGRESADA NO EXISTE, INTENTALO DE NUEVO" << endl;
	return false;
}
/* Nombre: validacionDeId
Parametros: id, actores [], contadorActores
Descripcion: se encarga de validar el id dado por el usuario, comparandolo con el .txt
Return: true or false
*/
bool validacionDeId(int id, Actor actores[], int contadorActores) {

	for (int i = 0; i < contadorActores; i++) {

		if (actores[i].getId() == id) {

			return true;
		}

	}

	cout << "EL ID INGRESADO ES INVALIDO, INTENTALO DE NUEVO" << endl;
	return false;
}
/* Nombre: listaDePeliculasPorActor
Parametros: actoores[],contadorActores, contadorPeliculas, peliculas[], funciones[]
Descripcion: Esta funcion se encarga de buscar el id dada por el usuario y mostrar el titulo y tiempo de cada pelicula donde esta dicho actor
Return:null
*/
void listaDePeliculasPorActor(Actor actores[], int contadorActores, int contadorPeliculas,Pelicula peliculas[],Funcion funciones[]) {

	bool valido = true;
	int id{ 0 };
	string peli{ "" };
	
	do {
		cout << "Ingresa el id del actor con el que deseeas desplegar las peliculas: " << endl;
		cin >> id;

		valido = validacionDeId(id,actores,contadorActores);

	} while (!valido);

	for (int i = 0; i < contadorPeliculas; i++) {


			
		

		for (int j = 0; j < peliculas[i].getCantidadActores(); j++) {

			if (peliculas[i].getListaActores(j) == id) {

				peli = peliculas[i].getTitulo();
				cout << peli << endl;
			}

			if (peliculas[i].getListaActores(j) == id) {

				cout << "Año: " << peliculas[i].getAño()<< endl;
			}
		}

		
	}

}
/* Nombre: consultaPorClave
Parametros: Funcion funciones[], int numFunciones, Pelicula peliculas[], int contadorPeliculas, Actor actores[], int contadorActores
Descripcion: Esta funcion se encarga de mostrar las funciones con todos sus datos basandose en la clave dada
Return: null
*/
void consultaPorClave(Funcion funciones[], int numFunciones, Pelicula peliculas[], int contadorPeliculas, Actor actores[], int contadorActores) {

	string clv{ "" };
	bool valido = true;
	bool existe = true;
	string pelicula{ "" };
	Hora hh;
	int duracion{ 0 };
	string genero{ "" };
	string autor{ "" };

	do {

		cout << "Ingresa la clave de la funcion a mostrar" << endl;
		cin.ignore();
		getline(cin, clv);
		valido = validacionClave(funciones, numFunciones, clv);

	} while (!valido);

	for (int i = 0; i < numFunciones; i++) {

		if (funciones[i].getCveFuncion() == clv) {
			existe = false;

			cout <<"Sala # "<< funciones[i].getSala() << endl;			

			pelicula = mostrarPelicula(funciones, peliculas, i, contadorPeliculas);
			cout << "Pelicula: " << pelicula<<endl;

			hh = funciones[i].getHora();
			cout << "Horario: " << hh.getHora() <<":"<<hh.getMinutos()<< endl;

			for (int p = 0; p < contadorPeliculas; p++) {

				if (peliculas[p].getNumPeli() == funciones[i].getNumPeli()) {

					duracion = peliculas[p].getDuracion();
				}
			}
			//Busqueda del numero de peliculas 
			for (int p = 0; p < contadorPeliculas; p++) {
				//Compara el numero del archivo con el de la funcion
				if (peliculas[p].getNumPeli() == funciones[i].getNumPeli()) {

					genero = peliculas[p].getGenero();

					for (int j = 0; j < contadorActores; j++) {
						//Despliegue de actores
						for (int r = 0; r < peliculas[p].getCantidadActores(); r++) {

							if (peliculas[p].getListaActores(r) == actores[j].getId()) {

								cout << "Actor #" << j + 1 << actores[j].getNombre()<<endl;
							}
						}
					}

					
				}

			}

			cout << "Duracion: " << duracion << " minutos" << endl;
			cout << "Genero: " << genero << endl;
			
		}
	}
}
/* Nombre: funcionesPorHpra
Parametros:Funcion funciones[], int numFunciones, Pelicula peliculas[], int contadorPeliculas
Descripcion: Esta funcion se encarga de mostrar las funciones en la hora dada por e usuario
Return: null
*/
void funcionesPorHora(Funcion funciones[], int numFunciones, Pelicula peliculas[], int contadorPeliculas) {

	int hora{ 0 };
	int minutos{ 0 };
	Hora hr;
	string pelicula{ "" };
	bool existe = true;
	cout << "Ingresa la hora para las funciones que deseeas ver: " << endl;

	//Se pide la hora y se valida
	do {
		cout << "Hora: " << endl;
		cin >> hora;
		cout<<"Minutos: " << endl;
		cin >> minutos;

	} while (!validacionHora(hora,minutos));

	for (int i = 0; i < numFunciones; i++) {

		hr = funciones[i].getHora();

		if (hr.getHora() == hora && hr.getMinutos() == minutos) {
			existe = false;	

			pelicula = mostrarPelicula(funciones, peliculas, i, contadorPeliculas);

			cout << "Pelicula: " << pelicula << endl;
			cout << "Sala# "<<funciones[i].getSala() << endl;
		}

	}

	if (existe) {
		cout << "NO HAY NINGUNA FUNCION CON ESE HORARIO" << endl;
	}


}
/* Nombre: todosLosActores
Parametros: actores[], contadorActores
Descripcion: Esta funcion se encarga de desplegar todos los autores dentro de la lista
Return: null
*/
void todosLosActores(Actor actores[], int contadorActores) {

	for (int i = 0; i < contadorActores; i++) {
		cout << " Id: " <<actores[i].getId();
		cout <<setw(15)<< "Nombre: "<<actores[i].getNombre() << endl;
	}
}
/* Nombre: todasLasFunciones
Parametros: Funcion funciones[],int contador, Pelicula peliculas[], int numPeliculas
Descripcion: Sen encarga de imprimir todas las funciones con sus datos 
Return: null
*/
void todasLasFunciones(Funcion funciones[],int contador, Pelicula peliculas[], int numPeliculas) {

	string pelicula{ "" };
	Hora hr;

	for (int i = 0; i < contador; i++) {

		cout << "CLAVE DE FUNCION: " << funciones[i].getCveFuncion()<<endl;

		for (int j = 0; j < numPeliculas; j++) {

			if (peliculas[j].getNumPeli() == funciones[i].getNumPeli()) {

				pelicula = peliculas[j].getTitulo();
			}			
			
		}

		

		cout << setw(10)<<"Pelicula: " << pelicula;
		cout <<setw(10)<< "Sala #" << funciones[i].getSala();
		hr = funciones[i].getHora();
		cout << setw(10)<<"Hora: " << hr.getHora() << ":" << hr.getMinutos()<< endl;
	}

}
/* Nombre: todasLasPeliculas
Parametros:Pelicula peli[],Actor actores[], int contadorPeliculas, int contadorActores
Descripcion:Se encarga de imprimir todas las peliculas dentro de la lista
Return: null
*/
void todasLasPeliculas(Pelicula peli[],Actor actores[], int contadorPeliculas, int contadorActores) {

	int id { 0 };
	string actor;
	for (int i = 0; i < contadorPeliculas; i++) {

		cout << "Titulo: "<<peli[i].getTitulo() << endl;
		cout << "Año: "<< peli[i].getAño() << endl;
		cout << "Duracion: "<< peli[i].getDuracion() << endl;
		cout << "Genero: "<<peli[i].getGenero()<< endl;
		
		
		for (int j = 0; j < peli[i].getCantidadActores(); j++) {

			id = peli[i].getListaActores(j);

			for (int p = 0; p < contadorActores; p++) {
				
				if (actores[p].getId() == id) {
					actor = actores[p].getNombre();
					cout << "Actor #" << j + 1 << ":  " << actor << endl;
				}
			}
		}

		
	}

}

/* Nombre: CargaFunciones
Parametros:Funcion funciones[], int funcionesNum, Pelicula peli[], int contadorPeliculas
Descripcion: Se encarga de cargar los datos de cada funcion, dependiendo de cuantas quiere el usuario	
Return: null
*/
void CargaFunciones(Funcion funciones[], int funcionesNum, Pelicula peli[], int contadorPeliculas) {
	string claveFuncion{ "" };
	int salaNum{ 0 };
	int peliNum{ 0 };
	int hora{ 0 };
	int minutos{ 0 };
	bool valido = false;

	for (int i = 0; i < funcionesNum; i++) {
		cout << "Ingresa los datos de la funcion #" << i+1<< endl;
		cout << "Cual es la clave de la funcion?" << endl;
		cin.ignore();
		getline(cin, claveFuncion);

		//Ingreso del numero de pelicula con validacion
		do {
			cout << "Cual es el numero de pelicula?" << endl;
			cin >> peliNum;
			valido = validacionNumPeli(peli, peliNum, contadorPeliculas);

			//Validadcion del numero de Pelicula
			if (valido) {

				funciones[i].setNumPeli(peliNum);
			}
			else {
				cerr << "El NUMERO DE PELCULA ES INVALIDO" << endl;
				cout << "Intenta otro numero" << endl;
			}
		} while (!valido);

		cout << "Cual es el numero de la Sala?" << endl;
		cin >> salaNum;
		//Asignacion de hora con validacion
		do {
			cout << "A que hora comienza la funcion?" << endl;
			cout << "Hora: " << endl;
			cin >> hora;
			cout << "Minutos: " << endl;
			cin >> minutos;
		} while (!validacionHora(hora, minutos));

		Hora hrs(hora, minutos);
		funciones[i].setCveFuncion(claveFuncion);
		funciones[i].setSala(salaNum);
		funciones[i].setHora(hrs);
	}

}

/* Nombre: main()
Parametros:
Descripcion: Esta funcion se encarga de desplegar el menu principal y dar las ociones a ejecutar para el usuario
Return: 0
*/
int main() {

	//Declaracion de variables
	int id{ 0 };
	int contadorActores{ 0 };
	int contadorPeliculas{ 0 };
	int numeroDePelicula{ 0 };
	int year{ 0 };
	int newId{ 0 };
	int nuevosActores{ 0 };
	int duracion{ 0 };
	string genero{ "" };
	string titulo{ "" };
	string nombreActor{ "" };
	Actor actor[20];
	Funcion funciones[20];
	Pelicula peliculas[20];
	string archivo1{ "" };
	string archivo2{ "" };
	int funcionesNum{ 0 };
	bool salir{ true };
	int opcion{ 0 };

	cout << "Cual es el nombre del archivo de texto donde estan los actores? (sin el .txt)" << endl;
	cin >> archivo1;
	cout << "Cual es el nombre del archivo de texto donde estan las peliculas?(sin el .txt)" << endl;
	cin >> archivo2;
	archivo1 += ".txt";
	archivo2 += ".txt";
	ifstream actores(archivo1.c_str());
	ifstream pelicula(archivo2.c_str());

	//Carga de datos del archivo actores.txt al areglo de actores.
	while (actores >> id && getline(actores, nombreActor)) {
		actor[contadorActores].setId(id);
		actor[contadorActores++].setNombre(nombreActor);

	}

	//Carga de datos del archivo peliculas.txt al arreglo peliculas
	while (pelicula >> numeroDePelicula >> year >> duracion >> genero >> nuevosActores) {

		for (int i = 0; i < nuevosActores; i++) {

			pelicula >> newId;
			peliculas[contadorPeliculas].agregarActor(newId);
		}
		getline(pelicula, titulo);
		peliculas[contadorPeliculas].setNumPeli(numeroDePelicula);
		peliculas[contadorPeliculas].setAño(year);
		peliculas[contadorPeliculas].setDuracion(duracion);
		peliculas[contadorPeliculas].setGenero(genero);
		peliculas[contadorPeliculas++].setTitulo(titulo);
	}

	//Carga de funciones
	cout << "Cuantas funciones estara disponibles el dia de hoy?";
	cin >> funcionesNum;
	CargaFunciones(funciones, funcionesNum,peliculas,contadorPeliculas);
	//Menu principal
	do {
		cout << "BIENVENIDO AL MENU PRINCIPAL" << endl;
		cout << "1.- Consulta de todos los actores que estan en la lista" << endl;
		cout << "2.- Conuslta de todas las peliculas dentro de la lista" << endl;
		cout << "3.- Consulta de todas las funciones disponibles" << endl;
		cout << "4.- Conuslta de funciones por hora" << endl;
		cout << "5.- Consulta por clave de funcion" << endl;
		cout << "6.- Consulta la lista de peliculas en las que participa un actor" << endl;
		cout << "7.- Salir del programa" << endl;
		cin >> opcion;

		switch (opcion)
		{
		default:
			break;

		case 1:
			todosLosActores(actor, contadorActores);
			break;

		case 2:
			todasLasPeliculas(peliculas, actor, contadorPeliculas, contadorActores);
			break;

		case 3:
			todasLasFunciones(funciones, funcionesNum, peliculas, contadorPeliculas);
			break;

		case 4:
			funcionesPorHora(funciones, funcionesNum, peliculas, contadorPeliculas);
			break;

		case 5:
			consultaPorClave(funciones, funcionesNum, peliculas, contadorPeliculas, actor, contadorActores);
			break;

		case 6:
			listaDePeliculasPorActor(actor, contadorActores, contadorPeliculas, peliculas, funciones);
			break;
		case 7:
			salir = false;
			break;

		}

	} while (salir);

	actores.close();
	pelicula.close();
		return 0;
	
}