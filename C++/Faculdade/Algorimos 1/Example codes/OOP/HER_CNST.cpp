// HER_CNST.CPP - Construtores e Destrutores em Hierarquia
// (C) Copyright Fernando Montenegro e Roberto Pacheco

#include <iostream>

using namespace std;

class Animal {
 protected :
  long quantidade;
 public :
  inline Animal (long qtde);
  inline ~Animal ();
  void mostrar ();

};

class Bovino:public Animal {
 protected :
  string raca;
 public :
   inline Bovino (string marca, long qtde);
   inline ~Bovino ();
   void mostrar ();
};

class BovinoLeite : public Bovino {
   long producao_diaria;
  public :
   BovinoLeite (long prod, string marca, long qtde);
   ~BovinoLeite ();
   void mostrar ();
};

int main () {
  BovinoLeite vaca (10,"Holandesa",350);
  vaca.mostrar();

  return 0;
}

/******************** Funcoes da Animal *************************/

Animal::Animal (long qtde) {
    quantidade = qtde;
    cout << "\nEstou construindo um Animal";
}
Animal::~Animal() {
  cout << "\nApagando um Animal ...";
}

void Animal::mostrar ()  {
   cout << "\nQuantidade de Animais : " << quantidade << endl;
}


/******************* Funcoes da Classe Bovino *******************/

Bovino::Bovino (string marca, long qtde) : Animal (qtde)  {
  raca = marca;
  cout << "\nEstou construindo um Bovino";
}

Bovino::~Bovino() {
 cout << "\nApagando um Bovino ...";
}

void Bovino::mostrar ()  {
   cout << "\nRaca : " << raca << endl;
}

/*************** Funcoes da Classe BovinoLeite ******************/

BovinoLeite::BovinoLeite(long prod, string marca,long qtde)
   : Bovino(marca, qtde) {
         producao_diaria = prod;
         cout << "\nEstou construindo um Bovino leiteiro";
}

BovinoLeite::~BovinoLeite() {
  cout << "\nApagando um Bovino leiteiro ...";
}

void BovinoLeite::mostrar ()  {
   // uma maneira de implementar o metodo mostrar na classe BovinoLeite
   // metodo tem acesso aos dados protegidos das classes base
   cout << "\n\nQuantidade de Animais : " << quantidade;
   cout << "\nRaca do Animal        : " << raca;
   cout << "\nProducao Diaria       : " << producao_diaria << "\n\n";

   // outra forma de implementar o metodo mostrar na classe BovinoLeite
   // Animal::mostrar();
   // Bovino::mostrar();
   // cout << "producao diaria :" << producao_diaria <<endl;
}

/*****************************************************************

OBJETIVO DO PROGRAMA :

O programa implementa uma hierarquia  para  guardar  os  dados  de
animais bovinos produtores de leite. Os dados  sao  quantidade  de
animais, raca destes animais e a producao diaria que estes animais
possuem.


TEORIA ABORDADA :

O programa mostra o funcionamento de Construtores e Destrutores ao
longo de uma hierarquia de classes em C++, ilustrando os seguintes
topicos :

- Sintaxe de declaracao de acesso aos construtores superiores
- A ordem de acionamento de construtores
- A ordem de acionamento de destrutores
- Comentario sobre o acesso protegido nas superclasses


EXPLICACOES :

Na funcao "main()", cria-se uma instancia da classe  "BovinoLeite"
de nome "vaca". Ela representa 350 animais da raca "Holandesa" com
uma producao diaria de 10 litros de leite.

A declaracao desta instancia na sentenca :

                BovinoLeite vaca (10,"Holandesa",350);

Aciona  o  construtor  "BovinoLeite()",  este  chama   "Bovino()",
passando  a  raca  e  a  quantidade  de  animais.   O   construtor
"Bovino()",  por  sua  vez,   chama   o   construtor   "Animal()",
passando-lhe o total de animais (350) que e', finalmente, guardado
no atributo "quantidade". Ao retornar ao  construtor  "Bovino",  o
programa guarda o valor do atributo "raca"  (string  "Holandesa").
Encerrado este processamento, o programa retorna ao construtor  de
BovinoLeite e guarda o valor do  atributo  "producao_diaria" (10).
Todo este caminho e' registrado por   mensagens   colocadas   nos
construtores de cada classe. Isto encerra a criacao do objeto.

A seguir, retornando `a funcao "main()", o programa  encontra  uma
chamada `a funcao membro "mostra()" da classe "BovinoLeite".  Esta
apresenta os dados dos atributos  na  hierarquia,  acessiveis  por
terem sido declarados com acesso "protected".

Quando a funcao "main()" se encerra, o objeto "vaca" e' destruido,
provocando a chamada dos destrutores da derivada ate'  a  raiz  da
arvore, como se pode ver na mensagem do programa.

*****************************************************************/

