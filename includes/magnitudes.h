#include "Magnitud.h"

#ifndef MAGNITUDES_H
#define MAGNITUDES_H

extern Magnitud distancia("mt");
extern Magnitud area("m2");

void usarMagnitudes()
{
    distancia
        .agregarEquivalencia(100, "cm")     // 1m = 100cm
        .agregarEquivalencia(3.28084, "ft") // 1m = 3.28ft
        .agregarEquivalencia(1e-3, "km")
        .agregarEquivalencia(39.3701, "in")
        .agregarEquivalencia(621.371192e-6, "mi");

    area
        .agregarEquivalencia(1e4, "cm2")
        .agregarEquivalencia(1e6, "mm2")
        .agregarEquivalencia(1550.0031, "in2")
        .agregarEquivalencia(10.76391, "ft2")
        .agregarEquivalencia(1973525241, "cmil");
}

#endif