#include "Matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int l, int c)
{
    this->linhas = l;
    this->colunas = c;

    this->matriz = new int[l * c];
}

Matriz::~Matriz()
{
    delete[] this->matriz;
}

void Matriz::insere(int el)
{
    for (int i = 0; i < (linhas * colunas); i++)
    {
        if (matriz[i] == NULL)
        {
            matriz[i] = el;
            return;
        }
    }
}

void Matriz::mostra()
{
    for (int i = 0; i < linhas * colunas; i++)
    {
        cout << matriz[i] << " ";
        if ((i + 1) % colunas == 0)
        {
            cout << endl;
        }
    }
}

int Matriz::soma_diagonal()
{
    int soma = 0;
    for (int i = 1; i <= linhas; i++)
    {
        if (i % 2 == 0)
        {
            soma += matriz[(i * i)];
        }
        else
        {
            soma += matriz[(i * i) - 1];
        }
    }
    return soma;
}

int Matriz::maximo()
{
    int max = matriz[0];
    for (int i = 0; i < linhas * colunas; i++)
    {
        if (matriz[i] > max)
        {
            max = matriz[i];
        }
    }
    return max;
}

Matriz operator+(Matriz &m1, Matriz &m2)
{
    Matriz soma(m1.linhas, m2.colunas);
    for (int i = 0; i < (m1.linhas * m2.colunas); i++)
    {
        soma.matriz[i] = m1.matriz[i] + m2.matriz[i];
    }
    return soma;
}
Matriz &Matriz ::operator=(Matriz soma)
{
    for (int i = 0; i < (linhas * colunas); i++)
    {
        matriz[i] = soma.matriz[i];
    }
    return *this;
}