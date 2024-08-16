#include "Habitacion.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include "Hotel.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    string nombreHotel= "Hotel POO";

    int numJunior, numSuite, numDeluxe;
    cout<<"Número de habitaciones Junior: "; cin>>numJunior;
    cout<<"Número de habitaciones Suite: "; cin>>numSuite;
    cout<<"Número de habitaciones Deluxe: "; cin>>numDeluxe;
    
    Hotel hotel(nombreHotel, numJunior, numSuite, numDeluxe);

    int opcion;
    do{
        
        cout<<"\n*** Menú del " <<nombreHotel<< " ***\n";
        cout<<"1. Check-in\n";
        cout<<"2. Check-out\n";
        cout<<"3. Realizar cargos a habitación\n";
        cout<<"4. Ingresos por tarifas\n";
        cout<<"5. Generar reporte de ocupación\n";
        cout<<"6. Sobrecarga Operador+\n";
        cout<<"7. Sobrecarga Operador[]\n";
        cout<<"8. Sobrecarga Operador<<\n";
        cout<<"9. Salir\n";
        cout<<"\nElige una opción: ";
        cin>>opcion;

        if (opcion==1) {
            string nombre;
            int adultos, infantes, tipoHabitacion;
            double credito;

            cout<<"Nombre del huésped: ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin, nombre);

            cout<<"Número de adultos: "; cin>>adultos;
            cout<<"Número de infantes: "; cin>>infantes;
            cout<<"Cantidad de crédito: "; cin>>credito;

            cout<<"\nElige el tipo de habitación:\n";
            cout<<"1. Habitación Junior\n";
            cout<<"2. Habitación Suite\n";
            cout<<"3. Habitación Deluxe\n";
            cout<<"\nElige una opción: "; cin>>tipoHabitacion;

            int habitacion=hotel.checkin(nombre, adultos, infantes, credito, tipoHabitacion);
            if (habitacion!=-1) {
                cout<<"Check-in exitoso en la habitación "<<habitacion<<".\n";
            } else {
                cout<<"No hay habitaciones disponibles o la capacidad es insuficiente.\n";
            }
        } else if (opcion==2) {
            cout<<"Número de la habitación: ";
            int numero; cin>>numero;
            if (hotel.checkout(numero)) {
                cout<<"Check-out exitoso.\n";
            } else {
                cout<<"La habitación no está ocupada.\n";
            }
        } else if (opcion==3) {
            cout<<"Número de la habitación: ";
            int numero; cin>>numero;
            cout<<"Cantidad del cargo: ";
            double cantidad; cin>>cantidad;
            if (hotel.realizarCargosHabitacion(numero, cantidad)) {
                cout<<"Cargo creado con éxito.\n";
            } else {
                cout<<"No se pudo crear el cargo (la habitación no está ocupada o la cantidad excede el crédito disponible).\n";
            }
        } else if (opcion==4) {
            cout<<"Los ingresos por tarifas son: " <<hotel.getTotalXTarifaBase()<< " pesos.\n";
        } else if (opcion==5) {
            hotel.imprimeOcupacion();
        } else if (opcion==6){
            double totTarifaBase=0.0;
            double tarifaBaseAcumulado = totTarifaBase + *hotel.getHabitaciones()[0];
            cout<< "Total tarifa base con sobrecarga: " << tarifaBaseAcumulado << " pesos." << endl;
            totTarifaBase=0.0;
            tarifaBaseAcumulado = totTarifaBase + *hotel.getHabitaciones()[0] + *hotel.getHabitaciones()[1] + *hotel.getHabitaciones()[2];
            cout<< "Total tarifa base con sobrecarga de Junior, Suite y Deluxe: " << tarifaBaseAcumulado << " pesos." << endl;
            } else if (opcion==7){
                Habitacion* habitacion = hotel[100];
if (habitacion != nullptr) {
    cout << habitacion->toString() << endl;
} else {
    cout << "Habitación no encontrada" << endl;
}
        } else if(opcion==8){
            cout<<hotel<<endl;
        }
        else if (opcion == 9) {
            break;
        } else {
            cout<<"Opción no válida. Por favor, elige una opción del menú.\n";
        }
    }while(opcion != 9);

    return 0;
};