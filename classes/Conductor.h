#include "../utilidades/constantes.h"

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor
{
public:
    float diamHilo;
    float factorEspirilacion;
    float k;
    float longitud;
    float resistividad20;
    float temperatura;
    int numHilos;

    float areaHilo()
    {
        return PI / 4 * diamHilo * diamHilo;
    }

    float area()
    {
        return numHilos * areaHilo();
    }

    float resistividad()
    {
        return resistividad20 * (temperatura + k) / (20 + k);
    }

    float resistenciaCD()
    {
        return factorEspirilacion * resistividad() * longitud / area();
    }
};

#endif