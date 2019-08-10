#include "Mejora.h"

Mejora::Mejora(string nombre, int precioBase) {
  this->nombre = nombre;
  this->precioBase = precioBase;
}

int Mejora::getPrecio() {
  return this->precioBase;
}
