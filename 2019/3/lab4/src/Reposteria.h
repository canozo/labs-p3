#ifndef REPOSTERIA_H
#define REPOSTERIA_H

#include <string>
#include <vector>
#include "Edificio.h"
#include "Mejora.h"

using namespace std;

class Reposteria {
  private:
    string jugador;
    int galletas;
    vector<Edificio *> edificios;
    vector<Mejora *> mejoras;

  public:
    Reposteria(string);
    ~Reposteria();

    int getGalletas();
    void setGalletas(int);

    string getNombre();

    void agregarEdificio(Edificio *);
    void agregarMejora(Mejora *);

    vector<Edificio *> getEdificios();
    vector<Mejora *> getMejoras();

    void info();

    void clic();
};

#endif
