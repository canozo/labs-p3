#include "Banco.h"

Banco::Banco() : Edificio("Banco", 100, 15, 40) {
  this->produccionExtra = 0;
}

int Banco::producir() {
  produccionExtra += 1;

  return produccionBase + produccionExtra;
}
