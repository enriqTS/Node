// Implementando os métodos da ContaBancaria

# include <iostream>
# include <string.h>
# include "ContaBancaria.h"

   
using namespace std;

ContaBancaria::ContaBancaria(){
       numero = 1;
       saldo = 0;
       strcpy(nome, " ");
}
       
ContaBancaria::ContaBancaria(double saldo){
       numero = 1;
       this->saldo = saldo;
       strcpy(nome, " ");
}
              
ContaBancaria::ContaBancaria(double saldo, const char *nome){
       numero = 1;
       this->saldo = saldo;
       strcpy(this->nome, nome);
}

ContaBancaria::~ContaBancaria(){
       cout << " Destruindo... " << endl;
       cout << "Cliente: " << nome << endl;
       cout << "Saldo: " << saldo << endl;
}
       
void ContaBancaria::Inicializa(int numero, double saldo, const char *nome){
   	   this->numero = numero;
	   this->saldo = saldo;
	   strcpy(this->nome,nome);
}

void ContaBancaria::Deposito(double valor){
	   this->saldo += valor;
}

void ContaBancaria::Saque (double valor){
       this->saldo -= valor;
}

void ContaBancaria::Imprime ( ){
	cout << "*** Dados da Conta ***" << endl;
 	cout << "Cliente: " <<  nome << endl;
	cout << "Numero: " << numero << endl;
	cout << "Saldo: " <<  saldo << endl;
	cout << "------------------------------------" << endl;
}

double ContaBancaria::getSaldo(){
	return this->saldo;
}

void ContaBancaria::Transferencia(ContaBancaria * c1, double valor){
   c1->Saque(valor);
   this->Deposito(valor);
}
