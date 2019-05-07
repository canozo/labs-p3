#ifndef CARRO_H
#define CARRO_H

#include <string>
#include "chassis.hpp"
#include "motor.hpp"
#include "pintura.hpp"

using namespace std;

class Carro {
  private:
    string modelo;
    int numero_modelo;
    bool es_prototipo;

    Chassis *chassis;
    Motor *motor;
    Pintura *pintura;

  public:
    Carro();
    ~Carro();
    Carro(string, int);
    Carro *clone();
    void setChassis(Chassis *);
    void setMotor(Motor *);
    void setPintura(Pintura *);

    string id();
    string info();

    Chassis *cloneChassis();
    Motor *cloneMotor();
    Pintura *clonePintura();

    bool getPrototipo();
};

#endif
