#include <iostream>

template <typename T>
void troca( T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

void troca (std::string &x, std::string&y)
{
    std::string temp = x;
    x = y;
    y = temp;
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
    
    std::string s1, s2;
    s1 = "Ola";
    s2 = "mundo";  
    std::cout << "Primeira string: " << s1 << ".\nSegunda string: " << s2 << ".\n";
    troca(s1,s2);
    std::cout << "Primeira string(Trocada): " << s1 << ".\nSegunda string(Trocada): " << s2 << ".\n"; 

    return 0;
}