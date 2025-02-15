#include <iostream>
#include <vector>
#include <string>
#include "carro.hpp"

using namespace std;

void iniciar_lp(Carro ***&);
void liberar_lp(Carro ***&);
void liberar_vec(vector<Carro *>);
bool agregar_linea(Carro ***, int);
bool agregar_linea_lazy(Carro ***, int);
void ver(Carro ***, int);
void ver_detalle(Carro ***, int);
void ver_producidos(vector<Carro *>);
bool trabajar(Carro ***, int, vector<Carro *> &);

int main() {
  int lineas_activas = 0;
  Carro ***lineas_produccion;
  iniciar_lp(lineas_produccion);

  vector<Carro *> producidos;

  int opcion = 1;
  string cadena;

  while (opcion != 0) {
    cout
      << "Lab 4\n"
      << "1) Agregar linea de produccion\n"
      << "2) Ver lineas de produccion\n"
      << "3) Ver lineas de produccion detallado\n"
      << "4) Ver listado de carros producidos\n"
      << "5) Trabajar en produccion\n"
      << "0) Salir\n"
      << "Seleccione: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        if (agregar_linea_lazy(lineas_produccion, lineas_activas)) {
          cout << "Linea de produccion #" << lineas_activas << " agregada.\n";
          lineas_activas += 1;
        } else {
          cout << "Lineas de produccion llenas.\n";
        }
        break;

      case 2:
        ver(lineas_produccion, lineas_activas);
        break;

      case 3:
        ver_detalle(lineas_produccion, lineas_activas);
        break;

      case 4:
        ver_producidos(producidos);
        break;

      case 5:
        if (trabajar(lineas_produccion, lineas_activas, producidos)) {
          cout << "Se avanzo en la produccion!\n";
        } else {
          cout << "Lineas de produccion vacias.\n";
        }
        break;

      case 0:
        cout << "Saliendo...\n";
        liberar_lp(lineas_produccion);
        liberar_vec(producidos);
        break;

      default:
        cout << "Opcion no valida\n";
        break;
    }
  }
  return 0;
}

void iniciar_lp(Carro ***&lineas_produccion) {
  // maximo de 5 lineas de produccion
  // tienen 3 fases + fase inicial con carro modelo
  lineas_produccion = new Carro**[5];
  for (int i = 0; i < 5; i += 1) {
    lineas_produccion[i] = new Carro*[4];
    for (int j = 0; j < 4; j += 1) {
      lineas_produccion[i][j] = NULL;
    }
  }
}

void liberar_lp(Carro ***&lineas_produccion) {
  for (int i = 0; i < 5; i += 1) {
    for (int j = 0; j < 4; j += 1) {
      if (lineas_produccion[i][j] != NULL) {
        cout << "Eliminando a " << lineas_produccion[i][j]->id() << '\n';
        delete lineas_produccion[i][j];
      }
    }
    delete[] lineas_produccion[i];
  }
  delete[] lineas_produccion;
}

void liberar_vec(vector<Carro *> vec) {
  for (int i = 0; i < vec.size(); i += 1) {
    cout << "Eliminando prod " << vec[i]->id() << '\n';
    delete vec[i];
  }
}

bool agregar_linea(Carro ***lineas_produccion, int lineas_activas) {
  if (lineas_activas >= 5) {
    return false;
  }
  cout << "Crear el carro modelo:\n";
  Carro *modelo = new Carro();
  modelo->setChassis(new Chassis());
  modelo->setMotor(new Motor());
  modelo->setPintura(new Pintura());

  cout << "Informacion del carro modelo:\n" << modelo->id() << '\n';
  // agregar el modelo en la linea de produccion
  lineas_produccion[lineas_activas][0] = modelo;
  lineas_activas += 1;
  return true;
}

bool agregar_linea_lazy(Carro ***lineas_produccion, int lineas_activas) {
  if (lineas_activas >= 5) {
    return false;
  }
  cout << "Crear el carro modelo:\n";
  Carro *modelo = new Carro();
  modelo->setChassis(new Chassis(true, "ruedas bonitas"));
  modelo->setMotor(new Motor(true, "electrico"));
  modelo->setPintura(new Pintura("rojo", "matte"));

  cout << "Informacion del carro modelo:\n" << modelo->id() << '\n';
  // agregar el modelo en la linea de produccion
  lineas_produccion[lineas_activas][0] = modelo;
  return true;
}

void ver(Carro ***lineas_produccion, int lineas_activas) {
  for (int i = 0; i < lineas_activas; i += 1) {
    for (int j = 0; j < 4; j += 1) {
      if (lineas_produccion[i][j] == NULL) {
        cout << "[ ]";
      } else if (lineas_produccion[i][j]->getPrototipo()) {
        cout << "[P]";
      } else {
        cout << "[C]";
      }
    }
    cout << '\n';
  }
}

void ver_detalle(Carro ***lineas_produccion, int lineas_activas) {
  for (int i = 0; i < lineas_activas; i += 1) {
    cout << "Linea de produccion [" << i << "]\n";
    for (int j = 1; j < 4; j += 1) {
      if (lineas_produccion[i][j] != NULL) {
        cout
          << "Paso de produccion [" << j << "]\n"
          << "Informacion de carro " << lineas_produccion[i][j]->id() << ":\n"
          << lineas_produccion[i][j]->info();
      }
    }
    cout << '\n';
  }
}

void ver_producidos(vector<Carro *> producidos) {
  for (int i = 0; i < producidos.size(); i += 1) {
    cout << "Carro producido " << producidos[i]->id() << ":\n" << producidos[i]->info();
  }
}

bool trabajar(Carro ***lineas_produccion, int lineas_activas, vector<Carro *> &producidos) {
  if (lineas_activas == 0) {
    return false;
  }

  // revisar si las lineas de produccion estan vacias inicialmente
  Carro *prototipo;
  Carro *actual;
  for (int i = 0; i < lineas_activas; i += 1) {
    prototipo = lineas_produccion[i][0];
    for (int j = 3; j > 0; j -= 1) {
      actual = lineas_produccion[i][j];

      if (actual == NULL) {
        continue;
      }

      // agregar pintura
      if (j == 3) {
        actual->setPintura(prototipo->clonePintura());
        producidos.push_back(actual);
      }

      // agregar motor
      if (j == 2) {
        actual->setMotor(prototipo->cloneMotor());
      }

      // agregar chassis
      if (j == 1) {
        actual->setChassis(prototipo->cloneChassis());
      }

      // pasar el auto a la siguiente linea de produccion
      if (j == 1 || j == 2) {
        lineas_produccion[i][j + 1] = actual;
      }
    }
    lineas_produccion[i][1] = prototipo->clone();
  }
  return true;
}
