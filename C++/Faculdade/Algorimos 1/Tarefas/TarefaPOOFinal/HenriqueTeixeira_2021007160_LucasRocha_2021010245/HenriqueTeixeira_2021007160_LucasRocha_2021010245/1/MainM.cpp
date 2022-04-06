#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main()
{
    // Somente matrizes quadradas
    Matriz m(3, 3);
    m.insere(1);
    m.insere(8);
    m.insere(3);
    m.insere(3);
    m.insere(9);
    m.insere(5);
    m.insere(7);
    m.insere(4);
    m.insere(4);

    m.mostra();
    cout << "Soma diagonal: " << m.soma_diagonal() << endl;

    cout << "Máximo: " << m.maximo() << endl
         << endl;

    Matriz m2(3, 3);
    m2.insere(1);
    m2.insere(8);
    m2.insere(3);
    m2.insere(3);
    m2.insere(9);
    m2.insere(5);
    m2.insere(7);
    m2.insere(4);
    m2.insere(4);

    m2.mostra();

    Matriz m3(3,3);

    cout << endl;

    m3 = m + m2;

    cout << "Matriz m1 e m2 sendo somadas: " << endl; 
    m3.mostra();

    cout << endl;

    return 0;
}