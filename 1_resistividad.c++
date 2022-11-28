#include <iostream>
#include <cmath>

// constantes para transformar a metros todo
#define cm *.01
#define ft *.3048
#define mt *1
#define in *.0254
#define km *1000

#define PI 3.14159265358979

using namespace std;

class Conductor
{
public:
  float diamHilo;
  float factorEspirilacion;
  float k;
  float longitud;
  float resistividad20;
  float temperatura;
  int numHilos;

  float areaHilo()
  {
    return PI / 4 * diamHilo * diamHilo;
  }

  float area()
  {
    return numHilos * areaHilo();
  }

  float resistividad()
  {
    return resistividad20 * (temperatura + k) / (20 + k);
  }

  float resistencia()
  {
    return factorEspirilacion * resistividad() * longitud / area();
  }
};

int main()
{
  Conductor c;

  c.numHilos = 8;
  c.longitud = 10 km;
  c.diamHilo = 5 cm;
  c.temperatura = 75;
  c.factorEspirilacion = 1.03;

  // de la tabla
  c.k = 228.1;
  c.resistividad20 = 2.83e-8;

  cout << "Area de la seccion transversal: " << c.area() << " m2" << endl;
  cout << "Resistividad a 75" << char(248) << "C: " << c.resistividad() << " ohm m" << endl;
  cout << "Resistencia a 75" << char(248) << "C: " << c.resistencia() << " ohm" << endl;

  return 0;
}