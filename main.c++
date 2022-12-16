#include <iostream>
#include <cstdlib>

#include "includes/magnitudes.h"

using namespace std;

int main() {
    tiempo.agregarEquivalencia(1/60, "min");
    cout << "125 min es igual a " << tiempo.convertir(125, "min", "seg") << " seg" << endl;

    // todo esto a fuerzas debe ser en main
    Magnitud distancia = Magnitud("mt");

    distancia.agregarEquivalencia(100, "cm")
        .agregarEquivalencia(3.28084, "ft")
        .agregarEquivalencia(1e-3, "km")
        .agregarEquivalencia(2.54 / 100, "in")
        .agregarEquivalencia(621.37119224e-6, "mi");

    cout << "5 ft es igual a " << distancia.convertir(5, "ft", "cm") << " cm" << endl;
    cout << "5 mi es igual a " << distancia.convertir(5, "mi", "km") << " km" << endl;

    puts(formatoIngenieria(34500, "V"));
    puts(formatoIngenieria(50000000, "VA"));
    puts(formatoIngenieria(5386576, "A"));

    system("pause");
    return 0;
}