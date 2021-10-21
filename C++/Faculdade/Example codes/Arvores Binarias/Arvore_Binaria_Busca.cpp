/*+--------------------------------------------------------+
  | Arvore Binaria de Busca - 2021                         |
  +--------------------------------------------------------+*/

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

int main () {

   Arvore te = NULL;

   cout << "Monte uma árvore: Digite letras (nós) e pontos (null) " << endl;

   constroiArvore(te);

   mostra (te, 0);

   cout << "\nMostrando arvore com pontos - pre-ordem\n" << endl;
   preordem(te);


   Arvore t = NULL;

   insereAbbRec(t, 'b');
   insereAbbRec(t, 'a');
   insereAbbRec(t, 'd');
   insereAbbRec(t, 'c');
   insereAbbRec(t, 'f');

   cout << "\n\npre-ordem: " ;   preordem(t); cout << endl;

   cout << "\n\nMostra Arvore\n";

   mostra (t, 0);

   return 0;
}
