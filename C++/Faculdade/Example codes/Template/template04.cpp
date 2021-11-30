//template04.cpp

#include <iostream>

using namespace std;

template <class T>
T& minimo (T& p1, T& p2){
	return (p1 < p2) ? p1 : p2;
}

int main () {
  char let = 'a';
  int num = 2, x = 10;
  int z = minimo (num,x); // gera minimo (int, int)
  minimo(num, let); // não encontra
  return 0;
}
