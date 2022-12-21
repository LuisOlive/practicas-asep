#include "_utilidades.h"

#ifndef SUBCONDUCTORES_H
#define SUBCONDUCTORES_H

class Subconductores
{
public:
    // localizaciones de los subconductores en el eje x
    std::vector<float> x;

    // localizaciones de los subconductores en el eje y
    std::vector<float> y;

    float radioSubconductores;
    string unidad;
    
    Subconductores() {
        radioSubconductores = distancia.pedirEnUnidad("Ingrese el radio de los subconductores", "mt");
        short N = pedirPositivo("Cuantos hilos tiene su conductor?", 255);
        
        unidad = input<string>("En que unidad desea trabajar?");
        
        puts();
        
        for(short i = 0; i < N; i++)
        {
            cout << "Ingrese la localizacion del subconductor "<< i << " en el eje x";
            x.push_back(distancia.pedirEnUnidad("", unidad));
            
            cout << "Ingrese la localizacion del subconductor "<< i << " en el eje y";
            y.push_back(distancia.pedirEnUnidad("", unidad));
        }
    }

    float distanciaSubconductores(short n, Subconductores s, short m)
    {
        // distancia en el eje x
        float dx = s.x[m] - x[n];

        // distancia en el eje y
        float dy = s.y[m] - y[n];

        // debe haber una distancia, como mínimo la del radio del conductor,
        // de lo contario es fisicamente imposible, a menos que sea el mismo conductor
        if (dx == 0 && dy == 0)
        {
            // es el mismo conductor, entonces se usa la formula de clase
            return 0.7788 * radioSubconductores;
        }

        // distancia entre dos puntos
        return hypot(dx, dy);
    }

    float dmg(Subconductores s)
    {
        double acumulado = 1;
        short N = x.size(), M = s.x.size();

        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
                acumulado *= distanciaSubconductores(n, s, m);

        // raíz<N*M> seria lo mismo que elevar a la 1/(N*M)
        return pow(acumulado, 1. / (N * M));
    }
    
    float rmg() {
        return dmg(*this);
    }
};

#endif