// Implementacao de Fila Utilizando Alocacao Dinamica

#include <iostream>

using namespace std;

struct NoF
{
    char Info;
    NoF *Lig;
};

typedef NoF *NoPtr;

struct Fila
{
    NoPtr Com;
    int Nro;
    NoPtr Fim;
};

struct NoP
{
    char Info;
    NoP *Lig;
};

typedef NoP *Pilha;

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

void IniciaPilha(Pilha &Topo)
{
    Topo = NULL;
}

bool PilhaVazia(Pilha &Topo)
{
    if (Topo == NULL)
        return true;
    return false;
}

void InsereFila(Fila &F, char Novo)
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

bool RetiraFila(Fila &F, char &Valor)
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
void Empilha(Pilha &Topo, char Elemento)
{
    NoP *Aux = new NoP;
    Aux->Info = Elemento;
    Aux->Lig = Topo;
    Topo = Aux;
}

bool Desempilha(Pilha &Topo, char &Elemento)
{
    if (PilhaVazia(Topo))
        return false;
    Elemento = Topo->Info;
    NoP *Aux = Topo;
    Topo = Topo->Lig;
    delete Aux;
    return true;
}

void InverteFila(Fila &F)
{
    if (!FilaVazia(F))
    {
        Pilha Aux;
        IniciaPilha(Aux);

        char el;

        while (RetiraFila(F, el))
        {
            Empilha(Aux, el);
        }

        while (Desempilha(Aux, el))
        {
            InsereFila(F, el);
        }
    }
}

int main()
{

    Fila F;
    IniciaFila(F);

    char valor;

    InsereFila(F, 'a');
    InsereFila(F, 'b');
    InsereFila(F, 'c');
    InsereFila(F, 'd');
    InsereFila(F, 'e');

    InverteFila(F);

    while (RetiraFila(F, valor))
        cout << "Valor retirado da fila: " << valor << endl;

    if (FilaVazia(F))
        cout << "Fila Vazia " << endl;
    else
        cout << "Fila nao vazia " << endl;

    return 0;
}
