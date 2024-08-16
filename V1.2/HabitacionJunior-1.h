#ifndef HABITACION_JUNIOR_H
#define HABITACION_JUNIOR_H
#include "Habitacion.h"
using namespace std;

class HabitacionJunior : public Habitacion {
public:
    HabitacionJunior(int num);
    double getTarifaBase() const override;
    string toString() const override;
    int getCapacidadMaxima() const override { 
        return 4; } 
};

#endif
