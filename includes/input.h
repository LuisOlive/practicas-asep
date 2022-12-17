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
T input(string prompt, T default_)
{
  if(noPedirNadaEnConsola)
    return default_;
  
  return input<T>(prompt);
}

#endif
