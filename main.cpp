#include "classes/Menu.h"

#include "ASEP/resistenciaCD.h"
#include "ASEP/rmg_dmg.h"
#include "ASEP/inductancia.h"
#include "ASEP/capacitancia.h"
#include "ASEP/abcd.h"

void pendiente()
{
    puts("Esto aun esta pendiente");
}

int main()
{
    usarMagnitudes();
    Menu m;

    m << "Calcular resistencia de CD de un conjunto de conductores" << resistenciaCD;
    m << "Calcular radio medio geometrico y distancia media geometrica de un conjunto de conductores" << dmgRmg;
    m << "Calcular la inductancia y reactancia inductiva de una linea" << inductancia;
    m << "Calcular la capacitancia, admitancia en derivacion, corriente de carga y potencia reactiva de una linea" << capacitancia;
    m << "Calcular parametros ABCD, V_S, I_S y P_S" << abcd;

    while (m.mostrarYRepetir())
    {
    }

    return 0;
}
