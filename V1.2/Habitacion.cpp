#include "Habitacion.h"
using namespace std;

Habitacion::Habitacion() : numero(0), nombre(""), adultos(0), infantes(0), credito(0.0), cargo(0.0), disponible(true) {}

Habitacion::Habitacion(int num) : numero(num), nombre(""), adultos(0), infantes(0), credito(0.0), cargo(0.0), disponible(true) {}

int Habitacion::getNumero() const {
    return numero;
}

bool Habitacion::getDisponible() const {
    return disponible;
}

string Habitacion::getNombre() const {
    return nombre;
}

void Habitacion::setNumero(int num) {
    numero = num;
}

bool Habitacion::checkin(string nom, int adu, int inf, double cred) {
    int totalPersonas = adu + inf;
    if (disponible && totalPersonas <= getCapacidadMaxima()) {
        nombre = nom;
        adultos = adu;
        infantes = inf;
        credito = cred;
        cargo = 0.0;
        disponible = false;
        return true;
    }
    return false;
}

bool Habitacion::checkout() {
    if (!disponible) {
        nombre = "";
        adultos = 0;
        infantes = 0;
        credito = 0.0;
        cargo = 0.0;
        disponible = true;
        return true;
    }
    return false;
}

bool Habitacion::realizarCargo(double cantidad) {
    if (cantidad > 0 && (cargo + cantidad) <= credito) {
        cargo += cantidad;
        return true;
    }
    return false;
}

double Habitacion::getTarifaBase() const {
    return (getAdultos() * 650.0 + getInfantes() * 250.0);
}

int Habitacion::getCapacidadMaxima() const {
    return 0;
}

string Habitacion::toString() const{
    return "";
}