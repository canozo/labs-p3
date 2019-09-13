#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

using namespace std;

void menu();
void menu_batalla(int, int);

void opc(Game *, int);
void opc_batalla(Game *, int);

int main(int argc, char** argv) {
  srand(time(NULL));

  Game game;
  int opcion = 1;

  while (opcion != 0) {
    if (!game.busy()) {
      menu();
    } else {
      menu_batalla(game.getVida(), game.getVidaOp());
    }
    cin >> opcion;

    if (!game.busy()) {
      opc(&game, opcion);
    } else {
      opc_batalla(&game, opcion);
      if (game.getVida() == 0) {
        cout << "Perdio la partida!\n";
        game.print_info();
        opcion = 0;
      }
    }
  }

  game.stop();
  return 0;
}

void menu() {
  cout << "\nMENU\n"
    << "1) Datos del jugador\n"
    << "2) Curar vida ($1)\n"
    << "0) Salir\n"
    << "Seleccione una opcion: ";
}

void menu_batalla(int vida, int vida_oponente) {
  cout << "\nBATALLA!\n"
    << "Vida Jugador: " << vida << '\n'
    << "Vida Oponente: " << vida_oponente << '\n'
    << "1) Piedra\n"
    << "2) Papel\n"
    << "3) Tijera\n"
    << "Seleccione una opcion: ";
}

void opc(Game *game, int opcion) {
  switch (opcion) {
    case 1:
      game->print_info();
      break;

    case 2:
      game->comprar_cura();
      break;

    case 0:
      break;

    default:
      cout << "Opcion no valida!\n";
      break;
  }
}

void opc_batalla(Game *game, int opcion) {
  switch (opcion) {
    case 1:
    case 2:
    case 3:
      if (!game->play(opcion)) {
        cout << "Partida terminada!\n";
      }
      break;

    default:
      cout << "Opcion de batalla no valida!\n";
      break;
  }
}
