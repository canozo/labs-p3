#ifndef MEJORA_H
#define MEJORA_H

#include <string>

using namespace std;

class Mejora {
  protected:
    string nombre;
    int precioBase;

  public:
    Mejora(string, int);

    int getPrecio();

    virtual float bono() = 0;
};

#endif
