#ifndef MOTOR_H
#define MOTOR_H

#include <string>

using namespace std;

class Motor {
  private:
    bool electrico;
    string config; // v6, v8, electrico

  public:
    Motor();
    Motor(bool, string);
    Motor *clone();
    string info();
};

#endif
