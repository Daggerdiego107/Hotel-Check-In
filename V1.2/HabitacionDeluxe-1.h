#ifndef HABITACION_DELUXE_H
#define HABITACION_DELUXE_H
#include "Habitacion.h"
using namespace std;

class HabitacionDeluxe : public Habitacion {
public:
    HabitacionDeluxe(int num);
    double getTarifaBase() const override;
    string toString() const override;
    int getCapacidadMaxima() const override { 
        return 8; } 
};

#endif