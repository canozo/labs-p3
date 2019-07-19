#include <iostream>
#include <string>

#define M 5

using namespace std;

int **crearMatriz();
void borrarMatriz(int **);
void puntoDeSilla(int **);
bool minimoFila(int **, int, int);
bool maximoColumna(int **, int, int);
int esTriangular(int);
void execTriangular();
void permutaciones(string);
bool repetidos(string);
void perm_recursiva(string, int);

int main() {
  int opcion = 1;
  string cadena;
  int **matrizTemp;

  while (opcion != 0) {
    cout
      << "Lab 1\n"
      << "1) Ejercicio 1\n"
      << "2) Ejercicio 2\n"
      << "3) Ejercicio 3\n"
      << "0) Salir\n"
      << "Seleccione: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        matrizTemp = crearMatriz();
        puntoDeSilla(matrizTemp);
        borrarMatriz(matrizTemp);
        break;

      case 2:
        execTriangular();
        break;

      case 3:
        cout << "Ingrese la cadena: ";
        cin >> cadena;
        permutaciones(cadena);
        break;

      case 0:
        cout << "Saliendo...\n";
        break;

      default:
        cout << "Opcion no valida\n";
        break;
    }
  }
  return 0;
}

int **crearMatriz() {
  // copiar una matriz de prueba
  int matriz[M][M] = {
    {43, 46, 78, 67, 98},
    {15, 10, 68, 22, 11},
    {27, 20, 55, 70, 67},
    {38, 91, 89, 56, 28},
    {19, 98, 33, 39, 64},
  };

  int **res = new int*[M];
  for (int i = 0; i < M; i += 1) {
    res[i] = new int[M];
    for (int j = 0; j < M; j += 1) {
      res[i][j] = matriz[i][j];
    }
  }

  return res;
}

void borrarMatriz(int **matriz) {
  for (int i = 0; i < M; i += 1) {
    delete[] matriz[i];
  }
  delete[] matriz;
}

void puntoDeSilla(int **matriz) {
  // minimo en la fila, maximo en la columna
  int encontrados = 0;
  bool resFila, resColumna;

  // imprimir matriz
  cout << "Imprimiendo matriz:" << endl;
  for (int i = 0; i < M; i += 1) {
    for (int j = 0; j < M; j += 1) {
      cout << matriz[i][j] << ' ';
    }
    cout << endl;
  }

  for (int i = 0; i < M; i += 1) {
    for (int j = 0; j < M; j += 1) {
      resFila = minimoFila(matriz, i, j);
      resColumna = maximoColumna(matriz, i, j);

      if (resFila && resColumna) {
        cout << "Hay un punto de silla en (" << i << ", " << j << ") con valor " << matriz[i][j] << endl;
        encontrados += 1;
      }
    }
  }

  cout << "Se encontraron " << encontrados << " puntos de silla" << endl;
}

bool minimoFila(int **matriz, int i, int j) {
  int actual = matriz[i][j];
  int comparar;
  int fila = i;

  for (int columna = 0; columna < M; columna += 1) {
    if (columna == j) {
      continue;
    }
    comparar = matriz[fila][columna];

    // existe uno mas pequenio
    if (actual > comparar) {
      return false;
    }
  }

  // es el minimo
  return true;
}

bool maximoColumna(int **matriz, int i, int j) {
  int actual = matriz[i][j];
  int comparar;
  int columna = j;

  for (int fila = 0; fila < M; fila += 1) {
    if (fila == i) {
      continue;
    }
    comparar = matriz[fila][columna];

    // existe uno mas grande
    if (actual < comparar) {
      return false;
    }
  }

  // es el maximo
  return true;
}

int esTriangular(int num) {
  int sumatoria = 0;
  for (int i = 0; i <= num; i++) {
    sumatoria += i;
    if (sumatoria == num) {
      break;
    } else if (sumatoria > num) {
      sumatoria -= i;
      break;
    }
  }
  return sumatoria;
}

void execTriangular() {
  int userInput = 0;
  do {
    cout << "Ingrese un numero positivo: ";
    cin >> userInput;
  } while (userInput <= 0);
  int resTriangular = esTriangular(userInput);

  if (resTriangular == userInput) {
    cout << "El numero " << userInput << " es triangular" << endl;
  } else {
    cout << "El numero " << userInput << " no es triangular" << endl;
    cout << "El numero triangular mas cercano a " << userInput << " es " << resTriangular << endl;
  }
}

void permutaciones(string cadena) {
  // revisar si hay repetidos en la cadena
  if (repetidos(cadena)) {
    cout << "Hay caracteres repetidos en la cadena!" << endl;
    return;
  }

  cout << "Permutaciones de " << cadena << '\n';
  perm_recursiva(cadena, 0);
  cout << '\n';
}

bool repetidos(string cadena) {
  for (int i = 0; i < cadena.length(); i += 1) {
    for (int j = 0; j < cadena.length(); j += 1) {
      if (i == j) {
        continue;
      }
      if (cadena[i] == cadena[j]) {
        return true;
      }
    }
  }
  return false;
}

void perm_recursiva(string cadena, int pos) {
  char temp;
  if (pos != cadena.length() - 1) {
    for (int i = pos; i < cadena.length(); i += 1) {
      temp = cadena[pos];
      cadena[pos] = cadena[i];
      cadena[i] = temp;

      perm_recursiva(cadena, pos + 1);

      temp = cadena[pos];
      cadena[pos] = cadena[i];
      cadena[i] = temp;
    }
  } else {
    cout << cadena << '\n';
  }
}
