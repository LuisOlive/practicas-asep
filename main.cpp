#include "classes/MenuPrincipal.h"

int main()
{
    usarMagnitudes();
    MenuPrincipal m;

    m << "Calcular resistencia de CD de un conjunto de conductores";
    m << "Calcular radio medio geometrico de un conjunto de conductores";
    // m << "Calcular distancia media geometrica de un conjunto de conductores";

    while (m.mostrarYRepetir())
    {
    }

    return 0;
}
