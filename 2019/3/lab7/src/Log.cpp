#include "Log.h"

Log::Log(string comando, string usuario, int num) {
  this->comando = comando;
  this->usuario = usuario;
  this->num = num;
}

Log::Log(string comando, string usuario, int num, ofstream &writer) {
  this->comando = comando;
  this->usuario = usuario;
  this->num = num;
  this->write(writer);
}

void Log::write(ofstream &writer) {
  int size = 0;
  // int num
  writer.write(reinterpret_cast<char*>(&num), sizeof(int));

  // string usuario
  size = usuario.size();
  writer.write(reinterpret_cast<char*>(&size), sizeof(int));
  writer.write(usuario.data(), size);

  // string comando
  size = comando.size();
  writer.write(reinterpret_cast<char*>(&size), sizeof(int));
  writer.write(comando.data(), size);
}

void Log::print() {
  cout
    << "num: " << this->num
    << ", usuario: "
    << this->usuario
    << ", cmd: \"" << this->comando
    << "\"\n";
}
