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

NoPtr UniaoListas(NoPtr &L1, NoPtr &L2)
{
    NoPtr L3 = NULL;
    NoPtr Aux = L1;
    NoPtr Aux2 = L2;
    while (Aux != NULL)
    {
        if (!Membro(L3, Aux->Info))
        {
            InsereLista(L3, Aux->Info);
        }
        Aux = Aux->Lig;
    }
    while (Aux2 != NULL)
    {
        if (!Membro(L3, Aux2->Info))
        {
            InsereLista(L3, Aux2->Info);
        }
        Aux2 = Aux2->Lig;
    }
    return L3;
}

int main()
{

    NoPtr L1 = NULL;
    NoPtr L2 = NULL;
    NoPtr L3 = NULL;

    InsereLista(L1, 1);
    InsereLista(L1, 2);
    InsereLista(L1, 4);
    InsereLista(L1, 5);

    InsereLista(L2, 1);
    InsereLista(L2, 3);
    InsereLista(L2, 5);

    L3 = UniaoListas(L1, L2);
    ImprimeLista(L1);
    ImprimeLista(L2);
    ImprimeLista(L3);

    return 0;
}