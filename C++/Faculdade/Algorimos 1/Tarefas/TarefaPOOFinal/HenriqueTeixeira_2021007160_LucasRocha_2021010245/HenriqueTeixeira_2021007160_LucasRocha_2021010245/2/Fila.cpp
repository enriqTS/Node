#include <iostream>
#include "./Fila (1).h"
using namespace std;

int main()
{
    int intValue = 1;
    cout << "\nFila vazia. Nao pode remover mais itens\n";

    Fila<int> F1(5);
    while (F1.push(intValue))
    {
        cout << intValue << " ";
        intValue++;
    }
    cout << endl;

    Fila<int> F2(8);
    while (F2.push(intValue))
    {
        cout << intValue << ' ';
        intValue--;
    }
    cout << endl;

    Fila<int> F3;

    F3 = F1 + F2;

    cout << endl;
    intValue = 0;
    while (F3.pop(intValue))
        cout << intValue << ' ';

    cout << endl;
    return 0;
}
