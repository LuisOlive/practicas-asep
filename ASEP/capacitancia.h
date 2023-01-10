#include "../classes/Linea.h"

#ifndef CAPACITANCIA_H
#define CAPACITANCIA_H

void capacitancia()
{
    puts("Definicion de la linea:");

    Linea l(1);

    hr();

    cout << "D_eq de la linea: " << fmtIng(l.rmg(), "mt") << endl;
    cout << "D_S de la linea: " << fmtIng(l.dmg(), "mt") << endl;
    cout << "D_SC de la linea: " << fmtIng(l.dSC(), "mt") << endl;

    cout << "Capacitancia unitaria: " << fmtIng(l.capacitanciaUnitaria(), "Fd/mt") << endl;
    cout << "Capacitancia total de la linea: " << fmtIng(l.capacitancia(), "Fd") << endl;

    cout << "Admitancia en derivacion: " << fmtIng(l.admitanciaCapacitiva(), "S") << endl;

    cout << "Corriente de carga: " << fmtIng(l.corrienteDeCarga(), "A") << endl;

    cout << "Potencia reactiva capacitiva: " << fmtIng(l.potenciaReactivaCapacitiva(), "VAr") << endl;
}

#endif