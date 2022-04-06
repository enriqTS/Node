// Exemplo 01 - Implementacao de Pilha Utilizando Vetor

#include <iostream>

using namespace std;

#define TAM 10

struct No{
  char Chave;
  int Valor;
};

struct Pilha{
  No Dados[TAM];
  int Topo;
};

void IniciaPilha(Pilha& P){
	P.Topo = -1;
}

bool PilhaVazia(Pilha P){
   if(P.Topo == -1)
     return true;
   return false;  
}

bool PilhaCheia(Pilha P){
   if(P.Topo == TAM - 1)
     return true;
   return false;  
}

bool Empilha(Pilha& P, No Novo){
  if (PilhaCheia(P))
     return false;
   P.Dados[++P.Topo] = Novo;
   return true;
}

bool Desempilha(Pilha& P, No& Novo){
   if (PilhaVazia(P))
     return false;
   Novo = P.Dados[P.Topo--];
   return true;
}

int main (){

   Pilha P;
   IniciaPilha(P);
   
   No Aux;


   Aux.Chave = 'a';
   Aux.Valor = 1;
   Empilha(P, Aux);
   
   Aux.Chave = 'b';
   Aux.Valor = 2;
   Empilha(P, Aux);

   while(Desempilha(P, Aux))
       cout << "Chave desempilhada: " << Aux.Chave << endl;
    
   if(PilhaVazia(P))
     cout << "Pilha vazia" << endl;
     
 return 0;
}
