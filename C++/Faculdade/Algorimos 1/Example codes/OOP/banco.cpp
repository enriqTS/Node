// Exemplo de Heranca em C++
// (C) Copyright Fernando Montenegro e Roberto Pacheco - 1993

#include <iostream>
#include <string.h>

using namespace std;

char mensagem[80] = {"Para doações ligue: 0800 12345678"};

class Usuario {
 private:
  char nome[30];
 public :
    Usuario(){};
    ~Usuario(){cout << " destruindo Usuario " << endl;};
	void entrada( );
	void mostrar( );
};

class Usuario_vip : public Usuario {
 public :
    Usuario_vip(){};
    ~Usuario_vip(){ cout << "destruindo Usuario Vip " << endl;};
	void editar( );
};

void Usuario::entrada( ){
  cout << "Entre com o seu Nome : ";
  cin.getline(this->nome,30);
}

void Usuario::mostrar( ){
  cout << "\nDADOS DO USUARIO\n"
       << "\tNome     : " << nome  << "\n"
       << "\nMENSAGEM DO SISTEMA : \n\t"
       << mensagem << "\n";
}

void Usuario_vip::editar( ){
  cout << "\nEDICAO DA MENSAGEM \n\t"
       << "Nova Mensagem : ";
  cin.getline(mensagem,200);
}

int main( ){
 const char* senha = "VIP";
 char senha_in [80];
 char resposta;

 do{
	cout << "Entre com a senha de acesso : " << endl;
	cin.getline(senha_in,80);
	if(strcmp(senha_in,senha))  {
	  Usuario pessoa;        // declaracao de Usuario comum
	  pessoa.entrada();
	  pessoa.mostrar();

	}
	else {
	  Usuario_vip pessoa;    // declaracao de Usuario vip
	  pessoa.entrada();
	  pessoa.mostrar();
	  pessoa.editar();
	}
	cout << "\nDeseja Continuar (S/N) ? " << endl;
	cin >> resposta;
	cin.ignore();

 }
 while (resposta != 'N');

 return 0;
}
