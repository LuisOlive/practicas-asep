#include <iostream>
using namespace std;

#ifndef Magnitud_H
#define Magnitud_H

// utiliza Magnitudes físicas como distancias
class Magnitud {
protected:
    string sigla;
    double valor;

    // digamos que la Magnitud son m, aquí van in, ft, ...
    static vector<string> siglasMagnitudesEquivalentes; 
    static vector<double> valoresMagnitudesEquivalentes;

    // aqui le decimos a cada clase que 1cm son 2.54 in, 37 ft....
    static Magnitud& agregarEquivalencia(string sigla, double valor) {
        siglasMagnitudesEquivalentes.push_back(sigla);
        valoresMagnitudesEquivalentes.push_back(valor);
        return *this;
    }

public:
    // 
    Magnitud(string sigla, double valor = 0) {
        this->sigla = sigla;
        this->valor = valor;
    }

    // si no pasan ninguna unidad, usa la primera que definimos
    Magnitud(double valor): Magnitud(Magnitud::siglasMagnitudesEquivalentes[0], valor);

    // devuelve este mismo valor en otra Magnitud, pe: son A=5m; A.convertirA("km") -> .005
    Magnitud convertirA(string sigla) {
        for(i = 0; i < siglasMagnitudesEquivalentes.size(); i++) 
        
            if(siglasMagnitudesEquivalentes[i] == sigla) {
                 cout << "tratando de convertir a " << siglasMagnitudesEquivalentes[i] << endl;
                return Magnitud(valor * valoresMagnitudesEquivalentes[i], sigla)
}
        cout << "no se puede transformar " << this->sigla << " a " << sigla << endl;
       
        

        return *this
    }

    Magnitud operator = (Magnitud u) {
        
    }
};

class Distancia: public Magnitud {};
class Area: public Magnitud {};

Distancia::agregarEquivalencia(1, "mt")
Distancia::agregarEquivalencia(1, "m2")

int main() {
    return 0;
    Distancia(8000).convertirA("m2")
}

#endif