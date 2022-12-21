#include <vector>

#include "../utilidades/input.h"
#include "../utilidades/formatoDeIngenieria.h"

#ifndef Magnitud_H
#define Magnitud_H

// transforma unidades
class Magnitud
{
protected:
    // digamos que la Magnitud son m, aquí van in, ft, ...
    std::vector<string> siglasMagnitudesEquivalentes;
    std::vector<double> valoresMagnitudesEquivalentes;

public:
    Magnitud(string siglaUnidadBase)
    {
        valoresMagnitudesEquivalentes.push_back(1);
        siglasMagnitudesEquivalentes.push_back(siglaUnidadBase);
    }

    // aqui le decimos a cada clase que 1cm son 2.54 in, 37 ft....
    Magnitud &agregarEquivalencia(double valor, string sigla)
    {
        valoresMagnitudesEquivalentes.push_back(valor);
        siglasMagnitudesEquivalentes.push_back(sigla);

        return *this;
    }

    double convertir(double valor, string sigla, string siglaObjetivo)
    { // 5, ft, cm
        short a = 250, b = 250;

        // [mt, cm, ft, in]
        for (short i = 0; i < siglasMagnitudesEquivalentes.size(); i++)
        {
            // 0, 1
            if (siglasMagnitudesEquivalentes[i] == sigla) // (mt == ft) -> No, (cm == ft) -> No, (ft == ft) -> Sí, No
                a = i;                                    // , , 2, 2

            if (siglasMagnitudesEquivalentes[i] == siglaObjetivo) // (mt == cm) -> No, (cm == cm) -> Sí, No, No
                b = i;                                            // , 1, 1, 1
        }

        if (a > 200 || b > 200)
        {
            std::cout
                << "(la unidad " << sigla
                << " no puede transformarse a " << siglaObjetivo
                << ". resuelto como 0)";
            return 0;
        }

        double
            A = valoresMagnitudesEquivalentes[a], // [2]: 3.28 ft/mt
            B = valoresMagnitudesEquivalentes[b]; // [1]: 100 cm/mt

        return valor / A * B; // 5 ft / (3.28 ft/mt) (100 cm/mt) = 152.5 cm
    }

    string get_unidadesDisponibles()
    {
        string s = "[ ";

        for (short i = 0; i < siglasMagnitudesEquivalentes.size(); i++)
        {
            if (i)
                s += ", ";

            s += siglasMagnitudesEquivalentes[i];
        }
        return s + " ]";
    }

    string pedirUnidad(string prompt)
    {
        return input<string>(prompt + " " + get_unidadesDisponibles());
    }

    double pedirEnUnidad(string prompt, string sigla)
    {
        double valor = input(prompt + " (solo el numero)");
        string siglaUs = pedirUnidad("En que unidad?");

        valor = convertir(valor, siglaUs, sigla);

        // mostrando al usuario como queda el valor que ingreso en la unidad que queremos
        puts(fmtIng(valor, sigla));

        return valor;
    }
};

#endif