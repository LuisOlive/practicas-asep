#include "../classes/CircuitoPI.h"

#ifndef ABCD_H
#define ABCD_H

void abcd()
{
     puts("Definicion de la linea:");

     CircuitoPi pi;

     hr();

     cout << "Voltaje de fase: " << pi.voltajeNominalLineaNeutro() << " kV" << endl;
     cout << "Voltaje recibido (el porcentaje a kV): " << pi.voltajeRecibido() << " kV" << endl;
     cout << "Corriente demandada por la carga (recibida): " << pi.corrienteRecibida() << " kA" << endl
          << endl;

     cout << "A: " << pi.A() << endl;
     cout << "B: " << pi.B() << endl;
     cout << "C: " << pi.C() << endl;
     cout << "D: " << pi.D() << endl
          << endl;

     cout << "Voltaje enviado (fase): " << pi.voltajeEnviado() << " kV" << endl;
     cout << "Voltaje enviado (linea): " << pi.voltajeEnviado() * RAIZ_3 << " kV" << endl;
     cout << "Corriente enviada: " << pi.corrienteEnviada() << " kA" << endl;
     cout << "Potencia enviada: " << pi.potenciaEnviada() << " MW" << endl
          << endl;

     cout << "Voltaje en vacio: " << pi.voltajeSinCarga() * RAIZ_3 << " kV" << endl;
     cout << "Caida de tension: " << pi.porcentajeCaidaDeTension() << " %" << endl;
     cout << "Eficiencia: " << pi.eficiencia() << " %" << endl;
}

#endif