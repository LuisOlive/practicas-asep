#include "Complejo.h"
#include "_utilidades.h"

#ifndef CIRCUITO_PI_H
#define CIRCUITO_PI_H

class CircuitoPi
{
public:
    double voltajeNominalLineaLinea;
    double porcentajeDeVoltajeRecibido;
    double potenciaActiva;
    double factorDePotencia;
    double longitud;
    Complejo z, y;

    CircuitoPi()
    {
        longitud = distancia.pedirEnUnidad("Ingrese la longitud de la linea", "km");

        z.real = longitud * input("Ingrese la parte real de la impedancia serie en ohm/km");
        z.imaginaria = longitud * input("Ingrese la parte imag. de la impedancia unitaria serie en ohm/km");
        y.imaginaria = longitud * input("Ingrese la parte imag. de admitancia en derivacion unitaria en S/km");

        voltajeNominalLineaLinea = input("Ingrese el voltaje de linea a linea en kV");
        potenciaActiva = input("Ingrese la potencia activa en MW");
        porcentajeDeVoltajeRecibido = pedirNumeroEnIntervalo("Ingrese el porcentaje de voltaje que llega al punto mas lejano", 50., 100.) / 100.;
        factorDePotencia = pedirNumeroEnIntervalo("Ingrese el porcentaje de factor de potencia de la carga", 50., 100.) / 100.;
    }

    CircuitoPi(bool _)
    {
        longitud = 200;
        z.real = .032 * longitud;
        z.imaginaria = .35 * longitud;

        y.imaginaria = 4.2e-6 * longitud;

        z.nombre = "z";
        y.nombre = "Y";

        z.status();
        y.status();

        (y * z).status();
        (y * z / 2).status();
        (y * z / 2 + 1).status();

        voltajeNominalLineaLinea = 345;
        potenciaActiva = 700;
        porcentajeDeVoltajeRecibido = 95. / 100;
        factorDePotencia = 99. / 100;
    }

    Complejo Z() { return z * longitud; }
    Complejo Y() { return y * longitud; }

    Complejo A() { return y * z / 2 + 1; }
    Complejo B() { return z; }
    Complejo C() { return y * (y * z / 4 + 1); }
    Complejo D() { return A(); }

    double voltajeNominalLineaNeutro()
    {
        return voltajeNominalLineaLinea / RAIZ_3;
    }

    double voltajeRecibido()
    {
        return voltajeNominalLineaNeutro() * porcentajeDeVoltajeRecibido;
    }

    double corrienteRecibida()
    {
        return potenciaActiva / (3 * voltajeRecibido() * factorDePotencia);
    }

    double voltajeEnviado()
    {
        return (A() * voltajeRecibido() + B() * corrienteRecibida()).modulo();
    }

    double corrienteEnviada()
    {
        return (C() * voltajeRecibido() + D() * corrienteRecibida()).modulo();
    }

    double potenciaEnviada()
    {
        return 3 * voltajeEnviado() * corrienteEnviada() * factorDePotencia;
    }

    double voltajeSinCarga()
    {
        return voltajeEnviado() / (A().modulo());
    }

    double porcentajeCaidaDeTension()
    {
        return 100 * (1 - voltajeRecibido() / voltajeSinCarga());
    }

    double eficiencia()
    {
        return 100 * potenciaActiva / potenciaEnviada();
    }
};

#endif