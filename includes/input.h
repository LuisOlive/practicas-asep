#include "output.h"

#ifndef INPUT_H
#define INPUT_H

template <typename T = double>
T input(string prompt)
{
  T x;
  std::cout << prompt;
  std::cin >> x;
  return x;
}

bool noPedirNadaEnConsola = false;

template <typename T = double>
T input(string prompt, T valorAutomatico)
{
  if(noPedirNadaEnConsola)
    return valorAutomatico;
  
  return input<T>(prompt);
}

#endif
