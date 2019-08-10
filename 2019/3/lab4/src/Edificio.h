#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>

using namespace std;

class Edificio {
  protected:
    string nombre;
    int precioBase;
    int produccionBase;
    int aumentoPrecio;

  public:
    Edificio(string, int, int, int);

    int getPrecio();
    int getAumento();

    virtual int producir() = 0;
};

#endif
