//template06.cpp

#include <iostream>

using namespace std;

template <class T>
T& total(T& atual) {
  static T total = 0;
  total += atual;
  return total;
}

int main() {
  cout << "\n\nTotal de ints    : ";
  for (int i = 0; i < 5; i++)
    cout << '\t' << total(i);
  double x = 2300.60, y = 3700.40, z = 1000;
  cout << "\nTotal de doubles : \t" << total(x);
  cout << '\t' << total(y);
  cout << '\t' << total(z) << "\n";
  return 0;
}
