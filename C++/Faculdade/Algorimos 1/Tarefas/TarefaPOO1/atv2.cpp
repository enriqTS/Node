#include <iostream>
using namespace std;

class Fracao{
    private:
        int denominador;
        int numerador;
        int mmc;
        int mdc;
        int findmdc(Fracao&, Fracao&);
        int findmmc(Fracao&, Fracao&);
    public:
        inline Fracao(int = 0, int = 1);
        ~Fracao();
        inline void ImprimeNumerador();
        inline void ImprimeDenominador();
        inline void Imprime();
        friend Fracao operator + (Fracao&, Fracao&);
        friend Fracao operator - (Fracao&, Fracao&);
        int getNumerador();
        int getDenominador();
};

Fracao::Fracao(int numerador, int denominador){
    this->numerador = numerador;
    this->denominador = denominador;
}

Fracao :: ~Fracao(){
    cout << "Destruindo a fracao: " << this->numerador << "/" << this->denominador << endl;
}

int Fracao :: findmdc(Fracao& n1, Fracao& n2){
    int mdc;
    for(int i=1; i <= n1.denominador && i <= n2.denominador; i++){
        if(n1.denominador%i == 0 && n2.denominador%i == 0){
           this->mdc = i;
        }
    }
    return this->mdc;
}

int Fracao :: findmmc(Fracao& n1, Fracao& n2){
    this->mmc = (n1.denominador * n2.denominador)/this->findmdc(n1,n2);
    return this->mmc;
}

Fracao operator + (Fracao& n1, Fracao& n2){
    Fracao soma;
    soma.findmmc(n1,n2);
    soma.numerador = (n1.numerador * (soma.mmc/n1.denominador)) + (n2.numerador * (soma.mmc/n2.denominador));
    soma.denominador = soma.mmc;
    return soma;
}

Fracao operator - (Fracao& n1, Fracao& n2){
    Fracao sub;
    sub.findmmc(n1,n2);
    sub.numerador = (n1.numerador * (sub.mmc/n1.denominador)) - (n2.numerador * (sub.mmc/n2.denominador));
    sub.denominador = sub.mmc; 
    return sub;
}

void Fracao :: Imprime(){
    cout << numerador << "/" << denominador << endl;
    
}
void Fracao :: ImprimeNumerador(){
    cout << "Numerador: " << numerador << endl;
}
void Fracao :: ImprimeDenominador(){
    cout << "Denominador: " << denominador << endl;
}

int Fracao :: getNumerador(){
    return numerador;
}

int Fracao :: getDenominador(){
    return denominador;
}

int main(){
    int numerador;
    int denominador;
    
    Fracao F1;
    Fracao F2;
    
    cout << "Digite o numerador(Apenas numeros inteiros): " << endl;
    cin >> numerador;
    cout << "Digite o denominador(Apenas numeros inteiros): " << endl;
    cin >> denominador;
    
    Fracao F3(numerador, denominador);
    
    cout << "Digite o numerador(Apenas numeros inteiros): " << endl;
    cin >> numerador;
    cout << "Digite o denominador(Apenas numeros inteiros): " << endl;
    cin >> denominador;

    Fracao F4(numerador, denominador);

    F1 = F3 + F4;
    F2 = F3 - F4;

    numerador = F1.getNumerador();
    denominador = F1.getDenominador();

    cout << "Numerador(get): " << numerador << endl;
    cout << "Denominador(get): " <<  denominador << endl;

    F1.Imprime();
    F1.ImprimeNumerador();
    F1.ImprimeDenominador();

    F2.Imprime();
    F2.ImprimeNumerador();
    F2.ImprimeDenominador();

    return 0;
}

