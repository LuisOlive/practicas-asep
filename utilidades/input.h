#include "output.h"

#ifndef INPUT_H
#define INPUT_H

template <typename T = double>
T input(string prompt = "", bool dosPuntos = true)
{
  T x;
  std::cout << prompt;

  if (dosPuntos)
    std::cout << ": ";

  std::cin >> x;
  return x;
}

#endif
