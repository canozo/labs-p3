#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <iostream>
#include "Game.h"

#define SLEEP_BATALLA 10000
#define SLEEP_DINERO 7000
#define SLEEP_VIDA 6000

using namespace std;

Game::Game() {
  this->dinero = 0;
  this->vida = 1;
  this->max_vida = 3;
  this->nivel = 1;
  this->batalla = false;

  this->hilo_batalla = true;
  this->hilo_dinero = true;
  this->hilo_vida = true;

  this->run_batalla();
  this->run_dinero();
  this->run_vida();
}

int Game::getVida() {
  return vida;
}

int Game::getVidaOp() {
  return vida_oponente;
}

bool Game::play(int opc_jg) {
  // opcion del oponente
  int opc_op = rand() % 3 + 1;
  if (opc_op == opc_jg) {
    cout << "Jugador y Oponente escogieron lo mismo!\n";
    return false;
  } else if (opc_jg == 1 && opc_op == 3) {
    cout << "Jugador: Piedra!\n"
      << "Oponente: Tijera!\n";
    vida_oponente -= 1;
  } else if (opc_jg == 1 && opc_op == 2) {
    cout << "Jugador: Piedra!\n"
      << "Oponente: Papel!\n";
    vida -= 1;
  } else if (opc_jg == 2 && opc_op == 1) {
    cout << "Jugador: Papel!\n"
      << "Oponente: Piedra!\n";
    vida_oponente -= 1;
  } else if (opc_jg == 2 && opc_op == 3) {
    cout << "Jugador: Papel!\n"
      << "Oponente: Tijera!\n";
    vida -= 1;
  } else if (opc_jg == 3 && opc_op == 1) {
    cout << "Jugador: Tijera!\n"
      << "Oponente: Piedra!\n";
    vida -= 1;
  } else if (opc_jg == 3 && opc_op == 2) {
    cout << "Jugador: Tijera!\n"
      << "Oponente: Papel!\n";
    vida_oponente -= 1;
  }

  if (vida == 0) {
    // perdio
    cout << "Perdio!\n";
    batalla = false;
  }

  if (vida_oponente == 0) {
    // gano
    cout << "Gano!\n";
    nivel += 1;
    max_vida += 1;
    batalla = false;
  }

  return batalla;
}

bool Game::busy() {
  return batalla;
}

void Game::comprar_cura() {
  if (dinero == 0) {
    cout << "No tiene suficiente dinero!\n";
    return;
  }

  if (batalla) {
    cout << "No deberia de estar comprando!\n";
    return;
  }

  if (vida == max_vida) {
    cout << "Tiene la vida llena!\n";
    return;
  }

  vida += 1;
  dinero -= 1;
  cout << "+1 vida!\n"
    << "-1 dinero!\n"
    << "Se realizo la compra!\n";
}

void Game::print_info() {
  cout << "Nivel: " << nivel << '\n';
  cout << "Dinero: " << dinero << '\n';
  cout << "Vida: " << vida << '/' << max_vida << '\n';
}

void Game::stop() {
  this->hilo_batalla = false;
  this->hilo_dinero = false;
  this->hilo_vida = false;
}

void Game::run_batalla() {
  _beginthread(&Game::runner_batalla, 0, static_cast<void *>(this));
}

void Game::runner_batalla(void *o) {
  srand(time(NULL));
  static_cast<Game *>(o)->call_batalla();
}

void Game::call_batalla() {
  while (hilo_batalla) {
    Sleep(SLEEP_BATALLA);
    int num = rand() % 100;

    if (!batalla && num > 20) {
      empezar_batalla();
    }
  }
  _endthread();
}

void Game::empezar_batalla() {
  batalla = true;
  vida_oponente = nivel;
  cout << "\n\nBATALLA ENCONTRADA!\n"
    << "Vida Jugador: " << vida << '\n'
    << "Vida Oponente: " << vida_oponente << '\n'
    << "1) Piedra\n"
    << "2) Papel\n"
    << "3) Tijera\n"
    << "Seleccione una opcion: ";
}

void Game::run_dinero() {
  _beginthread(&Game::runner_dinero, 0, static_cast<void *>(this));
}

void Game::runner_dinero(void *o) {
  srand(time(NULL));
  static_cast<Game *>(o)->call_dinero();
}

void Game::call_dinero() {
  while (hilo_dinero) {
    Sleep(SLEEP_DINERO);
    if (!batalla) {
      dinero += 1;
      cout << "\n+1 de dinero!\n"
        << "Seleccione una opcion: ";
    }
  }
  _endthread();
}

void Game::run_vida() {
  _beginthread(&Game::runner_vida, 0, static_cast<void *>(this));
}

void Game::runner_vida(void *o) {
  srand(time(NULL));
  static_cast<Game *>(o)->call_vida();
}

void Game::call_vida() {
  while (hilo_vida) {
    Sleep(SLEEP_VIDA);
    if (!batalla && vida < max_vida) {
      vida += 1;
      cout << "\n+1 de vida!\n"
        << "Seleccione una opcion: ";
    }
  }
  _endthread();
}
