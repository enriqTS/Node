#include <iostream>

using namespace std;

struct No {     // DEFINICAO DO NO
     char Info; // INFORMACAO ARMAZENADA NO NO
     No* esq;   // PONTEIRO PARA A SUB-ARVORE ESQUERDA
     No* dir;   // PONTEIRO PARA A SUB-ARVORE DIREITA
};

typedef No* Arvore; // DEFINICAO DO TIPO ARVORE


// INSERCAO DE UM NO NA ARVORE - RECURSIVA
void insereAbbRec (Arvore& A, char Info){
     if(A == NULL){ // SE O PONTEIRO A E NULO, INSERIR UM NOVO NO
         A = new No;
         A->Info = Info;
         A->esq = A->dir = NULL;
      }
      else if(Info > A->Info)
              insereAbbRec(A->dir, Info); //INSERINDO NO RAMO DIREITO
           else
              insereAbbRec(A->esq, Info); //INSERINDO NO RAMO ESQUERDO
}

// CONSTRUCAO DE UMA ARVORE BINARIA
void constroiArvore(Arvore& A){
     char Info;
     cin >> Info;  // LE A INFORMACAO DIGITADA
     if(Info == '.')  // SE FOR UM PONTO, INSERE NULO PARA O PONTEIRO
        A = NULL;
     else{           // CASO CONTRARIO, ALOCA O NOVO NO E CHAMA RECURSIVO PARA ESQ E DIR
         A = new No;
         A->Info = Info;
         constroiArvore(A->esq);
         constroiArvore(A->dir);
      }
}

// CAMINHAMENTO EM PRE-ORDEM
void preordem (Arvore A) {
      if(A!=NULL) {
		cout << A->Info; // PROCESSA O NO
        preordem (A->esq);   // CAMINHA PARA ESQUERDA
        preordem (A->dir);   // CAMINHA PARA DIREITA
      }
      else cout << "." ;
   }

// APRESENTA A ESTRUTURA DA ARVORE
void mostra (Arvore& a, int n) {
  if (a) {
     int i;
     mostra (a->dir, n+1);
     for (i = 0; i < n; i++) cout << "    ";
     cout << a->Info << endl;
     mostra (a->esq, n+1);
  }
}

int ContaNos(Arvore A){
   if(A!=NULL)
      return 1 + ContaNos(A->esq) + ContaNos(A->dir);
   return 0;   
}

int SomaNos(Arvore A){
   if(A!=NULL)
      return A->Info + SomaNos(A->esq) + SomaNos(A->dir);
   return 0;   
}

int Maior(Arvore A){
   if(A->dir)
      return Maior(A->dir);
   else  
      return A->Info;   
}

bool Busca(Arvore A, int Info){
   if(A){
      if(A->Info == Info)
         return true;
      else
         if(A->Info < Info)
            return Busca(A->dir, Info);
         else  
            return Busca(A->esq, Info);
      return false;      
   }
}

struct No2{
   int Info;
   No2 *Lig;
};

typedef No2 *NoPtr2;

struct Fila{
   NoPtr2 Com;
   int Nro;
   NoPtr2 Fim;
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
   NoPtr2 P = new No2;
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
       NoPtr2 P = F.Com;
       Valor = P->Info;
       F.Com = P->Lig; 
       F.Nro--;
       if (F.Nro == 0)
           F.Fim = NULL;
      delete P;
   }
   return true;
}

int main(){
    
}