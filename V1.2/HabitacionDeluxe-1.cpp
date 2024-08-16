#include "HabitacionDeluxe.h"
using namespace std;

HabitacionDeluxe::HabitacionDeluxe(int num) : Habitacion(num) {}

double HabitacionDeluxe::getTarifaBase() const {
    return (getAdultos() * 650.0 + getInfantes() * 250.0) * 1.5;
}

string HabitacionDeluxe::toString() const {
    return to_string(getNumero()) + ", Huesped:" + getNombre() + ", Tarifa Base:" + to_string(getTarifaBase()) + ", Credito:" + to_string(getCredito()) + ", Cargos:" + to_string(getCargo()) + ", Habitación Deluxe";
}
