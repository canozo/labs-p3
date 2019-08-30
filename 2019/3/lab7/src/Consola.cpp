#include <iostream>
#include <direct.h>
#include "Consola.h"
#include "CmdError.h"

Consola::Consola(string usuario, string nombreArchivo) {
  this->usuario = usuario;
  this->logger = new Logger(nombreArchivo, usuario);
}

Consola::~Consola() {
  delete this->logger;
}

void Consola::cmd() {
  string input;
  int error = 0;

  while (input != "exit") {
    cout << usuario << "$ ";

    getline(cin, input);
    input[input.size()] = 0;

    if (input == "") {
      continue;
    }

    if (input.size() > 3 && input.substr(0, 3) == "cd ") {
      error = _chdir(input.substr(3, input.size()).c_str());
    } else if (input == "listar") {
      this->logger->listar();
    } else {
      error = system(input.c_str());
    }

    if (error) {
      throw CmdError("Error al ejecutar el comando: \"" + input + "\"\n");
    }

    this->logger->log(input);
  }
}
