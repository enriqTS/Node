// Exemplo 02 - Implementacao de Pilha Utilizando Alocacao Dinamica de Memoria*

#include <iostream>

using namespace std;

struct No
{
    int Info;
    No *Lig;
};

typedef No *Pilha;

void IniciaPilha(Pilha &Topo)
{
    Topo = NULL;
}

Pilha TopoPilha(Pilha Topo)
{
    No *Aux = new No;
    Aux = Topo;
    return Aux;
}

bool PilhaVazia(Pilha &Topo)
{
    if (Topo == NULL)
        return true;
    return false;
}

void Empilha(Pilha &Topo, int Elemento)
{
    No *Aux = new No;
    Aux->Info = Elemento;
    Aux->Lig = Topo;
    Topo = Aux;
}

bool Desempilha(Pilha &Topo, int &Elemento)
{
    if (PilhaVazia(Topo))
        return false;
    Elemento = Topo->Info;
    No *Aux = Topo;
    Topo = Topo->Lig;
    delete Aux;
    return true;
}

bool findOne(Pilha P, int x)
{
    Pilha Aux = P;
    while (Aux != NULL)
    {
        if (x == Aux->Info)
        {
            return true;
        }
        Aux = Aux->Lig;
    }
    return false;
}

int SomaPilha(Pilha P)
{
    Pilha Aux = P;
    int soma = 0;
    while (Aux != NULL)
    {
        soma += Aux->Info;
        Aux = Aux->Lig;
    }
    return soma;
}

bool PilhasIguais(Pilha &P1, Pilha &P2)
{
    Pilha Aux1;
    Pilha Aux2;
    IniciaPilha(Aux1);
    IniciaPilha(Aux2);

    int el1, el2;
    bool equal = true;

    while (Desempilha(P1, el1))
    {
        Empilha(Aux1, el1);
    }
    while (Desempilha(P2, el2))
    {
        Empilha(Aux2, el2);
    }

    while (!PilhaVazia(Aux2) && !PilhaVazia(Aux1))
    {
        Desempilha(Aux1, el1);
        Desempilha(Aux2, el2);
        Empilha(P1, el1);
        Empilha(P2, el2);
        if (el1 != el2)
        {
            equal = false;
        }
    }
    if (!PilhaVazia(Aux2) || !PilhaVazia(Aux1))
    {
        equal = false;
        if (!PilhaVazia(Aux1))
        {
            while (Desempilha(Aux1, el1))
            {
                Empilha(P1, el1);
            }
        }
        if (!PilhaVazia(Aux2))
        {
            while (Desempilha(Aux2, el2))
            {
                Empilha(P2, el2);
            }
        }
    }

    return equal;
}

int main()
{

    Pilha P1, P2;
    IniciaPilha(P1);
    IniciaPilha(P2);

    int Elemento;

    Empilha(P1, 3);
    Empilha(P1, 1);
    Empilha(P1, 4);
    Empilha(P1, 4);

    Empilha(P2, 3);
    Empilha(P2, 1);
    Empilha(P2, 4);
    Empilha(P2, 4);

    if (PilhasIguais(P1, P2))
    {
        cout << "Igual" << endl;
    }
    else
    {
        cout << "Não Igual" << endl;
    }

    cout << "Pilha 1: ";
    while (Desempilha(P1, Elemento))
    {
        cout << Elemento << " ";
    }

    cout << "\nPilha 2: ";
    while (Desempilha(P2, Elemento))
    {
        cout << Elemento << " ";
    }

    delete P1;
    delete P2;

    return 0;
}
