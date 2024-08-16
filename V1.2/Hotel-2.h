#ifndef HOTEL_H
#define HOTEL_H
#include "Habitacion.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Hotel {
private:
    vector <Habitacion*> habitaciones;
    string nombre;
    int numJunior, numSuite, numDeluxe;

public:
    Hotel(string nom, int numJunior, int numSuite, int numDeluxe);
    int checkin(string nom, int adu, int inf, double cred, int tipoHabitacion);
    bool checkout(int num);
    bool realizarCargosHabitacion(int num, double cantidad);
    double getTotalXTarifaBase() const;
    void imprimeOcupacion();
    void agregarHabitacion(Habitacion* habitaciones);
    vector<Habitacion*>& getHabitaciones();
    Habitacion* operator[](int num);
    friend ostream& operator<<(ostream& os, const Hotel& hotel);
};

#endif
