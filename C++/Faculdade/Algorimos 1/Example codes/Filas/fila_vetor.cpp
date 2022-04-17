// Exemplo 03 - Implementacao de Fila Utilizando Vetor
   
#include <iostream>
using namespace std;
#define T 10

struct No{
  int Valor;
};

struct Fila{
   No Dados[T];
   int Tam;
   int Com;
   int Fim;
};

void IniciaFila(Fila& F){
   F.Fim = -1;
   F.Com = 0;
   F.Tam = 0;
}

bool FilaVazia(Fila F){
	if(F.Tam == 0)
	  return true;
	return false;
}

bool FilaCheia(Fila F){
	if(F.Tam == T)
	  return true;
	return false;
}

bool InsereFila(Fila& F, No Novo){
   if (FilaCheia(F))
      return false;
   F.Tam++;
   F.Fim = (F.Fim + 1) % T;
   F.Dados[F.Fim] = Novo;
   return true;
}

bool RetiraFila(Fila& F, No& Novo){
  if (FilaVazia(F))
     return false;
  F.Tam--;
  Novo = F.Dados[F.Com];
  F.Com = (F.Com + 1) % T;
  return true;
}

int main (){
   Fila F;
   IniciaFila(F);
   
   No Aux;
  
   Aux.Valor = 1;
   InsereFila(F, Aux);

   Aux.Valor = 2;
   InsereFila(F, Aux);

   while(RetiraFila(F, Aux))
       cout << "Valor que saiu da fila: " << Aux.Valor << endl;
  
   if(FilaVazia(F))
     cout << "Fila vazia" << endl;

   return 0;
}
