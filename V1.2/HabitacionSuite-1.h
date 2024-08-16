#ifndef HABITACION_SUITE_H
#define HABITACION_SUITE_H
#include "Habitacion.h"
using namespace std;

class HabitacionSuite : public Habitacion {
public:
    HabitacionSuite(int num);
    double getTarifaBase() const override;
    string toString() const override;
    int getCapacidadMaxima() const override { 
        return 6; } 
};

#endif
