#ifndef PINTURA_H
#define PINTURA_H

#include <string>

using namespace std;

class Pintura {
  private:
    string color; // rojo, verde, azul
    string acabado; // normal, matte, glossy

  public:
    Pintura();
    Pintura(string, string);
    Pintura *clone();
    string info();
};

#endif
