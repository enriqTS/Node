// FUNCVIRT.CPP - Funcoes Virtuais e Polimorfismo
// (C) Copyright Fernando Montenegro e Roberto Pacheco
// Com referências

#include <iostream>
#include <string.h>

using namespace std;

class Transacao {
   char cliente[31];
 public :
   Transacao(char * nome) {strcpy(cliente,nome);};
   virtual void mostrar();
};

class VendaVista : public Transacao {
 protected :
   double valor;
 public :
   VendaVista (char *, double);
   void mostrar();
};

class VendaPrazo : public VendaVista {
   float juros;
 public :
   VendaPrazo(char *, double, float);
   void mostrar();
};

int main () {
   char nome[31];
   double preco;  float taxa;

   cout << "Entre com o Nome : " ; cin.get(nome,30);  cin.get();
   cout << "Entre com o Valor a Vista : "; cin >> preco; cin.get();
   cout << "Entre com a Taxa de Juros (%) : "; cin >> taxa;

   Transacao objtransacao(nome);
   VendaVista objvendavista(nome,preco);
   VendaPrazo objvendaprazo(nome,preco,taxa);
   
   Transacao & vendas1 = objtransacao;
   Transacao & vendas2 = objvendavista;
   Transacao & vendas3 = objvendaprazo;

   cout << "\n\n";
   
   vendas1.mostrar(); cout << '\n';
   vendas2.mostrar(); cout << '\n';
   vendas3.mostrar(); cout << '\n';
   
   return 0;
}

void Transacao :: mostrar() {
   cout << "Nome do Cliente : " << cliente << '\n';
}

VendaVista::VendaVista(char* nome, double preco):Transacao(nome){
       valor = preco;
}

void VendaVista :: mostrar() {
   Transacao::mostrar(); 
   cout << "  Valor da Compra : " << valor << '\n';
}

VendaPrazo :: VendaPrazo (char * nome, double preco, float taxa) :
VendaVista (nome, preco) {
       juros = taxa;
}

void VendaPrazo :: mostrar() {
   Transacao::mostrar(); 
   cout << "  Taxa Praticada  : " << juros << '\n'
	<< "  Valor da Compra : " << valor*(100+juros)/100 << '\n';
}

/*****************************************************************

OBJETIVO DO PROGRAMA :

FUNCVIRT.CPP - O programa implementa a entrada de informacoes sobre 
um cliente e suas alternativas de compra (`a  vista  ou  a  prazo). 
Para determinar o valor a prazo, pede-se o valor da taxa de  juros. 
Ao final, o programa apresenta os tres niveis de informacoes: 
                a) Nome do cliente; 
                b) Nome e valor `a vista;
                c) Nome, taxa e valor a prazo. 

TEORIA ABORDADA :

O programa implementa o Polimorfismo atraves de Funcao Virtual.

A criacao de objetos  dindmicos  associados  a  ponteiros  para  a 
classe base faz  com  que  o  programa  deva  efetivar  a  ligacao 
objeto-funcao em tempo de execucao.  Para  tal,  e'  necessario  o 
emprego de funcao virtual pura.

Se voce remover a declaracao  "virtual"  na  definicao  da  classe 
"VendaVista", os resultados mostrarao apenas o nome da pessoa, nas 
tres impressoes. Isto ocorre porque a  ligacao  objeto-funcao  foi 
feita em tempo de compilacao. O compilador sabia  que  o  ponteiro 
era da classe base "Transacao"  e  chama  a  funcao  desta  classe 
sempre que ponteiro  solicitar.  A  declaracao  "virtual"  adia  a 
ligacao para a execucao do programa.

EXPLICACAO :

O programa pede o nome, valor `a vista e taxa de juros. Com  estes 
valores, ele cria um objeto para cada classe na  hierarquia  e  os 
guarda no array de ponteiros para a classe base ("vendas").

Quando o programa chama a funcao membro "mostrar()" para  cada  um 
dos objetos criados, executa-se a versao da classe do objeto. Para 
"VendaPrazo" significa chamar "Transacao::mostrar()" que apresenta 
o   nome.   Logo   apos,   o   programa    retorna    `a    funcao 
"VendaPrazo::mostrar()" e apresenta a taxa  de  juros  e  o  valor 
final da transacao (considerando os juros).

*****************************************************************/
