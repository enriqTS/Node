// Lista Ponteiros
// Sandro Izidoro - 2020

#include <iostream>

using namespace std;

struct No {
   char Info;
   No * Lig;
};

typedef struct No *NoPtr;


void InsereLista (NoPtr& L, char Novo) {
  if (L == NULL) {  // INSERCAO DO PRIMEIRO NO
      L = new No;
      L->Info = Novo;
      L->Lig = NULL;
  } else {                // AJUSTA PONTEIROS ANT E AUX
      NoPtr Ant = NULL;
      NoPtr Aux = L;
      while((Aux != NULL)&&(Aux->Info < Novo)) {//ENCONTRA POSICAO
      	    Ant = Aux;
            Aux = Aux->Lig;
      }
      Aux = new No;
      Aux->Info = Novo;     // INSERE O NO E AJUSTA PONTEIROS
      if (Ant == NULL) {
            Aux->Lig = L;
            L = Aux;
      } else {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
      }
  }
}

bool RetiraLista (NoPtr& L, char Novo) {
  NoPtr Ant = NULL;
  NoPtr Aux = L;
  while ((Aux != NULL) && (Aux->Info != Novo)) { // TENTA ENCONTRAR ELEMENTO
          Ant = Aux;
          Aux = Aux->Lig;
  }
  if (Aux == NULL)
         return false;  // RETORNA FALSO SE NAO ENCONTRA ELEMENTO
  if (Aux == L)        // SE ELEMENTO E O PRIMEIRO, REDIRECIONA O PONTEIRO
         L = L->Lig;
  else
         Ant->Lig = Aux->Lig; // REDIRECIONA O PONTEIRO
  delete Aux;  // APAGA O ELEMENTO
  return true;
}

void ImprimeLista (NoPtr L) {
  NoPtr Aux = L;
  cout << "L -> ";
  while ((Aux != NULL)) {
        Aux = Aux->Lig;
        cout << Ant->Info << " -> ";
  }
  if (Aux == NULL)
      cout << "NULL" << endl;
}

int main () {

  NoPtr L1 = NULL;
  NoPtr L2 = NULL;

  InsereLista(L1, 'c');
  InsereLista(L1, 'd');
  InsereLista(L1, 'a');
  InsereLista(L1, 'b');
  ImprimeLista(L1);

  InsereLista(L2, 'h');
  InsereLista(L2, 'e');
  InsereLista(L2, 'k');
  InsereLista(L2, 'i');
  ImprimeLista(L2);

  RetiraLista(L1,'c');
  RetiraLista(L2,'k');
  ImprimeLista(L1);
  ImprimeLista(L2);

return 0;
}
