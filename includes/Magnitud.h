#include <vector>

#include "input.h"

#ifndef Magnitud_H
#define Magnitud_H

// transforma unidades
class Magnitud
{
protected:
    // digamos que la Magnitud son m, aquí van in, ft, ...
    std::vector<std::string> siglasMagnitudesEquivalentes;
    std::vector<double> valoresMagnitudesEquivalentes;

public:
    Magnitud(std::string siglaUnidadBase)
    {
        valoresMagnitudesEquivalentes.push_back(1);
        siglasMagnitudesEquivalentes.push_back(siglaUnidadBase);
    }

    // aqui le decimos a cada clase que 1cm son 2.54 in, 37 ft....
    Magnitud &agregarEquivalencia(double valor, std::string sigla)
    {
        valoresMagnitudesEquivalentes.push_back(valor);
        siglasMagnitudesEquivalentes.push_back(sigla);

        return *this;
    }

    double convertir(double valor, std::string sigla, std::string siglaObjetivo)
    { // 5, ft, cm
        short a, b;

        // [mt, cm, ft, in]
        for (short i = 0; i < siglasMagnitudesEquivalentes.size(); i++)
        {                                                 // 0, 1
            if (siglasMagnitudesEquivalentes[i] == sigla) // (mt == ft) -> No, (cm == ft) -> No, (ft == ft) -> Sí, No
                a = i;                                    // , , 2, 2

            if (siglasMagnitudesEquivalentes[i] == siglaObjetivo) // (mt == cm) -> No, (cm == cm) -> Sí, No, No
                b = i;                                            // , 1, 1, 1
        }

        double
            A = valoresMagnitudesEquivalentes[a], // [2]: 3.28 ft/mt
            B = valoresMagnitudesEquivalentes[b]; // [1]: 100 cm/mt

        return valor / A * B; // 5 ft / (3.28 ft/mt) (100 cm/mt) = 152.5 cm
    }
};

#endif