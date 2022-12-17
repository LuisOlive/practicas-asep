#include "output.h"

#ifndef FORMATO_DE_INGENIERIA_H
#define FORMATO_DE_INGENIERIA_H

// obtiene el prefijo de formato de ingenieria
string buscarPrefijo(int potenciaDeDiez = 0)
{
  switch (potenciaDeDiez)
  {
  case -3:
    return "m";
  case -6:
    return "u";
  case -9:
    return "n";
  case -12:
    return "p";
  case 3:
    return "k";
  case 6:
    return "M";
  case 9:
    return "G";
  case 12:
    return "T";
  }

  return "";
}

// transforma a positivos los números, el normal no funciona
double _abs(double x)
{
  if (x < 0)
    return -x;
  return x;
}

// transforma los números a strings en formato de ingeniería para imprimirlos
string formatoIngenieria(const double valor, const string unidad)
{ // {caso 1} 34 500, {caso 2} .0000000345
  string prefijo = " ";
  int potenciaDeDiez = 0;
  double buff = _abs(valor);

  // pra numeros grandes
  while (buff > pow(10, potenciaDeDiez)) // {caso 1} 34 500 > 10->Sí, 1000 -> sí, 100 000 -> No
    potenciaDeDiez += 3;

  // para numeros pequeños
  while (buff > 0 && buff < pow(10., potenciaDeDiez)) // {caso 2} .0000000345 < 10->si, .001->si, .000 001->si, .000 000 001->no
    potenciaDeDiez -= 3;

  if (buff < 1 && buff >= .1)
    potenciaDeDiez = 0;

  buff = valor / pow(10., potenciaDeDiez);

  return std::to_string(buff) + " " + buscarPrefijo(potenciaDeDiez) + unidad;
}

// alias de formatoIngenieria()
#define fmtIng formatoIngenieria

#endif