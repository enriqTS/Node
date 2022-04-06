#include <iostream>
using namespace std;

template <class tipo>
class Vetor
{
    tipo *ptr_tipo;
    unsigned tam;

public:
    Vetor(unsigned);
    ~Vetor();
    void Imprime();
    tipo Max();
    tipo Soma();
    void Inverte();
    inline tipo &operator[](unsigned i);
    Vetor<tipo> operator++();
    void operator=(const Vetor<tipo> &);
    Vetor<tipo> operator+(const Vetor<tipo> &);
};

template <class tipo>
Vetor<tipo>::Vetor(unsigned t) : tam(t)
{
    ptr_tipo = new tipo[t];
}

template <class tipo>
Vetor<tipo>::~Vetor()
{
    delete[] ptr_tipo;
}

template <class tipo>
Vetor<tipo> Vetor<tipo>::operator++()
{
    Vetor<tipo> vetor(this->tam);
    for (int i = 0; i < this->tam; i++)
        ptr_tipo[i]++;
    return vetor;
}

template<class tipo>
tipo &Vetor<tipo>:: operator[](unsigned i){
    if(i>=tam)
        exit(0);
    return ptr_tipo[i];
}

template <typename tipo>
void Vetor<tipo>::Imprime()
{
    for (int i = 0; i < this->tam; i++)
    {
        cout << this->ptr_tipo[i] << " ";
    }
}

template <class tipo>
void Vetor<tipo>::Inverte()
{
    tipo temp;
    for (int i = 0, j = this->tam - 1; i < this->tam / 2; i++, j--)
    {
        temp = ptr_tipo[i];
        ptr_tipo[i] = ptr_tipo[j];
        ptr_tipo[j] = temp;
    }
}

template <class tipo>
tipo Vetor<tipo>::Max()
{
    tipo maior = 0;
    for (int i = 0; i < this->tam; i++)
    {
        if (ptr_tipo[i] > maior)
            maior = ptr_tipo[i];
    }
    return maior;
}
template <class tipo>
tipo Vetor<tipo>::Soma()
{
    tipo soma = 0;
    for (int i = 0; i < this->tam; i++)
    {
        soma += ptr_tipo[i];
    }
    return soma;
}
template <typename tipo>
Vetor<tipo> Vetor<tipo>::operator+(const Vetor<tipo> &v2)
{
    tipo size, menor;

    if (this->tam > v2.tam)
    {
        size = this->tam;
        menor = v2.tam;
    }
    if (v2.tam > this->tam)
    {
        size = v2.tam;
        menor = this->tam;
    }
    if (v2.tam == this->tam)
    {
        size = v2.tam;
        menor = size;
    }

    Vetor<tipo> Soma(size);

    for (int i = 0; i < menor; i++)
    {
        Soma.ptr_tipo[i] = this->ptr_tipo[i] + v2.ptr_tipo[i];
    }

    if (size != menor)
    {
        for (int i = menor; i < size; i++)
        {
            if (this->tam != menor)
            {
                Soma.ptr_tipo[i] = this->ptr_tipo[i];
            }
            if (v2.tam != menor)
            {
                Soma.ptr_tipo[i] = v2.ptr_tipo[i];
            }
        }
    }

    return Soma;
}

template <typename tipo>
void Vetor<tipo>::operator=(const Vetor<tipo> &soma)
{
    for (int i = 0; i < soma.tam; i++)
    {
        this->ptr_tipo[i] = soma.ptr_tipo[i];
    }
}

int main()
{
    Vetor<int> v1(5), v2(3), v3(5);

    cout << "Digite 5 valores para o vetor v1: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> v1[i];
    }
    cout << "Digite 3 valores para o vetor v2: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> v2[i];
    }

    cout << "Vetor v1: " << endl;
    v1.Imprime();
    cout << endl;

    cout << "Vetor v2: " << endl;
    v2.Imprime();
    cout << endl;

    v3 = v1 + v2;

    cout << "Soma dos vetores v1 e v2 (v3): " << endl;
    v3.Imprime();
    cout << endl;

    cout << "Maior valor do vetor v3: " << v3.Max() << endl;

    cout << "Vetor v3 invertido: " << endl;
    v3.Inverte();
    v3.Imprime();
    cout << endl;

    cout << "\nSoma dos elementos do vetor v3: " << v3.Soma() << endl;

    ++v3;
    cout << "\nImprimindo o vetor v3 depois do incremento... " << endl;
    v3.Imprime();
    cout << endl;
    return 0;
}