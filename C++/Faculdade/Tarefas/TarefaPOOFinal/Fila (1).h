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
      return Fim == -1 || Com == size - 1;
   }
   bool isFull()
   {
      return Fim == size - 1;
   }
   int Fsize()
   {
      return size;
   }
   Fila<T> operator+(Fila<T> F2);
   // Fila<T> operator+(Fila<T> F2);
   // inline Fila<T> operator=(Fila<T> Soma);

private:
   int size;
   int Com;
   int Fim;
   T *filaPtr;
};

template <typename T>
Fila<T>::Fila(int s) : size(s > 0 ? s : 10),
                       Com(-1),
                       Fim(-1),
                       filaPtr(new T[size])
{
}

template <typename T>
bool Fila<T>::push(const T &pushValue)
{
   if (!isFull())
   {
      filaPtr[++Fim] = pushValue;
      return true;
   }

   return false;
}

template <typename T>
bool Fila<T>::pop(T &popValue)
{
   if (!isEmpty())
   {
      popValue = filaPtr[++Com];
      return true;
   }
   return false;
}

// template <typename T>
// Fila<T> Fila<T>::operator+(Fila<T> F2)
// {
//    T x, y;
//    Fila<T> Soma;
// while (this->pop(x) || F2.pop(y))
// {
//    if ((!this->isEmpty() && !F2.isEmpty()) || (this->isEmpty() && F2.isEmpty()))
//    {
//       Soma.push(x + y);
//    }
//    if (!this->isEmpty() && F2.isEmpty())
//    {
//       Soma.push(x);
//    }
//    if (this->isEmpty() && !F2.isEmpty())
//    {
//       Soma.push(y);
//    }
// }

//    return Soma;
// }

// template <typename T>
// Fila<T> Fila<T>::operator=(Fila<T> Soma)
// {
//    T value;
//    while (Soma.pop(value))
//    {
//       this->push(value);
//    }
//    return *this;
// }

template <typename T>
Fila<T> Fila<T>::operator+(Fila<T> F2)
{
   // T x, y;
   Fila<T> Soma(5);
   // while (this->pop(x) || F2.pop(y))
   // {
   //    if ((!this->isEmpty() && !F2.isEmpty()) || (this->isEmpty() && F2.isEmpty()))
   //    {
   //       Soma.push(x + y);
   //    }
   //    if (!this->isEmpty() && F2.isEmpty())
   //    {
   //       Soma.push(x);
   //    }
   //    if (this->isEmpty() && !F2.isEmpty())
   //    {
   //       Soma.push(y);
   //    }
   // }
   Soma.push(2);
   Soma.push(2);
   Soma.push(2);
   Soma.push(2);
   Soma.push(2);

   return Soma;
}

#endif