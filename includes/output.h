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

    string formatoIngenieria(double valor, string unidad)
{ // 34 500
  string prefijo = " ";
  int potenciaDeDiez = 0;

  while (valor > powl(10, potenciaDeDiez) ) // 34 500 > 10->Sí, 1000 -> sí, 100 000 -> No
    potenciaDeDiez+= 3; 
  

  if(valor < .1) 
  {
    valor *= 1000;
    prefijo = " m";
  }

  potenciaDeDiez -= 3; 
  return std::to_string(valor / powl(10, potenciaDeDiez)) + " " + buscarPrefijo(potenciaDeDiez) + unidad;
}

#endif