#include <iostream>
using namespace std;

struct No
{
    int valor;
    No *Lig;
};

typedef No *noPtr;

struct Fila
{
    noPtr Com;
    int Nro;
    noPtr Fim;
};

void IniciaFila(Fila &F)
{
    F.Nro = 0;
    F.Com = NULL;
    F.Fim = NULL;
}

bool FilaVazia(Fila F)
{
    if (F.Nro == 0)
    {
        return true;
    }
    return false;
}

void InsereFila(Fila &F, int Novo)
{
    noPtr P = new No;
    P->valor = Novo;
    P->Lig = NULL;
    if (F.Nro == 0)
    {
        F.Com = F.Fim = P;
    }
    else
    {
        F.Fim->Lig = P;
        F.Fim = P;
    }
    F.Nro++;
}

bool RetiraFila(Fila &F, int &valor)
{
    if (FilaVazia(F))
    {
        return false;
    }
    else
    {
        noPtr P = F.Com;
        valor = P->valor;
        F.Com = P->Lig;
        F.Nro--;
        if (F.Nro == 0)
        {
            F.Fim = NULL;
        }
        delete P;
    }
    return true;
}

Fila SomaFilas(Fila F1, Fila F2)
{
    Fila Soma;
    IniciaFila(Soma);
    int valor1 = 0, valor2 = 0;

    while (!(FilaVazia(F1) && FilaVazia(F2)))
    {
        bool f1 = RetiraFila(F1, valor1);
        bool f2 = RetiraFila(F2, valor2);

        if (!f1 && f2)
        {
            InsereFila(Soma, valor2);
        }
        if (!f2 && f1)
        {
            InsereFila(Soma, valor1);
        }
        if (f2 && f1)
        {
            int valor3 = valor1 + valor2;
            InsereFila(Soma, valor3);
        }
    }
    return Soma;
}

int main()
{
    Fila F1;
    IniciaFila(F1);

    InsereFila(F1, 4);
    InsereFila(F1, 1);
    InsereFila(F1, 4);
    InsereFila(F1, 1);
    InsereFila(F1, 1);
    InsereFila(F1, 1);

    Fila F2;
    IniciaFila(F2);

    InsereFila(F2, 5);
    InsereFila(F2, 4);
    InsereFila(F2, 1);

    Fila F3 = SomaFilas(F1, F2);

    int valor3;
    while (RetiraFila(F3, valor3))
    {
        cout << "Soma: " << valor3 << endl;
    }

    return 0;
}