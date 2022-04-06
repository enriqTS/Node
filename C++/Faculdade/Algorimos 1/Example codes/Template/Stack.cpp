//template07.cpp

#include <iostream>
using std::cout;
using std::endl;

#include "Stack.h" // Definição de template de classe Stack

int main(){

   Stack< double > doubleStack( 5 ); // tamanho 5
   double doubleValue = 1.1;

   cout << "Empilhando elementos na pilha double\n";

   // insere 5 doubles em doubleStack
   while ( doubleStack.push( doubleValue ) )
   {
      cout << doubleValue << ' ';
      doubleValue += 1.1;
   } // fim do while

   cout << "\nPilha cheia. Nao pode empilhar " << doubleValue
      << "\n\nDesempilhando elementos da pilha double\n";

   // remove elementos de doubleStack
   while ( doubleStack.pop( doubleValue ) )
      cout << doubleValue << ' ';

   cout << "\nPilha vazia. Nao pode desempilhar\n";

   Stack< int > intStack; // tamanho padrão de 10
   int intValue = 1;
   cout << "\nEmpilhando elementos na pilha int \n";

   // insere 10 inteiros em intStack
   while ( intStack.push( intValue ) )
   {
      cout << intValue << ' ';
      intValue++;
   } // fim do while

   cout << "\nPilha cheia. Nao pode empilhar " << intValue
      << "\n\nDesempilhando elementos da pilha int\n";

   // remove elementos de intStack
   while ( intStack.pop( intValue ) )
      cout << intValue << ' ';

   cout << "\nPilha vazia. Nao pode desempilhar" << endl;
   return 0;
} // fim de main
