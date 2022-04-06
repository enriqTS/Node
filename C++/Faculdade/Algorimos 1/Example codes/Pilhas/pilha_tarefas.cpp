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

void Empilha(Pilha& Topo, int Elemento){
   No *Aux = new No;
   Aux->Info = Elemento;
   Aux->Lig = Topo;
   Topo = Aux;
}

bool Desempilha(Pilha& Topo, int& Elemento){
   if (PilhaVazia(Topo))
       return false;
   Elemento = Topo->Info;
   No *Aux = Topo;
   Topo = Topo->Lig;
   delete Aux;
   return true;
}

// Pilha InvertePilha(Pilha& Topo){
//    Pilha Aux, Aux2;
//    IniciaPilha(Aux);
//    IniciaPilha(Aux2);
//    char Elemento;
    
//    while(Elemento != ' '){
//       Desempilha(Topo, Elemento);
//       Empilha(Aux, Elemento);
//       Desempilha(Aux, Elemento);
//       Empilha(Aux2, Elemento);
//    } 
//    Topo = Aux2;
//    return Topo;   
// }

float MediaPilha(Pilha& Topo){
   Pilha Aux;
   IniciaPilha(Aux);
   int Elemento;

   while(!PilhaVazia(Topo)){
      Desempilha(Topo, Elemento);
      Empilha(Aux, Elemento);
   }
}

int main (){
	
   Pilha Topo;
   IniciaPilha(Topo);
   
   // char Elemento;
   // string s = "Hoj esta muito quente";
   // for(int i = 0; i < s.size(); i++){
   //     Empilha(Topo, s[i]);
   // }

//   InvertePilha(Topo);
  
   while(Desempilha(Topo,Elemento))
      cout << "Desempilhando elemento -> " << Elemento << endl;
   
   if(PilhaVazia(Topo))
     cout << "Pilha Vazia" << endl;
     
   delete Topo;

 return 0;
}