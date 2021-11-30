#include <iostream>
using namespace std;

int minimo(int& , int&);
float minimo(float& , float&);

int main () {
  int a,b;
  cout << "Digite dois numeros: ";
  cin >> a >> b;
  cout << "o menor numero digitado foi: " << minimo(a,b);
  return 0;
}
int minimo (int& a, int& b){ return (a < b) ? a : b;  }
float minimo (float& a, float& b){ return (a < b) ? a : b;}
