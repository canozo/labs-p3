#ifndef BANCO_H
#define BANCO_H

#include "Edificio.h"

class Banco : public Edificio {
  private:
    int produccionExtra;

  public:
    Banco();
    virtual int producir();
};

#endif
