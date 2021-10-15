// Implementacao de Fila Utilizando Alocacao Dinamica

#include <iostream>

using namespace std;

struct No
{
    int Info;
    No *Lig;
};

typedef No *NoPtr;

struct Fila
{
    NoPtr Com;
    int Nro;
    NoPtr Fim;
};

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

void InsereFila(Fila &F, int Novo)
{
    NoPtr P = new No;
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

bool RetiraFila(Fila &F, int &Valor)
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

NoPtr Primeiro(Fila &F)
{
    NoPtr P = F.Com;
    return P;
}

Fila SomaFilas(Fila F1, Fila F2)
{
    NoPtr Pf1 = new No;
    NoPtr Pf2 = new No;

    Fila Soma;
    IniciaFila(Soma);

    Pf1->Info = F1.Com->Info;
    Pf1->Lig = F1.Com;

    Pf2->Info = F2.Com->Info;
    Pf2->Lig = F2.Com;

    Pf1 = Pf1->Lig;
    Pf2 = Pf2->Lig;

    while (Pf1 != NULL || Pf2 != NULL)
    {

        if (Pf1 != NULL && Pf2 != NULL)
        {
            int soma = Pf1->Info + Pf2->Info;
            InsereFila(Soma, soma);
        }
        else if (!(Pf1 != NULL) && Pf2 != NULL)
        {
            InsereFila(Soma, Pf2->Info);
        }
        else if (Pf1 != NULL && !(Pf2 != NULL))
        {
            InsereFila(Soma, Pf1->Info);
        }

        if (Pf1 != NULL)
        {
            Pf1 = Pf1->Lig;
        }
        if (Pf2 != NULL)
        {
            Pf2 = Pf2->Lig;
        }
    }
    return Soma;
}

bool findOne(Fila F, int value)
{
    if (!FilaVazia(F))
    {
        NoPtr P = new No;
        P->Info = F.Com->Info;
        P->Lig = F.Com;
        while (P != NULL)
        {
            if (P->Info == value)
            {
                return true;
            }
            P = P->Lig;
        }
        return false;
    }
    return false;
}

int main()
{

    Fila F1, F2, Soma;

    IniciaFila(F1);
    IniciaFila(F2);
    IniciaFila(Soma);

    InsereFila(F1, 2);
    InsereFila(F1, 3);
    InsereFila(F1, 5);
    InsereFila(F2, -1);
    InsereFila(F2, -5);
    InsereFila(F2, 10);
    InsereFila(F2, 8);

    if (findOne(F1, 'c'))
    {
        cout << "Achou" << endl;
    }

    if (!FilaVazia(F1) && !FilaVazia(F2))
    {
        Soma = SomaFilas(F1, F2);
    }

    int valor;
    while (RetiraFila(F1, valor))
        cout << valor << " ";

    cout << endl
         << " + " << endl;

    while (RetiraFila(F2, valor))
        cout << valor << " ";

    cout << endl
         << " = " << endl;

    if (!FilaVazia(Soma))
    {
        while (RetiraFila(Soma, valor))
        {
            cout << valor << " ";
        }
    }

    return 0;
}
