// Exemplo 01 - Implementacao de Pilha Utilizando Vetor

#include <iostream>

using namespace std;

#define TAM 10

struct No{
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

float media(Pilha& P){
   Pilha PAux;
   IniciaPilha(PAux);
   No Aux;
   int n = 0; // numero de elementos da pilha
   float Soma = 0;
   
   while(Desempilha(P, Aux)){
      n++;
      Soma += Aux.Valor;
      Empilha(PAux, Aux);
   }
   while(Desempilha(PAux, Aux)){
      Empilha(P, Aux);
   }

   return Soma/n;
}

int main (){

   Pilha P;
   IniciaPilha(P);
   
   No Aux;

   Aux.Valor = 9;
   Empilha(P, Aux);
      
   Aux.Valor = 1;
   Empilha(P, Aux);

   Aux.Valor = 3;
   Empilha(P, Aux);

   Aux.Valor = 5;
   Empilha(P, Aux);

   cout << "Media dos valores de P: " << media(P) << endl;

   while(Desempilha(P, Aux))
       cout << "Chave desempilhada: " << Aux.Valor << endl;
    
   if(PilhaVazia(P))
     cout << "Pilha vazia" << endl;
     
 return 0;
}