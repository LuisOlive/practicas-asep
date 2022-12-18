#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using std::string;

#ifndef OUTPUT_H
#define OUTPUT_H

void puts(string prompt = "")
{
  std::cout << prompt << std::endl;
}

void hr()
{
  puts("----------------");
}

void limpiar()
{
  system("cls");
}

void pausa()
{
  system("pause");
}

#endif