#ifndef FILA_H
#define FILA_H

template <typename T>
class Fila
{
public:
   Fila(int = 10);
   ~Fila()
   {
      delete[] filaPtr;
   }
   bool push(const T &);
   bool pop(T &);
   bool isEmpty()
   {
      return Tam == 0;
   }
   bool isFull()
   {
      return Tam == size;
   }
   int Fsize()
   {
      return Tam;
   }
   Fila<T> operator+(Fila<T> &F);
   inline Fila<T> &operator=(Fila<T>);

private:
   int size;
   int Tam;
   int Com;
   int Fim;
   T *filaPtr;
};

template <typename T>
Fila<T>::Fila(int s) : size(s > 0 ? s : 10),
                       Com(0),
                       Fim(-1),
                       Tam(0),
                       filaPtr(new T[size])
{
}

template <typename T>
bool Fila<T>::push(const T &pushValue)
{
   if (isFull())
      return false;
   Tam++;
   Fim = (Fim + 1) % size;
   filaPtr[Fim] = pushValue;
   return true;
}

template <typename T>
bool Fila<T>::pop(T &popValue)
{
   if (isEmpty())
      return false;
   Tam--;
   popValue = filaPtr[Com];
   Com = (Com + 1) % size;
   return true;
}

template <typename T>
Fila<T> Fila<T>::operator+(Fila<T> &F)
{
   T sum, x, y;
   Fila<T> F1;
   Fila<T> auxthis(this->size);
   Fila<T> auxF(F.size);

   while (this->pop(x) && F.pop(y))
   {
      sum = x + y;
      F1.push(sum);
      auxthis.push(x);
      auxF.push(y);
   }

   if (!this->isEmpty())
   {
      auxthis.push(x);
      F1.push(x);
      while (this->pop(x))
      {
         auxthis.push(x);
         F1.push(x);
      }
   }
   if (!F.isEmpty())
   {
      while (F.pop(y))
      {
         auxF.push(y);
         F1.push(y);
      }
   }

   while (auxthis.pop(x))
   {
      this->push(x);
   }
   while (auxF.pop(y))
   {
      F.push(y);
   }
   return F1;
}

template <typename T>
Fila<T> &Fila<T>::operator=(Fila<T> F)
{
   T z;
   while (F.pop(z))
   {
      this->push(z);
   }
   return *this;
}

#endif