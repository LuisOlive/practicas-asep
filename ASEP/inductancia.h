#include "../classes/Linea.h"

#ifndef INDUCTANCIA_H
#define INDUCTANCIA_H

void inductancia()
{
    puts("Definicion de la linea:");

    Linea l;

    hr();

    cout << "D_eq de la linea: " << fmtIng(l.rmg(), "mt") << endl;
    cout << "D_S de la linea: " << fmtIng(l.dmg(), "mt") << endl;
    cout << "D_SL de la linea: " << fmtIng(l.dSL(), "mt") << endl;
    cout << "Inductancia unitaria: " << fmtIng(l.inductanciaUnitaria(), "H/mt") << endl;
    cout << "Inductancia total de la linea: " << fmtIng(l.inductancia(), "H") << endl;
    cout << "Reactancia total de la linea: " << fmtIng(l.reactanciaInductiva(), "ohm") << endl;
}

#endif