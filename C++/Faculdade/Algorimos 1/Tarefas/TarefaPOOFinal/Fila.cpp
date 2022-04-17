#include<iostream>
#include "Fila (1).h"

using std::cout;
using std::endl;

int main(){
    Fila < int > intFila ( 8 );
    int intValue = 1;

    while ( intFila.push( intValue ) )
    {
        cout << intValue << ' ';
        intValue++;
    } 

    while ( intFila.pop( intValue ) )
    cout << intValue << ' ';

    cout << "\nFila vazia. Nao pode remover mais itens\n";

    Fila < float > floatFila;
    float floatValue = 1.1;

    while (floatFila.push( floatValue )){
        cout << floatValue << ' ';
        floatValue += 1.1;
    } 

    while ( floatFila.pop( floatValue ) )
    cout << floatValue << ' ';

    cout << "\nFila vazia. Nao pode remover mais itens\n";

    Fila < int > F1 ( 5 );
    F1.push(1);
    F1.push(5);
    F1.push(8);
    F1.push(3);
    F1.push(2);

    Fila < int > F2 ( 8 );
    F2.push(1);
    F2.push(5);
    F2.push(8);
    F2.push(3);
    F2.push(2); 
    F2.push(8);
    F2.push(3);
    F2.push(2);

    Fila < int > F3(8);

    F3 = F1 + F2;  

    int value;
    while ( F3.pop( value ) )
    cout << value << ' '; 
    cout << endl; 

    while ( F1.pop( value ) )
    cout << value << ' ';
    cout << endl;  

    while ( F2.pop( value ) )
    cout << value << ' ';
    cout << endl;

    return 0;
}
