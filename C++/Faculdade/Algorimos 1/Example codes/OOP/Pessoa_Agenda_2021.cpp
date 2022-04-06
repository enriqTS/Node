#include <iostream>
#include <string.h>

using namespace std;

class Pessoa{
  private:
     char nome[30];
     int idade;
     float altura;
     // sugestão: incluir telefone, email e etc.
  public:
     Pessoa(); // construtor default
     ~Pessoa(); // destrutor
     void Atualizar (const char [30], int, float);
     void Imprimir();
     void RetornaNome(char[30]);
};

class Agenda{
   private:
      Pessoa Povo[10];
      int tamanho;
   public:
      Agenda(){tamanho=0;}; // construtor default
      bool removePessoa(const char [30]);
      int buscaPessoa(const char [30]);
      void ImprimePovo();
      bool armazenaPessoa(Pessoa);
      void ImprimePessoa(int);

};

// CLASSE PESSOA - METODOS

Pessoa::Pessoa (){  // Construtor default Pessoa
         strcpy(nome,"");
         idade = 0;
         altura = 0;
}

Pessoa::~Pessoa(){  // Destrutor Pessoa
}

void Pessoa::Atualizar(const char nome[30], int idade, float altura){ // Atualiza dados de pessoa
   strcpy(this->nome, nome);
   this->idade = idade;
   this->altura = altura;
}

void Pessoa::Imprimir(){ // Imprime dados de pessoa
    cout << nome << endl;
    cout << idade << endl;
    cout << altura << endl;
}

void Pessoa::RetornaNome(char nome[30]){ // Retorna o nome da pessoa
   strcpy(nome, this->nome);
}


// CLASSE AGENDA - METODOS

bool Agenda::armazenaPessoa(Pessoa P){ // Armazena pessoa na agenda
   char nome[30];
   if(tamanho==10)  // se a agenda está cheia, retorna falso
     return false;
   else{
      for(int i = 0; i < 10 ; i++){
          Povo[i].RetornaNome(nome);
          if(!strcmp(nome, "")){ // se a posição está livre, armazena pessoa
            Povo[i] = P;
            tamanho++;
            return true;
          }
      }
      return false;
   }
}

int Agenda::buscaPessoa(const char nome[30]){ // Busca uma pessoa na agenda
   char nome2[30];
   for(int i = 0; i < 10 ; i++){
      Povo[i].RetornaNome(nome2);
          if(!strcmp(nome, nome2))
            return i; // se encontra a pessoa, retorna sua posicao

    }
    return -1; // se não encontra pessoa retorna -1
}

bool Agenda::removePessoa(const char nome[30]){ // Remove Pessoa
     int i = buscaPessoa(nome);
     if(i>=0){   // Se encontra pessoa, atualiza com vazio
       Povo[i].Atualizar("",0,0);
       return true; // se conseguiu apagar, retorna verdadeiro
     }
     else return false; // se não conseguiu apagar, retorna falso
}

void Agenda::ImprimePovo(){ // Imprime toda a agenda
      char nome[30];
      for(int i = 0; i < 10 ; i++){
          Povo[i].RetornaNome(nome);
          if(strcmp(nome, ""))   // Se o nome é válido, imprime
            Povo[i].Imprimir();
      }
}

void Agenda::ImprimePessoa(int i){ // Imprime apenas uma pessoa
      Povo[i].Imprimir(); // imprime pessoa da posição i
}

// FUNCAO PRINCIPAL

int main (){
   Pessoa a, b, c;
   a.Atualizar("Sandro", 49, 1.76);
   b.Atualizar("Edelma", 44, 1.72);
   c.Atualizar("Joana", 6, 1.10);

   a.Imprimir();
   b.Imprimir();
   c.Imprimir();

   Agenda X;
   cout << "imprimindo agenda vazia " << endl;
   X.ImprimePovo();

   X.armazenaPessoa(a);
   X.armazenaPessoa(b);
   X.armazenaPessoa(c);
   cout << "imprimindo agenda com dados " << endl;
   X.ImprimePovo();

   X.ImprimePessoa(3);

   cout << "Procurando Joana" << endl;
   cout << "a pessoa procurada está no indice " <<  X.buscaPessoa("Joana") << endl;

   X.removePessoa("Sandro");

   X.ImprimePovo();

   return 0;
}
