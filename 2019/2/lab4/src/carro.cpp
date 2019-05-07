#include <iostream>
#include <sstream>
#include "carro.hpp"

using namespace std;

Carro::Carro() {
  cout << "Ingrese el modelo del carro: ";
  cin >> this->modelo;
  this->numero_modelo = 0;

  this->es_prototipo = true;

  this->chassis = NULL;
  this->motor = NULL;
  this->pintura = NULL;
}

Carro::Carro(string modelo, int numero_modelo) {
  this->modelo = modelo;
  this->numero_modelo = numero_modelo;

  this->es_prototipo = false;

  this->chassis = NULL;
  this->motor = NULL;
  this->pintura = NULL;
}

Carro::~Carro() {
  if (this->chassis != NULL) {
    delete this->chassis;
  }

  if (this->motor != NULL) {
    delete this->motor;
  }

  if (this->pintura != NULL) {
    delete this->pintura;
  }
}

Carro *Carro::clone() {
  this->numero_modelo += 1;
  return new Carro(
    this->modelo,
    this->numero_modelo
  );
}

void Carro::setChassis(Chassis *chassis) {
  this->chassis = chassis;
}

void Carro::setMotor(Motor *motor) {
  this->motor = motor;
}

void Carro::setPintura(Pintura *pintura) {
  this->pintura = pintura;
}

string Carro::id() {
  stringstream res;
  res << '#' << this->modelo << this->numero_modelo;
  return res.str();
}

string Carro::info() {
  stringstream res;

  if (this->chassis != NULL) {
    res << "Info del chassis del carro:\n" << this->chassis->info() << '\n';
  } else {
    res << "El carro aun no tiene chassis.\n";
  }

  if (this->motor != NULL) {
    res << "Info del motor del carro:\n" << this->motor->info() << '\n';
  } else {
    res << "El carro aun no tiene motor.\n";
  }

  if (this->pintura != NULL) {
    res << "Info del pintura del carro:\n" << this->pintura->info() << '\n';
  } else {
    res << "El carro aun no tiene pintura.\n";
  }
  return res.str();
}

Chassis *Carro::cloneChassis() {
  return this->chassis->clone();
}

Motor *Carro::cloneMotor() {
  return this->motor->clone();
}

Pintura *Carro::clonePintura() {
  return this->pintura->clone();
}

bool Carro::getPrototipo() {
  return this->es_prototipo;
}
