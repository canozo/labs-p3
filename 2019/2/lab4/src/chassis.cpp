#include <iostream>
#include <sstream>
#include "chassis.hpp"

using namespace std;

Chassis::Chassis() {
  string automatico;
  cout << "El carro es automatico? [y/n]: ";
  cin >> automatico;
  this->automatico = automatico == "y" || automatico == "Y";

  cout << "Ingrese el tipo de ruedas: ";
  cin >> this->ruedas;
}

Chassis::Chassis(bool automatico, string ruedas) {
  this->automatico = automatico;
  this->ruedas = ruedas;
}

Chassis *Chassis::clone() {
  return new Chassis(
    this->automatico,
    this->ruedas
  );
}

string Chassis::info() {
  stringstream res;
  res << "Automatico: " << this->automatico << '\n';
  res << "Ruedas: " << this->ruedas << '\n';
  return res.str();
}
