#include "_utilidades.h"

#ifndef LINEA_H
#define LINEA_H

class Linea
{
public:
    short numFases;
    short conductoresPorFase;
    double distanciaFase; // distancias entre sub conductores de la misma fase
    double dAB, dAC, dBC;
    double longitud;
    short frecuencia;
    double voltajeLineaLinea;
    bool esEstrella;
    double radioExt;

    double _rmg;

    Linea(short modo = 0)
    {
        esEstrella = false;

        numFases = input("Ingrese el numero de fases [1 o 3]");
        conductoresPorFase = pedirNumeroEnIntervalo("Cuantos conductores por fase?", 1, 4);
        longitud = distancia.pedirEnUnidad("Ingrese la longitud de la linea", "mt");

        if (modo == 1)
            voltajeLineaLinea = input("Ingrese el voltaje de linea a linea");

        frecuencia = input("A que frecuencia opera? (en America se usan 60)");

        if (modo == 0)
            _rmg = distancia.pedirEnUnidad("Ingrese el RMG de la tabla A3 o A4", "mt");
        else if (modo == 1)
            radioExt = distancia.pedirEnUnidad("Ingrese el diametro exterior", "mt") / 2.;

        if (conductoresPorFase > 1)
        {

            distanciaFase = distancia.pedirEnUnidad("Ingrese la separacion de haces", "mt");
        }

        if (numFases == 3)
        {
            dAB = dBC = distancia.pedirEnUnidad("Ingrese la distancia entre conductores adyacentes", "mt");
            dAC = 2 * dAB;
            esEstrella = pedirBooleano("Esta en config. estrella?");
        }
        else
        {
            distanciaFase = distancia.pedirEnUnidad("Ingrese la distancia entre fase y neutro", "mt");
        }
    }

    double rmg()
    {
        return _rmg;
    }

    double dmg()
    {
        if (numFases == 1)
            return distanciaFase;

        return pow(dAB * dAC * dBC, .33333333333333);
    }

    double dSL()
    {
        switch (conductoresPorFase)
        {
        case 1:
            return rmg();
        case 2:
            return pow(distanciaFase * rmg(), 1. / 2);
        case 3:
            return pow(distanciaFase * rmg(), 1. / 3);
        case 4:
            return 1.091 * pow(distanciaFase * distanciaFase * distanciaFase * rmg(), 1. / 4);
        }
    }

    double inductanciaUnitaria()
    {
        return 2e-7 * log(dmg() / dSL());
    }

    double inductancia()
    {
        if (numFases == 1)
            return 2 * longitud * inductanciaUnitaria();

        return longitud * inductanciaUnitaria();
    }

    double reactanciaInductiva()
    {
        return 2 * PI * frecuencia * inductancia();
    }

    double dSC()
    {
        return pow(distanciaFase * radioExt, 1. / 2);
    }

    double capacitanciaUnitaria()
    {
        if (numFases == 1)
        {
            return PI * EPSILON / log(distanciaFase / radioExt);
        }

        return 2 * PI * EPSILON / log(dmg() / dSC());
    }

    double capacitancia()
    {
        return longitud * capacitanciaUnitaria();
    }

    double admitanciaCapacitiva()
    {
        return 2 * PI * frecuencia * capacitancia();
    }

    double voltajeLineaNeutro()
    {
        if (esEstrella)
            return voltajeLineaLinea / RAIZ_3;

        return voltajeLineaLinea;
    }

    double corrienteDeCarga()
    {
        return admitanciaCapacitiva() * voltajeLineaNeutro();
    }

    double potenciaReactivaCapacitiva()
    {
        return 3 * voltajeLineaNeutro() * voltajeLineaNeutro() * admitanciaCapacitiva();
    }
};

#endif