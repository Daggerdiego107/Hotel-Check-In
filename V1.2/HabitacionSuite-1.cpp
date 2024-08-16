#include "HabitacionSuite.h"
using namespace std;

HabitacionSuite::HabitacionSuite(int num) : Habitacion(num) {}

double HabitacionSuite::getTarifaBase() const {
    return (getAdultos() * 650.0 + getInfantes() * 250.0) * 1.3;
}

string HabitacionSuite::toString() const {
    return to_string(getNumero()) + ", Huesped:" + getNombre() + ", Tarifa Base:" + to_string(getTarifaBase()) + ", Credito:" + to_string(getCredito()) + ", Cargos:" + to_string(getCargo()) + ", Habitación Suite";
}