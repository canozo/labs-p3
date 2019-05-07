#include <iostream>
#include <sstream>
#include "motor.hpp"

using namespace std;

Motor::Motor() {
  string electrico;
  cout << "El carro es electrico? [y/n]: ";
  cin >> electrico;
  this->electrico = electrico == "y" || electrico == "Y";

  cout << "Ingrese la configuracion del motor (v8, v6, eletrico): ";
  cin >> this->config;
}

Motor::Motor(bool electrico, string config) {
  this->electrico = electrico;
  this->config = config;
}

Motor *Motor::clone() {
  return new Motor(
    this->electrico,
    this->config
  );
}

string Motor::info() {
  stringstream res;
  res << "Eletrico: " << this->electrico << '\n';
  res << "Configuracion: " << this->config << '\n';
  return res.str();
}
