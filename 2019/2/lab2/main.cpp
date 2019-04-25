#include <iostream>
#include <string>

using namespace std;

int captcha_simple(string);
int captcha_mkII(string);
void perfectos(int);
bool es_perfecto(int);
void print_factores(int);
void permutaciones(string);
void perm_recursiva(string, int);

int main() {
  int opcion = 1;
  int P;
  string cadena;

  while (opcion != 0) {
    cout
      << "Lab 2\n"
      << "1) Ejercicio 1\n"
      << "2) Ejercicio 2\n"
      << "3) Ejercicio 3\n"
      << "0) Salir\n"
      << "Seleccione: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        cout << "Ingrese la cadena: ";
        cin >> cadena;
        cout << "Captcha de " << cadena << " es " << captcha_simple(cadena) << '\n';
        cout << "Captcha v2 de " << cadena << " es " << captcha_mkII(cadena) << '\n';
        break;

      case 2:
        cout << "Ingrese el numero P: ";
        cin >> P;
        perfectos(P);
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

int captcha_simple(string cadena) {
  // con el siguiente caracter
  int suma = 0;
  int l = cadena.length();
  char ultimo = cadena[l - 1];
  char actual;

  for (int i = 0; i < l; i += 1) {
    actual = cadena[i];
    if (actual == ultimo) {
      suma += actual - '0';
    }
    ultimo = actual;
  }
  return suma;
}

int captcha_mkII(string cadena) {
  // con el caracter a la siguiente mitad
  int suma = 0;
  int l = cadena.length();
  int mitad = l / 2;
  char ultimo = cadena[mitad];
  char actual;

  for (int i = 0; i < l; i += 1) {
    actual = cadena[i];
    if (actual == ultimo) {
      suma += actual - '0';
    }

    mitad = (mitad + 1) % l;
    ultimo = cadena[mitad];
  }
  return suma;
}

void perfectos(int P) {
  bool perfecto = es_perfecto(P);
  if (perfecto) {
    cout << "El numero " << P << " es perfecto";
    print_factores(P);
  } else {
    cout << "El numero " << P << " no es perfecto, el numero perfecto mas cercano es ";
    for (int i = P - 1; i >= 6; i -= 1) {
      if (es_perfecto(i)) {
        cout << i;
        print_factores(i);
        break;
      }
    }
  }
}

bool es_perfecto(int P) {
  int suma = 0;
  for (int i = 1; i < P; i += 1) {
    if (P % i == 0) {
      suma += i;
    }
  }
  return suma == P;
}

void print_factores(int P) {
  cout << ", sus factores son ";
  for (int i = 1; i < P; i += 1) {
    if (P % i == 0) {
      cout << i << ", ";
    }
  }
  cout << '\n';
}

void permutaciones(string cadena) {
  cout << "Permutaciones de " << cadena << '\n';
  perm_recursiva(cadena, 0);
  cout << '\n';
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
