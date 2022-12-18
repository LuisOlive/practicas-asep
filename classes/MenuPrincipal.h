#include "../Menu/Menu.h"
#include "Conductor.h"

#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

class MenuPrincipal : public Menu
{
public:
    void opc1()
    {
        Conductor c;
        c.numHilos = input("Ingrese el numero de hilos");
        c.longitud = distancia.pedirEnUnidad("Ingrese la longitud de la linea", "mt");
        c.diamHilo = distancia.pedirEnUnidad("ingrese el diametro de los hilos", "mt");
        c.temperatura = input("Ingrese la temperatura ambiente en grados C");
        c.factorEspirilacion = input("Ingrese el coeficiente de espirilacion");

        // si da tiempo lo sacamos de archivos
        c.k = input("Ingrese la constante de temperatura k de la tabla");
        c.resistividad20 = input("Ingrese la resistividad a 20 grados de la tabla");

        cout << "Area de la seccion transversal de cada hilo: " << fmtIng(c.areaHilo(), "(m2)") << endl;
        cout << "Area de la seccion transversal total: " << fmtIng(c.area(), "(m2)") << endl;
        cout << "Resistividad a " << c.temperatura << char(248) << "C: " << fmtIng(c.resistividad(), "ohm m") << endl;
        cout << "Resistencia de CD a " << c.temperatura << char(248) << "C: " << fmtIng(c.resistenciaCD(), "ohm") << endl;
    }

    void opc2()
    {
        puts("Opcion 2");
    }
};

#endif