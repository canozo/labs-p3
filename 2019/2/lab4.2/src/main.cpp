#include <iostream>
#include <string>

using namespace std;

void new_dungeon(char **&, int);
void delete_dungeon(char **&, int);
int iniciar_dungeon(char **&);
bool descifrar(char **, int);


int main() {
  int dungeon_size = 0;
  char **dungeon = NULL;
  int opcion = 1;

  while (opcion != 0) {
    cout
      << "Lab 4\n"
      << "1) Ingresar el piso inicial\n"
      << "2) Descifrar el dungeon\n"
      << "0) Salir\n"
      << "0) Salir\n"
      << "Seleccione: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        dungeon_size = iniciar_dungeon(dungeon);
        break;

      case 2:
        descifrar(dungeon, dungeon_size);
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        break;

      case 0:
        cout << "Saliendo...\n";
        break;

      default:
        cout << "Opcion no valida\n";
        break;
    }
  }
  delete_dungeon(dungeon, dungeon_size);
  return 0;
}

void new_dungeon(char **&dungeon, int size) {
  dungeon = new char*[size];
  for (int i = 0; i < size; i += 1) {
    dungeon[i] = new char[size];
    for (int j = 0; j < size; j += 1) {
      dungeon[i][j] = '.';
    }
  }
}

void delete_dungeon(char **&dungeon, int size) {
  if (dungeon != NULL) {
    for (int i = 0; i < size; i += 1) {
      delete dungeon[i];
    }
    delete[] dungeon;
  }
}

int iniciar_dungeon(char **&dungeon) {
  if (dungeon != NULL) {
    cout << "Ya se creo el dungeon\n";
    return 0;
  }
  // revisar que piso inicial solo contiene '.' y '^'
  string piso_inicial = ".^^.^.^^^^";
  new_dungeon(dungeon, piso_inicial.length());
  return piso_inicial.length();
}

bool descifrar(char **dungeon, int size) {
  if (dungeon == NULL) {
    cout << "Debe crear el piso inicial primero.\n";
    return false;
  }

  return true;
}
