// Lista Estatica Sequencial
// Sandro Izidoro - 2020

#include <iostream>
using namespace std;

#define TAM 10

struct No {
  char Chave;
  int Valor;
};

struct ListaSequencial {
  No Dados[TAM];
  int Fim;
};

void IniciaLista(ListaSequencial& L){
	L.Fim = -1;
}

bool InsereListaSeq (ListaSequencial &L, No Novo){
   if(L.Fim == TAM - 1)
      return false;
   else{
      int i = 0, p;
      while((i <= L.Fim)&&(L.Dados[i].Chave < Novo.Chave))
         i++;
      p = i;
      i = L.Fim;
      while (i > p-1) {
         L.Dados[i+1] = L.Dados[i];
         i--;
      }
      L.Dados[p] = Novo;
      L.Fim++;
      return true;
   }
}

bool RetiraListaSeq (ListaSequencial& L, No& N){
   int i = 0;
   while ((i <= L.Fim) && (L.Dados[i].Chave != N.Chave))
      i++;
   if (i > L.Fim)
      return false;
   N = L.Dados[i];
   while (i < L.Fim) {
      L.Dados[i] = L.Dados[i+1];
      i++;
   }
   L.Fim--;
   return true;
}

void ImprimeListaSeq (ListaSequencial L){
   int i = 0;
   while (i <= L.Fim){
      cout << L.Dados[i].Chave << " - " << L.Dados[i].Valor << endl;
      i++;
   }
}

int main () {

   ListaSequencial L;
   IniciaLista(L);
   No Aux;
   Aux.Chave = 'c'; Aux.Valor = 3;
   InsereListaSeq(L, Aux);
   Aux.Chave = 'a'; Aux.Valor = 1;
   InsereListaSeq(L, Aux);
   Aux.Chave = 'b'; Aux.Valor = 2;
   InsereListaSeq(L, Aux);
   cout << "\nImpressao da Lista"<< endl;
   ImprimeListaSeq(L);
   Aux.Chave = 'b'; Aux.Valor = 2;
   RetiraListaSeq(L, Aux);
   cout << "\nImpressao da Lista"<< endl;
   ImprimeListaSeq(L);
return 0;
}
