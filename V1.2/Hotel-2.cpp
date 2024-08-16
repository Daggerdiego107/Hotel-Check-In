#include "Hotel.h"
#include <vector>
#include <iostream>
using namespace std;

Hotel::Hotel(string nom, int numJunior, int numSuite, int numDeluxe) : nombre(nom) {
    int numIn = 100;
    for (int i=0; i<numJunior; ++i) {
        habitaciones.push_back(new HabitacionJunior(numIn+i));
    }
    for (int i=0; i<numSuite; ++i) {
        habitaciones.push_back(new HabitacionSuite(numIn+i));
    }
    for (int i=0; i<numDeluxe; ++i) {
        habitaciones.push_back(new HabitacionDeluxe(numIn+i));
    }
}

void Hotel::agregarHabitacion(Habitacion* habitacion){
    habitaciones.push_back(habitacion);
}

int Hotel::checkin(string nom, int adu, int inf, double cred, int tipoHabitacion) {
    for (auto& habitacion:habitaciones) {
        if (habitacion->getDisponible() && habitacion->getCapacidadMaxima() >= (adu + inf)) {
            if ((tipoHabitacion == 1 && dynamic_cast<HabitacionJunior*>(habitacion)) ||
                (tipoHabitacion == 2 && dynamic_cast<HabitacionSuite*>(habitacion)) ||
                (tipoHabitacion == 3 && dynamic_cast<HabitacionDeluxe*>(habitacion))) {
                habitacion->checkin(nom, adu, inf, cred);
                return habitacion->getNumero();
            }
        }
    }
    return -1;
}

bool Hotel::checkout(int num) {
    for (auto& habitacion:habitaciones) {
        if (habitacion->getNumero() == num && !habitacion->getDisponible()) {
            return habitacion->checkout();
        }
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int num, double cantidad) {
    for (auto& habitacion:habitaciones) {
        if (habitacion->getNumero() == num && !habitacion->getDisponible()) {
            return habitacion->realizarCargo(cantidad);
        }
    }
    return false;
}

double Hotel::getTotalXTarifaBase() const{
    double total = 0.0;
    for (const auto& habitacion:habitaciones) {
        if (!habitacion->getDisponible()) {
            total+=habitacion->getTarifaBase();
        }
    }
    return total;
}

void Hotel::imprimeOcupacion() {
    cout<<"Ocupación en " <<nombre<< "\n";
    for (const auto& habitacion:habitaciones) {
        if (!habitacion->getDisponible()) {
            cout << habitacion->toString() << "\n";
        }
    }
}   
vector<Habitacion*>& Hotel::getHabitaciones(){
    return habitaciones;
}

Habitacion* Hotel::operator[](int num) {
    if (habitaciones[num - 100]->getNumero() == num) {
        return habitaciones[num - 100];
    }
    return nullptr;
}

ostream& operator<<(ostream& os, const Hotel& hotel) {
    os << "Hotel" << hotel.nombre << endl;
    for (int i = 0; i < hotel.habitaciones.size(); i++) {
        if (!hotel.habitaciones[i]->getDisponible()) {
            os << hotel.habitaciones[i]->toString() << endl;
            }
        }
    os << "Total acumulado por tarifa base: " << hotel.getTotalXTarifaBase() << " pesos." << endl;
    return os;
}
