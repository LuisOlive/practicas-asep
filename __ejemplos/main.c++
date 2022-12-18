#include <iostream>
#include <cstdlib>

#include "includes/utilidades/magnitudes.h"
#include "includes/utilidades/formatoDeIngenieria.h"

using namespace std;

int main()
{
    usarMagnitudes(); // muy importante

    cout << "5 ft es igual a " << distancia.convertir(5, "ft", "cm") << " cm" << endl;
    cout << "5 mi es igual a " << distancia.convertir(5, "mi", "km") << " km" << endl;

    cout << "1 in es igual a " << distancia.convertir(1, "in", "cm") << " cm" << endl;
    cout << "5 cm2 es igual a " << distancia.convertir(5, "cm2", "cmil") << " cmil" << endl;
    cout << "5 cm2 es igual a " << area.convertir(5, "cm2", "cmil") << " cmil" << endl;

    puts(formatoIngenieria(-34500, "V"));
    puts(formatoIngenieria(50000000, "VA"));
    puts(formatoIngenieria(-5386576, "A"));
    puts(formatoIngenieria(.0000000345, "A"));
    puts(formatoIngenieria(-.00789, "S"));
    puts(formatoIngenieria(.06789, "S"));
    puts(formatoIngenieria(.789, "km"));
    puts(formatoIngenieria(5.789, "km"));

    string sigla1 = distancia.pedirUnidad("Que unidad desea trnasformar?");
    double n = input("Que cantidad?: ");
    string sigla2 = distancia.pedirUnidad("A que lo unidad desea transformar?");

    cout << n << " " << sigla1 << " es igual a " << distancia.convertir(n, sigla1, sigla2) << " " << sigla2 << endl;

    area.pedirEnUnidad("Ingrese un area", "cmil");

    system("pause");
    return 0;
}