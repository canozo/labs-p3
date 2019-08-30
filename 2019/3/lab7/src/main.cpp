#include <iostream>
#include "CmdError.h"
#include "Consola.h"

using namespace std;

int main(int argc, char** argv) {
  string usuario;
  cout << "Username: ";
  cin >> usuario;
  Consola *consola = new Consola(usuario, "logs.bin");

  try {
    consola->cmd();
  } catch (CmdError &e) {
    cout << e.what();
  }

  delete consola;
  return 0;
}
