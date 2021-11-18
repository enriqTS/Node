// Sobrecarga de operadores com Funcao Friend
// (C) Copyright Fernando Montenegro e Roberto Pacheco
#include <iostream>
using namespace std;

class Complexo {
  double real;
  double imaginario;
 public :
  inline Complexo(double = 0, double = 0);
  friend Complexo operator + (Complexo &, Complexo &);
  
  friend ostream &operator << (ostream &, const Complexo);
  friend istream &operator >> (istream &, Complexo &);
  
  inline void mostra();
};

int main () {
  Complexo Z (5,3); // Numero 5 + 3i
  Complexo Y (2,1); // Numero 2 + i
  Complexo R;       // inicializado com 0 + 0i
  R.mostra();
  R = Z + Y;
  Z.mostra(); Y.mostra(); 
  cout << "\n\nSoma de Z + Y : " << R << endl;
  //R.mostra();
  //cout << R << endl;
  Complexo temp1, temp2;
  cin >> temp1 >> temp2;
  cout << temp1 << "  " << temp2 << endl; 
  return 0;
}

Complexo :: Complexo(double r, double img) {
  real = r;
  imaginario = img;
}

Complexo operator + (Complexo& n1, Complexo& n2) {
  Complexo aux;
  aux.real = n1.real + n2.real;
  aux.imaginario = n1.imaginario + n2.imaginario;
  return aux;
}

void Complexo :: mostra() {
  cout << "\nNumero Imaginario = " << real
       << " + " << imaginario << "i";
}

ostream &operator << (ostream &saida, const Complexo n){
	saida << n.real << " + " << n.imaginario << "i" << endl;
	return saida;
}

istream &operator >> (istream & entrada, Complexo & n){
    	 entrada >> n.real;
    	 entrada.ignore();
    	 entrada >> n.imaginario;
    	 return entrada;
 }
     
