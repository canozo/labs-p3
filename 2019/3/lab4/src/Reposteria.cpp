#include <iostream>
#include <typeinfo>
#include "Reposteria.h"
#include "Granja.h"
#include "Banco.h"
#include "Templo.h"
#include "Oreo.h"
#include "Migajas.h"

using namespace std;

Reposteria::Reposteria(string jugador) {
  this->jugador = jugador;
  this->galletas = 0;
  // this->galletas = 1000;
}

Reposteria::~Reposteria() {
  for (int i = 0; i < edificios.size(); i += 1) {
    delete edificios[i];
  }

  for (int i = 0; i < mejoras.size(); i += 1) {
    delete mejoras[i];
  }
}

int Reposteria::getGalletas() {
  return this->galletas;
}

void Reposteria::setGalletas(int galletas) {
  this->galletas = galletas;
}

string Reposteria::getNombre() {
  return this->jugador;
}

void Reposteria::agregarEdificio(Edificio *edificio) {
  this->edificios.push_back(edificio);
}

void Reposteria::agregarMejora(Mejora *mejora) {
  this->mejoras.push_back(mejora);
}

void Reposteria::info() {
  cout
    << "Reposteria de " << jugador << "con " << galletas << " galletas.\n"
    << "Posee " << edificios.size() << " edicifios.\n"
    << "Posee " << mejoras.size() << " mejoras.\n";
}

vector<Edificio *> Reposteria::getEdificios() {
  return this->edificios;
}

vector<Mejora *> Reposteria::getMejoras() {
  return this->mejoras;
}

void Reposteria::clic() {
  int total = 1;

  for (int i = 0; i < edificios.size(); i += 1) {
    total += edificios[i]->producir();
  }

  for (int i = 0; i < mejoras.size(); i += 1) {
    total += total * mejoras[i]->bono();
  }

  this->galletas += total;
}
