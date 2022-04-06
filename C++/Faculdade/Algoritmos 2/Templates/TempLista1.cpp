#include <iostream>

template <typename T>
void troca( T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int x = 5, y = 8;
    std::cout << "Primeiro numero: " << x << ".\nSegundo numero: " << y << ".\n";
    troca(x,y);
    std::cout << "Primeiro numero(Trocado): " << x << ".\nSegundo numero(Trocado): " << y << ".\n";
    float a = 5.5, b = 8.8;
    std::cout << "Primeiro numero: " << a << ".\nSegundo numero: " << b << ".\n";
    troca(a,b);
    std::cout << "Primeiro numero(Trocado): " << a << ".\nSegundo numero(Trocado): " << b << ".\n";   
}