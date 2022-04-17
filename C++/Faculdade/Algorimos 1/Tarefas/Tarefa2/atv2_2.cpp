#include <iostream>
#include <queue>

using namespace std;

struct No
{
   int Info;
   No *esq;
   No *dir;
};

typedef No *Arvore;

struct NoF
{
   Arvore Info;
   NoF *Lig;
};

typedef NoF *NoPtr;

struct Fila
{
   NoPtr Com;
   int Nro;
   NoPtr Fim;
};
void IniciaFila(Fila &F)
{
   F.Nro = 0;
   F.Com = NULL;
   F.Fim = NULL;
}

bool FilaVazia(Fila F)
{
   return !F.Nro;
}

void InsereFila(Fila &F, Arvore Novo)
{
   NoPtr P = new NoF;
   P->Info = Novo;
   P->Lig = NULL;
   if (F.Nro == 0)
      F.Com = F.Fim = P;
   else
   {
      F.Fim->Lig = P;
      F.Fim = P;
   }
   F.Nro++;
}

bool RetiraFila(Fila &F, Arvore &Valor)
{
   if (FilaVazia(F))
      return false;
   else
   {
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

void insereAbbRec(Arvore &A, int Info)
{
   if (A == NULL)
   {
      A = new No;
      A->Info = Info;
      A->esq = A->dir = NULL;
   }
   else if (Info > A->Info)
      insereAbbRec(A->dir, Info);
   else
      insereAbbRec(A->esq, Info);
}

void constroiArvore(Arvore &A)
{
   int Info;
   cin >> Info;
   if (Info == '.')
      A = NULL;
   else
   {
      A = new No;
      A->Info = Info;
      constroiArvore(A->esq);
      constroiArvore(A->dir);
   }
}

void PercursoLarg(Arvore A)
{
   if (A == NULL)
      return;

   Fila F;
   IniciaFila(F);

   InsereFila(F, A);

   Arvore Aux;
   while (RetiraFila(F, Aux))
   {
      cout << Aux->Info << " ";
      if (Aux->esq != NULL)
      {
         InsereFila(F, Aux->esq);
      }
      if (Aux->dir != NULL)
      {
         InsereFila(F, Aux->dir);
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

   PercursoLarg(t);
}