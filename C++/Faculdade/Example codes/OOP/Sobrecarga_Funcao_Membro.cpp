// Sobrecarga de operadores com Funcao Membro
// (C) Copyright Fernando Montenegro e Roberto Pacheco

#include <iostream>

using namespace std;

class Complexo {
 private:
  double real;
  double imaginario;
 public :
  inline Complexo(double = 0, double = 0);
  Complexo operator + (Complexo&);
  inline void mostra();
};

int main () {
  Complexo Z (5,3); // Numero 5 + 3i
  Complexo Y (2,1); // Numero 2 + i
  Complexo R;       // inicializado com 0 + 0i
  R = Z + Y;
  Z.mostra(); Y.mostra();
  cout << "\n\nSoma de Z + Y : ";
  R.mostra();
  return 0;
}

Complexo :: Complexo(double real, double imaginario) {
  this->real = real;
  this->imaginario = imaginario;
}

Complexo Complexo :: operator + (Complexo& n) {
  Complexo aux;
  aux.real = this->real + n.real;
  aux.imaginario = this->imaginario + n.imaginario;
  return aux;
}

void Complexo :: mostra() {
  cout << "\nNumero Imaginario = " << real
       << " + " << imaginario << "i";
}
