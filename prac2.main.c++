#include <iostream>
#include <vector>
using namespace std;

// transforma unidades 
class Magnitud {
protected:
    // digamos que la Magnitud son m, aquí van in, ft, ...
    vector<string> siglasMagnitudesEquivalentes; 
    vector<double> valoresMagnitudesEquivalentes;

public:
    Magnitud(string siglaUnidadBase) {
        valoresMagnitudesEquivalentes.push_back(1);
        siglasMagnitudesEquivalentes.push_back(siglaUnidadBase);
    }

    // aqui le decimos a cada clase que 1cm son 2.54 in, 37 ft....
    Magnitud& agregarEquivalencia(double valor, string sigla) {
        valoresMagnitudesEquivalentes.push_back(valor);
        siglasMagnitudesEquivalentes.push_back(sigla);

        return *this;
    }

    double convertir(double valor, string sigla, string siglaObjetivo) { // 5, ft, cm
        short a = -1, b = -1;

        // [mt, cm, ft, in]
        for(short i = 0; i < siglasMagnitudesEquivalentes.size(); i++) { // 0, 1
            if(siglasMagnitudesEquivalentes[i] == sigla)         // (mt == ft) -> No, (cm == ft) -> No, (ft == ft) -> Sí, No
                a = i; // , , 2, 2

            if(siglasMagnitudesEquivalentes[i] == siglaObjetivo) // (mt == cm) -> No, (cm == cm) -> Sí, No, No
                b = i; // , 1, 1, 1
        }

        double
            A = valoresMagnitudesEquivalentes[a], // [2]: 3.28 ft/mt
            B = valoresMagnitudesEquivalentes[b]; // [1]: 100 cm/mt

        return valor / A * B; // 5 ft / (3.28 ft/mt) (100 cm/mt) = 152.5 cm
    }
};

int main() {
    Magnitud distancia("mt");

    distancia
        .agregarEquivalencia(100, "cm")
        .agregarEquivalencia(3.28084, "ft")
        .agregarEquivalencia(1e-3, "km")
        .agregarEquivalencia(621.37119224e-6, "mi")
    ;

    cout << "5 ft es igual a " << distancia.convertir(5, "ft", "cm") << " cm" << endl;
    cout << "5 mi es igual a " << distancia.convertir(5, "mi", "km") << " km" << endl;

    return 0;
}