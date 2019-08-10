#ifndef TEMPLO_H
#define TEMPLO_H

#include "Edificio.h"

class Templo : public Edificio {
  private:
    int produccionExtra;

  public:
    Templo();
    virtual int producir();
};

#endif
