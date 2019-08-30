#include "Logger.h"

Logger::Logger(string nombreArchivo, string usuario) {
  this->nombreArchivo = nombreArchivo;
  this->usuario = usuario;
  this->logNum = 0;
  this->cargar();
  this->writer.open(nombreArchivo.c_str(), ios::binary | ios::app);
}

void Logger::log(string comando) {
  logs.push_back(new Log(comando, usuario, logNum, writer));
  logNum += 1;
}

void Logger::cargar() {
  ifstream reader(nombreArchivo.c_str(), ios::binary);

  if (!reader) {
    return;
  }

  while (!reader.eof()) {
    int logNum, size;
    string comando, usr;

    // int logNum
    reader.read(reinterpret_cast<char*>(&logNum), sizeof(int));

    // string usuario
    reader.read(reinterpret_cast<char*>(&size), sizeof(int));
    char usrBuffer[size];
    reader.read(usrBuffer, size);
    usr = usrBuffer;
    usr = usr.substr(0, size);

    // string comando
    reader.read(reinterpret_cast<char*>(&size), sizeof(int));
    char cmdBuffer[size];
    reader.read(cmdBuffer, size);
    comando = cmdBuffer;
    comando = comando.substr(0, size);

    this->logs.push_back(new Log(comando, usr, logNum));
    this->logNum = logNum > this->logNum ? logNum : this->logNum + 1;
  }

  // por alguna razon cuando carga, lo agrega dos veces
  delete logs[logs.size() - 1];
  logs.erase(logs.begin() + logs.size() - 1);

  reader.close();
}

void Logger::listar() {
  for (int i = 0; i < logs.size(); i += 1) {
    logs[i]->print();
  }
}

Logger::~Logger() {
  for (int i = 0; i < logs.size(); i += 1) {
    delete logs[i];
  }
  this->writer.close();
}
