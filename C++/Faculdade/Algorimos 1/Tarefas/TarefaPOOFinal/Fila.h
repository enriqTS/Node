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
         return Tam == 0;
   }
   bool isFull(){
      return Tam == size;
   }
   int Fsize(){
      return Tam;
   }
   Fila<T> operator+(Fila<T>& F);
   inline Fila<T>& operator=(Fila<T>);
       
private:
  int size;
  int Tam; 
  int Com;
  int Fim;
   T *filaPtr; 
};

template< typename T >
Fila< T >::Fila( int s ):size( s > 0 ? s : 10 ),
     Com( 0 ),
     Fim( -1 ),
     Tam( 0 ),
     filaPtr( new T[ size ] ) 
{
} 

template< typename T >
bool Fila< T >::push( const T &pushValue )
{
   if (isFull())
      return false;
   Tam++;
   Fim = (Fim + 1) % size;
   filaPtr[ Fim ] = pushValue;
   return true;
} 

template< typename T >
bool Fila< T >::pop( T &popValue )
{
   if (isEmpty())
      return false;
   Tam--;
   popValue = filaPtr[ Com ];
   Com = (Com + 1) % size;
   return true; 
} 

template< typename T >
Fila<T> Fila<T> :: operator+ (Fila<T>& F){
   T sum,x,y;
   Fila <int> F1;
   if(!this->isEmpty() && !F.isEmpty()){
      if(this->Tam >= F.Tam){
         for(int i = 0; i<=F.Tam; i++){
            this->pop(x);
            F.pop(y);
            sum = x + y;
            F1.push(sum);
            this->push(x);
            F.push(y);
         }   
      }else{
         for(int i = 0; i<=this->Tam; i++){
            this->pop(x);
            F.pop(y);
            sum = x + y;
            F1.push(sum);
            this->push(x);
            F.push(y);
         }   
      }
   }   
   else if(this->isEmpty() && !F.isEmpty()){
      for(int i=0; i<=F.Tam;i++){
         F.pop(y);
         F1.push(y);
         F.push(y);
      } 
   }
   else if(!this->isEmpty() && F.isEmpty()){
      for(int i=0; i<=this->Tam;i++){
         this->pop(x);
         F1.push(x);
         this->push(x); 
      }
   }
   return F1;
}

template< typename T >
Fila<T> &Fila<T> :: operator=(Fila<T> F){
   T z;
   while(F.pop(z)){
      this->push(z);
   }
   return *this;
}

#endif