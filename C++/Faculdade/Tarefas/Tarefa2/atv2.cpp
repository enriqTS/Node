#include <iostream>
#include <queue>

using namespace std;

struct No {     
     int Info; 
     No* esq;   
     No* dir;   
     };

typedef No* Arvore; 

void insereAbbRec (Arvore& A, int Info){
     if(A == NULL){ 
         A = new No;
         A->Info = Info;
         A->esq = A->dir = NULL;
      }
      else if(Info > A->Info)
              insereAbbRec(A->dir, Info); 
           else
              insereAbbRec(A->esq, Info); 
}

void constroiArvore(Arvore& A){
     int Info;
     cin >> Info;  
     if(Info == '.')  
        A = NULL;
     else{           
         A = new No;
         A->Info = Info;
         constroiArvore(A->esq);
         constroiArvore(A->dir);
      }
}

void PercursoLarg(Arvore A){
   if(A == NULL) return;
   queue<No*> F1;
   F1.push(A);
   while(!F1.empty()){
      No* Atual = F1.front();
      cout << "Atual: " << Atual->Info << endl;
      if(Atual->esq != NULL) 
         F1.push(Atual->esq);
      if(Atual->dir != NULL)
         F1.push(Atual->dir);
      F1.pop();   
   }
}

int main(){
    
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