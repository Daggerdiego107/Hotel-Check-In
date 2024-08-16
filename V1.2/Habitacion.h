#ifndef HABITACION_H
#define HABITACION_H
#include <string>
using namespace std;

class Habitacion {
private:
    int numero;
    string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;

protected:
    int getAdultos() const { return adultos; }
    int getInfantes() const { return infantes; }
    double getCredito() const { return credito; }
    double getCargo() const { return cargo; }

public:
    Habitacion();
    Habitacion(int num);
    virtual ~Habitacion()=default; 

    int getNumero() const;
    bool getDisponible() const;
    string getNombre() const; 
    void setNumero(int num);
    bool checkin(string nom, int adu, int inf, double cred);
    bool checkout();
    virtual double getTarifaBase() const; 
    virtual int getCapacidadMaxima() const; 
    bool realizarCargo(double cantidad);
    virtual string toString() const;
    friend double operator+(double total, const Habitacion& h1){
        return total + (h1.getTarifaBase());
    }
};

#endif