#include <iostream>
#include <string>
#include <vector>

#include "Reposteria.h"
#include "Edificio.h"
#include "Granja.h"
#include "Banco.h"
#include "Templo.h"
#include "Mejora.h"
#include "Oreo.h"
#include "Migajas.h"

using namespace std;

int main(int argc, char** argv) {
  int opcion = 1;
  int cantidadGranjas = 0;
  int cantidadBancos = 0;
  int cantidadTemplos = 0;
  bool tieneOreo = false;
  bool tieneMigajas = false;

  string nombre;
  cout << "Ingrese el nombre del jugador: ";
  cin >> nombre;

  Reposteria *repo = new Reposteria(nombre);

  while (opcion != 0) {
    cout
      << "Reposteria de " << repo->getNombre() << " con " << repo->getGalletas() << " galletas:\n"
      << "1) Hacer clic\n"
      << "2) Comprar Granja\n"
      << "3) Comprar Banco\n"
      << "4) Comprar Templo\n"
      << "5) Comprar Oreo\n"
      << "6) Comprar Migajas\n"
      << "7) Mostrar Edificios y Mejoras\n"
      << "0) Salir\n"
      << "Seleccione una opcion: ";

    cin >> opcion;

    switch (opcion) {
      case 1:
        repo->clic();
        break;

      case 2: {
        Granja infoGranja;
        int total = infoGranja.getPrecio() + infoGranja.getAumento() * cantidadGranjas;
        if (repo->getGalletas() >= total) {
          cout << "Compro una granja!\n";
          repo->setGalletas(repo->getGalletas() - total);
          repo->agregarEdificio(new Granja());
        } else {
          cout << "No tiene suficientes galletas!\n";
        }
        break;
      }

      case 3: {
        Banco infoBanco;
        int total = infoBanco.getPrecio() + infoBanco.getAumento() * cantidadBancos;
        if (repo->getGalletas() >= total) {
          cout << "Compro un banco!\n";
          repo->setGalletas(repo->getGalletas() - total);
          repo->agregarEdificio(new Banco());
        } else {
          cout << "No tiene suficientes galletas!\n";
        }
        break;
      }

      case 4: {
        Templo infoTemplo;
        int total = infoTemplo.getPrecio() + infoTemplo.getAumento() * cantidadTemplos;
        if (repo->getGalletas() >= total) {
          cout << "Compro un templo!\n";
          repo->setGalletas(repo->getGalletas() - total);
          repo->agregarEdificio(new Templo());
        } else {
          cout << "No tiene suficientes galletas!\n";
        }
        break;
      }

      case 5: {
        if (tieneOreo) {
          cout << "Ya compro esta mejora!\n";
          break;
        }

        Oreo infoOreo;
        if (repo->getGalletas() >= infoOreo.getPrecio()) {
          cout << "Compro la mejora de Oreo!\n";
          repo->setGalletas(repo->getGalletas() - infoOreo.getPrecio());
          repo->agregarMejora(new Oreo());
          tieneOreo = true;
        } else {
          cout << "No tiene suficientes galletas!\n";
        }
        break;
      }

      case 6: {
        if (tieneMigajas) {
          cout << "Ya compro esta mejora!\n";
          break;
        }

        Migajas infoMigajas;
        if (repo->getGalletas() >= infoMigajas.getPrecio()) {
          cout << "Compro la mejora de Migajas!\n";
          repo->setGalletas(repo->getGalletas() - infoMigajas.getPrecio());
          repo->agregarMejora(new Migajas());
          tieneMigajas = true;
        } else {
          cout << "No tiene suficientes galletas!\n";
        }
        break;
      }

      case 7:
        repo->info();
        break;

      case 0:
        cout << "Saliendo...\n";
        break;

      default:
        cout << "Opcion no valida!\n";
        break;
    }
  }

  delete repo;

  return 0;
}
