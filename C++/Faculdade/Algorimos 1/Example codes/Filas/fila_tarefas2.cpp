// Implementacao de Fila Utilizando Alocacao Dinamica

#include <iostream>

using namespace std;

struct No{
   char Info;
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

void InsereFila(Fila& F, char Novo){
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

bool RetiraFila(Fila& F, char& Valor){
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

NoPtr Primeiro(Fila& F){
   NoPtr P = F.Com;
   return P;
}

int main (){

   char dado;
   Fila F;
   IniciaFila(F);
   
   // if(FilaVazia(F))
   //    cout << "Fila Vazia " << endl;
   // else cout << "Fila nao vazia " << endl;

   InsereFila (F, 'a');
   InsereFila (F, 'b');
   RetiraFila (F, dado);
   InsereFila (F, 'c');
   InsereFila (F, 'e');
   RetiraFila (F, dado);
   
   // if(FilaVazia(F))
   //    cout << "Fila Vazia " << endl;
   // else cout << "Fila nao vazia " << endl;

   while(RetiraFila(F, dado))
      cout << "Valor retirado da fila: "<< dado << endl;
 
   // if(FilaVazia(F))
   //    cout << "Fila Vazia " << endl;
   // else cout << "Fila nao vazia " << endl;
 
 return 0;
}
