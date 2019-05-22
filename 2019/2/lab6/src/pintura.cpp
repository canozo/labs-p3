#include <iostream>
#include <sstream>
#include "pintura.hpp"

using namespace std;

Pintura::Pintura() {
  cout << "Ingrese el color de la pintura (rojo, verde, azul): ";
  cin >> this->color;

  cout << "Ingrese el acabo de la pintura (normal, matte, glossy): ";
  cin >> this->acabado;
}

Pintura::Pintura(string color, string acabado) {
  this->color = color;
  this->acabado = acabado;
}

Pintura *Pintura::clone() {
  return new Pintura(
    this->color,
    this->acabado
  );
}

string Pintura::info() {
  stringstream res;
  res << "Color: " << this->color << '\n';
  res << "Acabado: " << this->acabado << '\n';
  return res.str();
}
