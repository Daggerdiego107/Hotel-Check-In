#include "HabitacionJunior.h"
using namespace std;

HabitacionJunior::HabitacionJunior(int num) : Habitacion(num) {}

double HabitacionJunior::getTarifaBase() const {
    return (getAdultos() * 650.0 + getInfantes() * 250.0) * 1.2;
}

string HabitacionJunior::toString() const {
    return to_string(getNumero()) + ", Huesped:" + getNombre() + ", Tarifa Base:" + to_string(getTarifaBase()) + ", Credito:" + to_string(getCredito()) + ", Cargos:" + to_string(getCargo()) + ", Habitación Junior";
}
