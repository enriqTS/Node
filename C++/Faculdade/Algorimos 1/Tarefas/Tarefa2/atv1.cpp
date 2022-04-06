/*+--------------------------------------------------------+
  | Arvore Binaria de Busca - 2021                         |
  +--------------------------------------------------------+*/

#include <iostream>

using namespace std;

struct No
{            // DEFINICAO DO NO
   int Info; // INFORMACAO ARMAZENADA NO NO
   No *esq;  // PONTEIRO PARA A SUB-ARVORE ESQUERDA
   No *dir;  // PONTEIRO PARA A SUB-ARVORE DIREITA
};

typedef No *Arvore; // DEFINICAO DO TIPO ARVORE

// INSERCAO DE UM NO NA ARVORE - RECURSIVA
void insereAbbRec(Arvore &A, int Info)
{
   if (A == NULL)
   { // SE O PONTEIRO A E NULO, INSERIR UM NOVO NO
      A = new No;
      A->Info = Info;
      A->esq = A->dir = NULL;
   }
   else if (Info > A->Info)
      insereAbbRec(A->dir, Info); //INSERINDO NO RAMO DIREITO
   else
      insereAbbRec(A->esq, Info); //INSERINDO NO RAMO ESQUERDO
}

// CAMINHAMENTO EM PRE-ORDEM
void preordem(Arvore A)
{
   if (A != NULL)
   {
      cout << A->Info << "  "; // PROCESSA O NO
      preordem(A->esq);        // CAMINHA PARA ESQUERDA
      preordem(A->dir);        // CAMINHA PARA DIREITA
   }
}

// Função para remover nó
void removeNo(Arvore &A, int info)
{
   if (A != NULL)
   {
      if (A->Info == info && A->dir != NULL && A->esq != NULL && A->dir->esq != NULL)
      {
         A->Info = A->dir->esq->Info;
         A->dir->esq = NULL;
      }
      if (A->Info == info && (A->dir == NULL || A->esq == NULL))
      {
         if (A->dir == NULL && A->esq == NULL)
         {
            A = NULL;
         }
         if (A != NULL && A->dir != NULL)
         {
            A = A->dir;
         }
         if (A != NULL && A->esq != NULL)
         {
            A = A->esq;
         }
      }
      if (A != NULL)
      {
         removeNo(A->esq, info);
         removeNo(A->dir, info);
      }
   }
}

int main()
{

   Arvore t = NULL;

   insereAbbRec(t, 30);
   insereAbbRec(t, 20);
   insereAbbRec(t, 25);
   insereAbbRec(t, 15);
   insereAbbRec(t, 40);
   insereAbbRec(t, 35);
   insereAbbRec(t, 45);
   insereAbbRec(t, 47);

   cout << "pre-ordem: ";
   preordem(t);

   cout << endl;

   // Caso 1
   removeNo(t, 45);

   preordem(t);

   // Caso 1
   removeNo(t, 35);
   cout << endl;

   preordem(t);
   // Caso 1
   removeNo(t, 47);
   cout << endl;

   preordem(t);

   insereAbbRec(t, 35);

   // Caso 2
   removeNo(t, 30);
   cout << endl;

   preordem(t);

   cout << endl;

   return 0;
}
