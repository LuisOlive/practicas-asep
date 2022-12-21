#include "input.h"
#include "magnitudes.h"

#ifndef INTERACCION_H
#define INTERACCION_H

using namespace std;

template <class T = double>
T pedirNumeroEnIntervalo(string prompt, T min, T max)
{
    T x = input<T>(prompt + " [" + to_string(min) + "~" + to_string(max) + "]");

    while (x < min || x > max)
    {
        puts("\nIngrese un valor valido\n");
        x = input<T>(prompt + " [" + to_string(min) + "~" + to_string(max) + "]");
    }

    return x;
}

template <class T = double>
T pedirPositivo(string prompt, T max) {
    return pedirNumeroEnIntervalo<T>(prompt, 0, max);
}

bool pedirBooleano(string prompt) {
    string x = input<string>(prompt + "? [s/n]: ", false);

    return x == "s" || x == "S" || x == "si" || x == "SI" || x == "yes" || x == "YES";
}

bool desea(string prompt) {
    return pedirBooleano(string("Desea ") + prompt); 
}

#endif