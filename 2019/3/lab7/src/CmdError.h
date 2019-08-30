#ifndef CMDERROR_H
#define CMDERROR_H

#include <stdexcept>
#include <string>

using namespace std;

class CmdError : public runtime_error {
  public:
    CmdError(string);
};

#endif
