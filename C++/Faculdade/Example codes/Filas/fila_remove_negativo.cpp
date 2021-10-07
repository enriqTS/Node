// Implementacao de Fila Utilizando Alocacao Dinamica

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

void RemoveNegativo(Fila& F){
   int valor;
   int tam = F.Nro;
   for(int i = 1; i <= tam; i++){
      RetiraFila(F, valor);
      if(valor >= 0){
         InsereFila(F, valor);
      }
   }   
} 
      
NoPtr Primeiro(Fila& F){
   NoPtr P = F.Com;
   return P;
}

int main (){

   Fila F;
   IniciaFila(F);
   
   if(FilaVazia(F))
      cout << "Fila Vazia " << endl;
   else cout << "Fila nao vazia " << endl;

   InsereFila (F, 5);
   InsereFila (F, -3);
   InsereFila (F, 9);
   InsereFila (F, -5);
   InsereFila (F, 3);
   InsereFila (F, -7);

   if(FilaVazia(F))
      cout << "Fila Vazia " << endl;
   else cout << "Fila nao vazia " << endl;

   RemoveNegativo(F);

   int valor;
   while(RetiraFila(F,valor))
      cout << "Valor retirado da fila: "<< valor << endl;
 
   if(FilaVazia(F))
      cout << "Fila Vazia " << endl;
   else cout << "Fila nao vazia " << endl;
 
 return 0;
}
