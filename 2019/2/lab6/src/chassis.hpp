#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>

using namespace std;

class Chassis {
  private:
    bool automatico;
    string ruedas;

  public:
    Chassis();
    Chassis(bool, string);
    Chassis *clone();
    string info();
};

#endif
