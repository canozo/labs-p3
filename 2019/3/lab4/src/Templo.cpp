#include "Templo.h"

Templo::Templo() : Edificio("Templo", 200, 30, 100) {
  this->produccionExtra = 0;
}

int Templo::producir() {
  produccionExtra += 3;

  return produccionBase + produccionExtra;
}
