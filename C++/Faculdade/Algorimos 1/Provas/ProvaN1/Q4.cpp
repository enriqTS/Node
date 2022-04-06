#include <iostream>

using namespace std;

struct No
{
    int Info;
    No *Lig;
};

typedef struct No *NoPtr;

void InsereLista(NoPtr &L, int Novo)
{
    if (L == NULL)
    { // INSERCAO DO PRIMEIRO NO
        L = new No;
        L->Info = Novo;
        L->Lig = NULL;
    }
    else
    { // AJUSTA PONTEIROS ANT E AUX
        NoPtr Ant = NULL;
        NoPtr Aux = L;
        while ((Aux != NULL) && (Aux->Info < Novo))
        { //ENCONTRA POSICAO
            Ant = Aux;
            Aux = Aux->Lig;
        }
        Aux = new No;
        Aux->Info = Novo; // INSERE O NO E AJUSTA PONTEIROS
        if (Ant == NULL)
        {
            Aux->Lig = L;
            L = Aux;
        }
        else
        {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
        }
    }
}

bool RetiraLista(NoPtr &L, int Novo)
{
    NoPtr Ant = NULL;
    NoPtr Aux = L;
    while ((Aux != NULL) && (Aux->Info != Novo))
    { // TENTA ENCONTRAR ELEMENTO
        Ant = Aux;
        Aux = Aux->Lig;
    }
    if (Aux == NULL)
        return false; // RETORNA FALSO SE NAO ENCONTRA ELEMENTO
    if (Aux == L)     // SE ELEMENTO E O PRIMEIRO, REDIRECIONA O PONTEIRO
        L = L->Lig;
    else
        Ant->Lig = Aux->Lig; // REDIRECIONA O PONTEIRO
    delete Aux;              // APAGA O ELEMENTO
    return true;
}

void ImprimeLista(NoPtr L)
{
    NoPtr Aux = L;
    cout << "L -> ";
    while ((Aux != NULL))
    {
        cout << Aux->Info << " -> ";
        Aux = Aux->Lig;
    }
    if (Aux == NULL)
        cout << "NULL" << endl;
}

bool Membro(NoPtr L, int dado)
{
    NoPtr Aux = L;
    while (Aux != NULL)
    {
        if (dado == Aux->Info)
            return true;
        Aux = Aux->Lig;
    }
    return false;
}

void RemoveRepetidos(NoPtr &L)
{
    NoPtr Aux = L;
    NoPtr Aux2 = NULL;
    while (Aux != NULL)
    {
        if (!Membro(Aux2, Aux->Info))
        {
            InsereLista(Aux2, Aux->Info);
        }
        Aux = Aux->Lig;
    }
    L = Aux2;
}

int main()
{

    NoPtr L1 = NULL;

    InsereLista(L1, 1);
    InsereLista(L1, 1);
    InsereLista(L1, 5);
    InsereLista(L1, 5);
    InsereLista(L1, 3);
    InsereLista(L1, 3);
    InsereLista(L1, 3);
    InsereLista(L1, 9);
    InsereLista(L1, 5);
    InsereLista(L1, 5);
    InsereLista(L1, 9);
    InsereLista(L1, 8);
    ImprimeLista(L1);

    RemoveRepetidos(L1);
    ImprimeLista(L1);

    return 0;
}