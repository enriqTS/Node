// Automovel.cpp
// Exemplo de construtores e destrutores

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Automovel{
  char modelo[20];// atributo privado
  public:
    //construtores sobrecarregados sem e com parametro
    Automovel ( ) {
      strcpy(modelo," ");
      cout << "Construindo... " << modelo << endl;
    }
    Automovel (char nome[20]) {
	  strcpy(modelo,nome);
      cout <<"Construindo nao default..." << modelo << endl;
    }
    // destrutor
    ~Automovel ( ) {cout << "destruindo..." << modelo << "\n";}
    // mostra o modelo
    void mostrar() {cout << "modelo:" << modelo << "\n";}
};

int main ( ){
    // instanciando a classe Automovel, ou, criando um objeto
    Automovel GM(" Corsa ");
    Automovel Ford("Fiesta");
    Automovel Honda;

    // mostrando os modelos dos carros
    GM.mostrar();
    Ford.mostrar();
    Honda.mostrar();

   // criando mais dois objetos do tipo carro
    { // esse bloco poderia ser um if, for ou while
        Automovel Teste1 ("fusca"), Teste2("Jipe");
        Teste1.mostrar(); Teste2.mostrar();
    }
    // quando sai do bloco, Teste1 e Teste2 são destruidos
    // Teste1.mostrar();
    // aqui vai dar um erro pois Teste1 não existe mais
    return 0;
}
