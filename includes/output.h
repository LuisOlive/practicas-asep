#include <iostream>
#include <cmath>
#include <string>

using std::string;

#ifndef OUTPUT_H
#define OUTPUT_H

void puts(string prompt)
{
  std::cout << prompt << std::endl;
}

// obtiene el prefijo de formato de ingenieria
string buscarPrefijo(int potenciaDeDiez = 0)
{
  switch (potenciaDeDiez)
  {
  case 3:
    return "k";
  case 6:
    return "M";
  case 9:
    return "G";
  case -3:
    return "m";
  case -6:
    return "u";
  case -9:
    return "n";
  }

  return "";
}

double abs_(double x) {
  if(x < 0)
    return -x;
  return x;
}

string formatoIngenieria(const double valor, const string unidad)
{ // {caso 1} 34 500, {caso 2} .0000000345
  string prefijo = " ";
  int potenciaDeDiez = 0;
  double buff = abs_(valor);

  puts("-------");
  std::cout << "buff antes:" << buff << std::endl;
  std::cout << "potenciaDeDiez antes:" << potenciaDeDiez << std::endl;

  // pra numeros grandes
  while (buff > pow(10, potenciaDeDiez)) // {caso 1} 34 500 > 10->Sí, 1000 -> sí, 100 000 -> No
    potenciaDeDiez += 3;

  // para numeros pequeños
  while (buff > 0 && buff < pow(10., potenciaDeDiez)) // {caso 2} .0000000345 < 10->si, .001->si, .000 001->si, .000 000 001->no
    potenciaDeDiez -= 3;

  if (buff < 1 && buff >= .1)
    potenciaDeDiez = 0;
  
  buff = valor / pow(10., potenciaDeDiez);
  std::cout << "buff despues:" << buff << std::endl;
  std::cout << "potenciaDeDiez despues:" << potenciaDeDiez << std::endl;
  
  return std::to_string(buff) + " " + buscarPrefijo(potenciaDeDiez) + unidad;
}

#endif