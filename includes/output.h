#include <iostream>
#include <cmath>
#include <string>

using std::string;

#ifndef OUTPUT_H
#define OUTPUT_H

void puts(string prompt) {
  std::cout << prompt << std::endl;
}

// obtiene el prefijo de formato de ingenieria
string buscarPrefijo(int potenciaDeDiez = 0) {
  switch (potenciaDeDiez)
  {
    case 3: return "k";
    case 6: return "M";
    case 9: return "G";
    case -3: return "m";
    case -6: return "u";
    case -9: return "n";
  }
  
  return "";
}

    string formatoIngenieria(const double valor, const string unidad)
    { // {caso 1} 34 500, {caso 2} .0000000345
  string prefijo = " ";
  int potenciaDeDiez = 0;
  double buff = valor;

  while (valor > powl(10, potenciaDeDiez) ) // {caso 1} 34 500 > 10->Sí, 1000 -> sí, 100 000 -> No
    potenciaDeDiez+= 3;

  while (valor < powl(10, potenciaDeDiez)) // {caso 2} .0000000345 < 10->si, .001->si, .000 001->si, .000 000 001->no
    potenciaDeDiez -= 3;

  buff = valor / powl(10, potenciaDeDiez); 
  return std::to_string(buff) + " " + buscarPrefijo(potenciaDeDiez) + unidad;
    }

#endif