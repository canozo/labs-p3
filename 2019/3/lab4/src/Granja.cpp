#include "Granja.h"

Granja::Granja() : Edificio("Granja", 50, 5, 15) {
  this->clics = 0;
}

int Granja::producir() {
  clics += 1;

  if (clics == 10) {
    clics = 0;
    return produccionBase + 20;
  }

  return produccionBase;
}
