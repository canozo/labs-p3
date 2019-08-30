#ifndef CONSOLA_H
#define CONSOLA_H

#include <string>
#include "Logger.h"

using namespace std;

class Consola {
  private:
    string usuario;
    Logger *logger;

  public:
    Consola(string, string);
    ~Consola();
    void cmd();
};

#endif
