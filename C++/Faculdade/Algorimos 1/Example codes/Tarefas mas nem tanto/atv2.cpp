#include <iostream>
#include <string.h>
using namespace std;

const int TAM = 10;

struct No
{
    int Valor;
    No *Lig;
};

typedef No *Pilha;

void IniciaPilha(Pilha &Topo)
{
    Topo = NULL;
}

bool PilhaVazia(Pilha& Topo){
   if (Topo == NULL)
       return true;
   return false;
}

void Empilha(Pilha &Topo, int Valor)
{
    No *Aux;
    Aux = new No;
    Aux->Valor = Valor;
    Aux->Lig = Topo;
    Topo = Aux;
}

bool Desempilha(Pilha &Topo, int &Valor)
{
    if (PilhaVazia(Topo))
    {
        return false;
    }
    Valor = Topo->Valor;
    Topo = Topo->Lig;
    return true;
}

void toString(Pilha Topo)
{
    int Valor;
    while (Desempilha(Topo, Valor))
    {
        cout << Valor << "\t";
    }
    cout << endl;
}

int MenorElementPilha(Pilha Topo){
    int menor = Topo->Valor, Valor;
    while(Desempilha(Topo,Valor)){
        if(menor > Valor){
            menor = Valor;
        }
    }
    return menor;
}

int MenorElementoPilha(Pilha& Topo, int &Valor)
{
    Pilha Aux;
    IniciaPilha(Aux);
    int menor = Valor;
    
    while(Desempilha(Topo, Valor)){
        Empilha(Aux, Valor);
        if(Valor < menor){
            menor = Valor;
        }
    }
    while(Desempilha(Aux, Valor)){
        Empilha(Topo, Valor);
    }
    return menor;
}

int main()
{
    Pilha Topo;
    IniciaPilha(Topo);

    int Valor;

    Empilha(Topo, 1);
    Empilha(Topo, 1);
    Empilha(Topo, 6);
    Empilha(Topo, -8);
    Empilha(Topo, 5);

    toString(Topo);

    cout << "Menor valor: " << MenorElementoPilha(Topo, Valor) << endl;

    toString(Topo);

    cout << "Menor valor: " << MenorElementPilha(Topo) << endl;

    toString(Topo);

    delete Topo;
    return 0;
}
