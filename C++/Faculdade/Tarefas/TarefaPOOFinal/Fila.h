#ifndef FILA_H
#define FILA_H

template< typename T >
class Fila {
public:
   Fila( int = 10 ); 
   ~Fila(){  
      delete [] filaPtr; 
   }
   bool push( const T& ); 
   bool pop( T& );
   bool isEmpty(){  
         return Fim == -1 || Com == size - 1;
   }
   bool isFull(){
      return Fim == size - 1;
   }
   int Fsize(){
      return size;
   }
   friend Fila<T> operator+(Fila<T>& F1, Fila<T>& F2);
       
private:
  int size; 
  int Com;
  int Fim;
   T *filaPtr; 
};

template< typename T >
Fila< T >::Fila( int s ):size( s > 0 ? s : 10 ),
     Com( -1 ),
     Fim( -1 ),
     filaPtr( new T[ size ] ) 
{
} 

template< typename T >
bool Fila< T >::push( const T &pushValue )
{
   if ( !isFull() )
   {
      filaPtr[ ++Fim ] = pushValue;
      if( isEmpty() )
      {
         filaPtr[ Com ] = pushValue;
      }
      return true;
   } 

   return false; 
} 

template< typename T >
bool Fila< T >::pop( T &popValue )
{
   if ( !isEmpty() )
   {
      popValue = filaPtr[ ++Com ];
      return true; 
   } 
   return false; 
} 

template< typename T >
Fila<T> operator+ (Fila<T>& F1, Fila<T>& F2){
    int sum;
    Fila < T > Fila;

    while(!F1.isEmpty() || !F2.isEmpty()){
        if(!F1.isEmpty() && !F2.isEmpty()){
            sum = filaPtr[ F1.ItemFila ] + filaPtr[ F2.ItemFila ];
            filaPtr[ Fila.ItemFila ] = sum;
        }
        else if(F1.isEmpty() && !F2.isEmpty()){
            filaPtr[ Fila.ItemFila ] = filaPtr[ F2.ItemFila ]; 
        }
        else if(!F1.isEmpty() && F2.isEmpty()){
        filaPtr[ Fila.ItemFila ] = filaPtr[ F1.ItemFila ]; 
        }
        if(!F1.isEmpty()){
            filaPtr[ F1.ItemFila++ ];
        }
        if(!F2.isEmpty()){
            filaPtr[ F2.ItemFila++ ];
        }
    }
    
    return Fila;
}

#endif