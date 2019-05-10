#include <iostream>
#include <string>

#define HARD_MODE true

using namespace std;

void new_dungeon(char **&, int, int);
void delete_dungeon(char **&, int);
bool iniciar_dungeon(char **&, int *, int *);
bool descifrar(char **, int, int);
void imprimir(char **, int, int);
int seguros(char **, int, int);

int main() {
  int pisos = 0;
  int tiles = 0;
  char **dungeon = NULL;
  int opcion = 1;
  int temp;

  while (opcion != 0) {
    cout
      << "Lab 4\n"
      << "1) Ingresar el piso inicial\n"
      << "2) Descifrar el dungeon\n"
      << "3) Mostrar el dungeon\n"
      << "4) Contar el numero de cuadros seguros\n"
      << "0) Salir\n"
      << "Seleccione: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        iniciar_dungeon(dungeon, &pisos, &tiles);
        break;

      case 2:
        descifrar(dungeon, pisos, tiles);
        break;

      case 3:
        imprimir(dungeon, pisos, tiles);
        break;

      case 4:
        temp = seguros(dungeon, pisos, tiles);
        if (temp > 0) {
          cout << "Hay " << temp << " cuadros seguros.\n";
        }
        break;

      case 0:
        cout << "Saliendo...\n";
        break;

      default:
        cout << "Opcion no valida\n";
        break;
    }
  }
  delete_dungeon(dungeon, pisos);
  return 0;
}

void new_dungeon(char **&dungeon, int pisos, int tiles) {
  dungeon = new char*[pisos];
  for (int i = 0; i < pisos; i += 1) {
    dungeon[i] = new char[tiles];
    for (int j = 0; j < tiles; j += 1) {
      dungeon[i][j] = ' ';
    }
  }
}

void delete_dungeon(char **&dungeon, int pisos) {
  if (dungeon != NULL) {
    for (int i = 0; i < pisos; i += 1) {
      delete dungeon[i];
    }
    delete[] dungeon;
  }
}

bool iniciar_dungeon(char **&dungeon, int *pisos, int *tiles) {
  if (dungeon != NULL) {
    cout << "Ya se creo el dungeon\n";
    return false;
  }
  // revisar que piso inicial solo contiene '.' y '^'
  string piso_inicial = ".^^.^.^^^^";
  int num_pisos = 10;

  if (HARD_MODE) {
    piso_inicial = "......^.^^.....^^^^^^^^^...^.^..^^.^^^..^.^..^.^^^.^^^^..^^.^.^.....^^^^^..^..^^^..^^.^.^..^^..^^^..";
    num_pisos = 400000;
  }

  new_dungeon(dungeon, num_pisos, piso_inicial.length());

  // setear el piso inicial
  for (int i = 0; i < piso_inicial.length(); i += 1) {
    dungeon[0][i] = piso_inicial[i];
  }

  *pisos = num_pisos;
  *tiles = piso_inicial.length();

  return true;
}

bool descifrar(char **dungeon, int pisos, int tiles) {
  if (dungeon == NULL) {
    cout << "Debe crear el piso inicial primero.\n";
    return false;
  }

  for (int i = 1; i < pisos; i += 1) {
    for (int j = 0; j < tiles; j += 1) {
      char left = j == 0 ? '.' : dungeon[i - 1][j - 1];
      char center = dungeon[i - 1][j];
      char right = j == tiles - 1 ? '.' : dungeon[i - 1][j + 1];

      string res = "";
      res += left;
      res += center;
      res += right;

      char current = '.';
      if (res == "^^." || res == ".^^" || res == "^.." || res == "..^") {
        current = '^';
      }
      dungeon[i][j] = current;
    }
  }

  return true;
}

void imprimir(char **dungeon, int pisos, int tiles) {
  if (dungeon == NULL) {
    cout << "Debe crear el dungeon primero.\n";
  } else {
    for (int i = 0; i < pisos; i += 1) {
      for (int j = 0; j < tiles; j += 1) {
        cout << dungeon[i][j];
      }
      cout << '\n';
    }
  }
}

int seguros(char **dungeon, int pisos, int tiles) {
  if (dungeon == NULL) {
    cout << "Debe crear el dungeon primero.\n";
    return 0;
  }

  int res = 0;
  for (int i = 0; i < pisos; i += 1) {
    for (int j = 0; j < tiles; j += 1) {
      res += dungeon[i][j] == '.' ? 1 : 0;
    }
  }
  return res;
}
