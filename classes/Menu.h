#include "../utilidades/interaccion.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
    std::vector<string> opciones;
    std::vector<void (*)()> funciones;

    void display()
    {
        puts("Que desea hacer?\n");

        for (short i = 0; i < opciones.size(); i++)
        {
            std::cout << i + 1 << ") " << opciones[i] << std::endl;
        }

        puts("");
    }

    bool mostrarYRepetir()
    {
        unsigned short numOpc;

        limpiar();
        display();

        numOpc = pedirNumeroEnIntervalo<short>("Seleccione una opcion", 1, opciones.size());

        ejecutar(numOpc - 1); // por los arrays

        return desea("hacer otro calculo");
    }

    void ejecutar(unsigned short i)
    {
        limpiar();
        puts(string(".: ") + opciones[i] + " :.\n");

        funciones[i](); 

        puts();
        hr();
    }

    Menu &operator<<(string opc)
    {
        opciones.push_back(opc);
        return *this;
    }

    Menu &operator<<(void (*f)())
    {
        funciones.push_back(f);
        return *this;
    }
};

#endif