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
   Fila<T> operator+(Fila<T>& F);
       
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
Fila<T> Fila<T> :: operator+ (Fila<T>& F){
   T sum,x,y;
   Fila <int> F1(8);

   // while ( this->pop( sum ) )
   // std::cout << sum << ' ';

   // while ( F.pop( sum ) )
   // std::cout << sum << ' ';

   // while(!this->isEmpty() || !F.isEmpty()){
   //    if(!this->isEmpty() && !F.isEmpty()){
   //       this->pop(x);
   //       std::cout << x << std::endl;;
   //       F.pop(y);
   //       std::cout << y << std::endl;
   //       sum = x + y;
   //       std::cout << sum << std::endl;
   //       F1.push(sum);
   //    }   
   //    else if(this->isEmpty() && !F.isEmpty()){
   //       F.pop(y);
   //       std::cout << y << std::endl;
   //       F1.push(y); 
   //    }
   //    else if(!this->isEmpty() && F.isEmpty()){
   //       this->pop(x);
   //       std::cout << x << std::endl;
   //       F1.push(x); 
   //    }
   // }
   // return F1;

   while (this->pop(x) && F.pop(y))
   {
      sum = x + y;
      F1.push(sum);
   }
   if (!this->isEmpty())
   {
      F1.push(x);
      while (this->pop(x))
      {
         F1.push(x);
      }
   }
   if (!F.isEmpty())
   {
      F1.push(y);
      while (F.pop(y))
      {
         F1.push(y);
      }
   }
   return F1;
}

#endif