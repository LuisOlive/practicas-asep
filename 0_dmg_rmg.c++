#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// constantes para transformar a cm todo
#define cm *.01
#define ft *.3048
#define mt *1
#define in *.0254

struct Conductor
{
public:
  // localizaciones de los subconductores en el eje x
  vector<float> x;

  // localizaciones de los subconductores en el eje y
  vector<float> y;

  float radioSubconductores;
};

float distanciaSubconductores(Conductor c1, int n, Conductor c2, int m)
{
  // distancia en el eje x
  float dx = c2.x[m] - c1.x[n];

  // distancia en el eje y
  float dy = c2.y[m] - c1.y[n];

  // debe haber una distancia, como mínimo la del radio del conductor,
  // de lo contario es fisicamente imposible, a menos que sea el mismo conductor
  if (dx == 0 && dy == 0)
  {
    // es el mismo conductor, entonces se usa la foruma de clase
    return 0.7788 * c1.radioSubconductores;
  }

  // distancia entre dos puntos
  return hypot(dx, dy);
}

float dmg(Conductor c1, Conductor c2)
{
  int N = c1.x.size(), M = c2.x.size();
  double acumulado = 1;

  for (int n = 0; n < N; n++)
    for (int m = 0; m < M; m++)
      acumulado *= distanciaSubconductores(c1, n, c2, m);

  // raíz N*M seria lo mismo que elevar a la 1/(N*M)
  return pow(acumulado, 1. / (N * M));
}

float rmg(Conductor c)
{
  return dmg(c, c);
}

float inductancia(double DMG, double RMG)
{
  return 2e-7 * log(DMG / RMG);
}

int main()
{
  Conductor c1, c2;

  c1.radioSubconductores = 12.5 cm;
  c2.radioSubconductores = 17.5 cm;

  c1.x.push_back(0);
  c1.x.push_back(c1.x[0] + 2 ft);
  c1.x.push_back(c1.x[1] + 2.5 ft);

  c2.x.push_back(c1.x[2] + 10 mt);
  c2.x.push_back(c2.x[0] + 10 in);
  c2.x.push_back(c2.x[1] + 10 in);
  // c2.x.push_back(c2.x[2] + 10 mt); // ejercicio 2

  for (int i = 0; i < c2.x.size(); i++)
  {
    c1.y.push_back(0);
    c2.y.push_back(0);
  }

  float DMG = dmg(c1, c2);
  float RMG1 = rmg(c1);
  float RMG2 = rmg(c2);

  float L1 = inductancia(DMG, RMG1);
  float L2 = inductancia(DMG, RMG2);
  float L = L1 + L2;

  cout << "DMG entre los conductores: " << DMG << " m" << endl;

  cout << "RMG en el conductor 1: " << RMG1 << " m" << endl;
  cout << "RMG en el conductor 2: " << RMG2 << " m" << endl;

  cout << "inductancia en el conductor 1: " << L1 << " H" << endl;
  cout << "inductancia en el conductor 2: " << L2 << " H" << endl;

  cout << "inductancia total: " << L << " H" << endl;

  return 0;
}