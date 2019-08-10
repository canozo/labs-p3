#ifndef GRANJA_H
#define GRANJA_H

#include "Edificio.h"

class Granja : public Edificio {
  private:
    int clics;

  public:
    Granja();
    virtual int producir();
};

#endif
