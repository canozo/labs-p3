#include "Edificio.h"

Edificio::Edificio(string nombre, int precioBase, int produccionBase, int aumentoPrecio) {
  this->nombre = nombre;
  this->precioBase = precioBase;
  this->produccionBase = produccionBase;
  this->aumentoPrecio = aumentoPrecio;
}

int Edificio::getPrecio() {
  return this->precioBase;
}

int Edificio::getAumento() {
  return this->aumentoPrecio;
}
