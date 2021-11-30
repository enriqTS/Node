// Stack.h
// Template de classe Stack.

#ifndef STACK_H
#define STACK_H

template< typename T >
class Stack {
public:
   Stack( int = 10 ); // construtor padrão (tamanho de Stack 10)
   ~Stack(){    // destrutor
      delete [] stackPtr; // desaloca o espaço interno para Stack
   }
   bool push( const T& ); // insere (push) um elemento na Stack
   bool pop( T& ); // remove (pop) um elemento da Stack
   bool isEmpty(){    // determina se a Stack está vazia
         return top == -1;
   }
   bool isFull(){ // determina se Stack está cheia
      return top == size - 1;
   }
private:
  int size; // número de elementos na Stack
  int top;// localização do elemento superior (-1 significa vazio)
   T *stackPtr; // ponteiro para a representação interna da Stack
};

// template construtora
template< typename T >
Stack< T >::Stack( int s )
   : size( s > 0 ? s : 10 ), // valida o tamanho
     top( -1 ), // Stack inicialmente vazia
     stackPtr( new T[ size ] ) // aloca memória para elementos
{
   // corpo vazio
} // fim da template construtora Stack

// insere elemento na Stack;
// se bem-sucedida, retorna true; caso contrário, retorna false
template< typename T >
bool Stack< T >::push( const T &pushValue )
{
   if ( !isFull() )
   {
      stackPtr[ ++top ] = pushValue; // insere item em Stack
      return true; // inserção bem-sucedido
   } // fim do if

   return false; // inserção mal-sucedido
} // fim da template de função push

// remove elemento da Stack;
// se bem-sucedida, retorna true; caso contrário, retorna false
template< typename T >
bool Stack< T >::pop( T &popValue )
{
   if ( !isEmpty() )
   {
      popValue = stackPtr[ top-- ]; // remove item da Stack
      return true; // remoção bem-sucedida
   } // fim do if

   return false; // remoção mal-sucedida
} // fim da template de função pop

#endif
