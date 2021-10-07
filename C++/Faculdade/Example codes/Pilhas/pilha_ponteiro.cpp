// Exemplo 02 - Implementacao de Pilha Utilizando Alocacao Dinamica de Memoria*

#include <iostream>

using namespace std;

struct No {
   char Info;
   No *Lig;
};

typedef No *Pilha;

void IniciaPilha(Pilha& Topo){
	Topo = NULL;
}

Pilha TopoPilha(Pilha Topo){
   No *Aux = new No;
   Aux = Topo;
   return Aux;
}

bool PilhaVazia(Pilha& Topo){
   if (Topo == NULL)
       return true;
   return false;
}

void Empilha(Pilha& Topo, char Elemento){
   No *Aux = new No;
   Aux->Info = Elemento;
   Aux->Lig = Topo;
   Topo = Aux;
}

bool Desempilha(Pilha& Topo, char& Elemento){
   if (PilhaVazia(Topo))
       return false;
   Elemento = Topo->Info;
   No *Aux = Topo;
   Topo = Topo->Lig;
   delete Aux;
   return true;
}

int main (){
	
   Pilha Topo;
   IniciaPilha(Topo);
   
   char Elemento;
   
   Empilha (Topo, 'a');
   Empilha (Topo, 'b');
   Empilha (Topo, 'c');
  
   while(Desempilha(Topo,Elemento))
      cout << "Desempilhando elemento -> " << Elemento << endl;
   
   if(PilhaVazia(Topo))
     cout << "Pilha Vazia" << endl;
     
   delete Topo;

 return 0;
}
