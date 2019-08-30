#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Log {
  private:
    string usuario;
    string comando;
    int num;

  public:
    Log(string, string, int);
    Log(string, string, int, ofstream &);
    void write(ofstream &);
    void print();
};

#endif
