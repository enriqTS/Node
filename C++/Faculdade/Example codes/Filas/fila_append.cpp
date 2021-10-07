#include <iostream>

using namespace std;

struct No{
   int Info;
   No *Lig;
};

typedef No *NoPtr;

struct Fila{
   NoPtr Com;
   int Nro;
   NoPtr Fim;
};

void IniciaFila(Fila& F){
   F.Nro = 0;
   F.Com = NULL;
   F.Fim = NULL;
}

bool FilaVazia(Fila F){
   return !F.Nro;
}

void InsereFila(Fila& F, int Novo){
   NoPtr P = new No;
   P->Info = Novo;
   P->Lig = NULL;
   if (F.Nro == 0)
        F.Com = F.Fim = P;
   else {
         F.Fim->Lig = P;
         F.Fim = P;
   }
   F.Nro++;
}

bool RetiraFila(Fila& F, int& Valor){
   if (FilaVazia(F))
       return false;
   else {
       NoPtr P = F.Com;
       Valor = P->Info;
       F.Com = P->Lig; 
       F.Nro--;
       if (F.Nro == 0)
           F.Fim = NULL;
      delete P;
   }
   return true;
}

Fila Concatena(Fila& F1, Fila& F2){
    Fila F3;
    IniciaFila(F3);
    int valor;

    for(int i=1; i <= F1.Nro; i++){
        RetiraFila(F1,valor);
        InsereFila(F3,valor);
        InsereFila(F1,valor);
    }

    for(int i=1; i <= F2.Nro; i++){
        RetiraFila(F2,valor);
        InsereFila(F3,valor);
        InsereFila(F2,valor);
    }

    return F3;
}

NoPtr Primeiro(Fila& F){
   NoPtr P = F.Com;
   return P;
}

int main (){

   Fila F1, F2, F3;
   IniciaFila(F1);
   IniciaFila(F2);
   IniciaFila(F3);
   
//    if(FilaVazia(F))
//       cout << "Fila Vazia " << endl;
//    else cout << "Fila nao vazia " << endl;

   InsereFila (F1, 5);
   InsereFila (F1, -3);
   InsereFila (F1, 9);

   InsereFila (F2, -5);
   InsereFila (F2, 3);
   InsereFila (F2, -7);

   F3 = Concatena(F1, F2);

//    if(FilaVazia(F))
//       cout << "Fila Vazia " << endl;
//    else cout << "Fila nao vazia " << endl;

   int valor;
    while(RetiraFila(F3,valor))
       cout << "Valor retirado da fila: "<< valor << endl;
 
    if(FilaVazia(F3))
       cout << "Fila Vazia " << endl;
    else cout << "Fila nao vazia " << endl;
 
 return 0;
}
