#include <iostream>
#include <string.h>
using namespace std;

template <class T>
T& minimo (T& p1, T& p2){
	return (p1 < p2) ? p1 : p2;
}

char * minimo(char * s1, char *s2){
 return (strcmp (s1,s2) < 0 ) ? s1 : s2;
}

int main () {
 int a,b;   float c,d;
 cout << "Digite dois numeros inteiros: ";  cin >> a >> b;
 cout <<"o menor numero inteiro digitado foi:" << minimo(a,b);
 cout << "\nDigite dois numeros reais: ";  cin >> c >> d;
 cout << "o menor numero float digitado foi: " << minimo(c,d);
 char nome1[ ] = "joao" , nome2[ ] = "maria";
 cout << "\n O minimo : " << minimo (nome1, nome2);
 return 0;
}
