class Hora {

public:
	Hora();
	Hora(int, int);
	void setHora(int);
	void setMinutos(int);
	int getHora() { return hora; }
	int getMinutos() { return minuto; }
	void printHora();

private:

	int hora;
	int minuto;
};


Hora::Hora() {

	hora = 0;
	minuto = 0;

}

Hora::Hora(int hr, int mm) {

	hora = hr;
	minuto = mm;
}

void Hora::setHora(int hr) {

	hora = hr;
}

void Hora::setMinutos(int mm) {

	minuto = mm;
}

void Hora::printHora() {

	std::cout << hora << ":" << minuto << std::endl;
}

