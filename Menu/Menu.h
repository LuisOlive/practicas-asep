#include "../utilidades/interaccion.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
    std::vector<string> opciones;

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

        ejecutar(numOpc);

        return desea("hacer otro calculo");
    }

    void ejecutar(unsigned short i)
    {
        limpiar();
        puts(string(".: ") + opciones[i - 1] + " :.\n");

        switch (i)
        {
        case 1:
            opc1();
            break;
        case 2:
            opc2();
            break;
        case 3:
            opc3();
            break;
        case 4:
            opc4();
            break;
        case 5:
            opc5();
            break;
        case 6:
            opc6();
            break;
        case 7:
            opc7();
            break;
        }

        puts();
        hr();
    }

    Menu &operator<<(string opc)
    {
        opciones.push_back(opc);
        return *this;
    }

    virtual void opc1(){};
    virtual void opc2(){};
    virtual void opc3(){};
    virtual void opc4(){};
    virtual void opc5(){};
    virtual void opc6(){};
    virtual void opc7(){};
};

#endif