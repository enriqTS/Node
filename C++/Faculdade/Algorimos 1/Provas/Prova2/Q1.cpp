#include<iostream>
using namespace std;

template <class tipo>
class Vetor {
private:    
    tipo * ptr_tipo;
    unsigned tam;
    int Posicao;
public:
    Vetor(unsigned);
    ~Vetor();
    void Imprime();
    tipo Max();
    tipo Soma();
    void Inverte();
    tipo& operator[](unsigned i);
    Vetor<tipo> operator ++();
    void operator = (const Vetor<tipo> &);
    Vetor<tipo> operator + (const Vetor<tipo> &);
} ;

int main (){
    Vetor<int> v0(1),v1(5),v2(3),v3(5);

    cin >> v0[0];
    v0.Imprime();
    // cout << " Digite 5 valores para o vetor v1: " << endl ;
    // for(int i = 0 ; i < 5 ; i++)
    //     cin >> v1[i] ;

    cout << " Digite 3 valores para o vetor v2: " << endl ;
    for( int i = 0 ; i < 3 ; i++)
        cin >> v2[i] ;

    // cout << "Vetor v1: " << endl ;
    // v1.Imprime() ;
    // cout << endl ;

    cout << "Vetor v2 : " << endl ;
    v2.Imprime ( ) ;
    cout << endl ;

    cout << v2.Soma() << endl;
    cout << "Maior valor de v2: " << v2.Max() << endl;

    ++v2;
    v2.Imprime();
    cout << endl;

    v2.Inverte();
    v2.Imprime();

    // v3 = v1 + v2 ;
    // cout << "Soma dos vetores v1 e v2 (v3): " << endl ;
    // v3 . Imprime ( ) ;
    // cout << endl ;

    // cout << "Maior v al o r do v e to r v3 : " << v3 .Max ( ) << endl ;

    // cout << "Vetor v3 i n v e r t i d o : " << endl ;
    // v3.Inverte( ) ;
    // v3.Imprime( ) ;
    // cout << endl ;

    // cout << "\nSoma dos elementos do vetor v3 : " << v3.Soma() << endl ;

    // ++v3 ;
    // cout << "\nImprimindo o v e to r v3 d e p oi s do inc remen to . . . " << endl;
    // v3.Imprime() ;

return 0 ;
}

template<class tipo>
Vetor<tipo>::Vetor(unsigned t) 
{
    this->tam = t;
    ptr_tipo = new tipo[t];
}

template<class tipo>
Vetor<tipo>::~Vetor(){
    delete[] ptr_tipo;
}

template<class tipo>
tipo &Vetor<tipo>:: operator[](unsigned i){
    if(i>=tam)
        exit(0);
    return ptr_tipo[i];
}

template<class tipo>
void Vetor<tipo>:: Imprime(){
    for(int i=0; i < this->tam;i++){
        cout << ptr_tipo[i];
    }
}

// template<class tipo>
// Vetor<tipo> Vetor<tipo> :: operator+(const Vetor<tipo> &){
//     while(this->Posicao )
// }

template<class tipo>
tipo Vetor<tipo> :: Soma(){
    int soma = 0;
    for(int i=0; i < this->tam;i++){
        soma += ptr_tipo[i];
    }
    return soma;
}

template<class tipo>
tipo Vetor<tipo> :: Max(){
    int maior=0;
    for(int i=0; i<this->tam;i++){
        if(ptr_tipo[i] > maior)
            maior = ptr_tipo[i];
    }
    return maior;
}

template<class tipo>
Vetor<tipo> Vetor<tipo> :: operator++(){
    Vetor<tipo> vetor(this->tam);
    for(int i = 0;i<this->tam;i++)
        ptr_tipo[i]++;
    return vetor;    
}

template<class tipo>
void Vetor<tipo> :: Inverte(){
    int temp;
    for(int i=0, j=this->tam-1; i < this->tam/2;i++,j--){
        temp = ptr_tipo[i];
        ptr_tipo[i] = ptr_tipo[j];
        ptr_tipo[j] = temp;
    }
}