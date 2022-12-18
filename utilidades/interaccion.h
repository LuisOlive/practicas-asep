#include "input.h"
#include "output.h"
#include "magnitudes.h"
#include "formatoDeIngenieria.h"
#include "constantes.h"

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

bool desea(string prompt)
{
    string x = input<string>(string("Desea ") + prompt + "? [s/n]: ", false);

    return x == "s" || x == "S" || x == "si" || x == "SI" || x == "yes" || x == "YES";
}

#endif