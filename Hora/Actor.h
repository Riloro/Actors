#include <string>
using namespace std;
class Actor {

public:

	Actor();
	Actor(int, string);
	void setId(int);
	void setNombre(string);
	int getId() { return id; }
	string getNombre() { return nombre; }

private:
	int id;
	string nombre;

};

Actor::Actor() {

	id = 0;
	nombre = "";
}

Actor::Actor(int iId, string sNombre) {

	id = iId;
	nombre = sNombre;
}

void Actor::setId(int iId) {

	id = iId;
}

void Actor::setNombre(string sNombre) {

	nombre = sNombre;
}