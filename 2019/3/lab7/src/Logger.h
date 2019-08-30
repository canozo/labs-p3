#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <vector>
#include "Log.h"

using namespace std;

class Logger {
  private:
    string nombreArchivo;
    string usuario;
    int logNum;
    vector <Log *> logs;
    ofstream writer;

  public:
    Logger(string, string);
    void log(string);
    void cargar();
    void listar();
    ~Logger();
};

#endif
