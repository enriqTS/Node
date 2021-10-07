// Implementando as funcoes da ContaBancaria

# include <iostream>
# include "ContaBancaria.h"

using namespace std;

void Inicializa(ContaBancaria& conta, int numero, double saldo){
	conta.numero = numero;
	conta.saldo = saldo;
}

void Inicializa(ContaBancaria& conta, int numero, float saldo){
	conta.numero = numero;
	conta.saldo = (double)saldo;
}

void Inicializa(ContaBancaria& conta, int numero){
	conta.numero = numero;
	conta.saldo = 0.0;
}

void Deposito (ContaBancaria& conta, double valor){
	conta.saldo += valor;
}

void Saque (ContaBancaria& conta, double valor){
	conta.saldo -= valor;
}

void Imprime (ContaBancaria conta){
    cout << "Dados da conta" << endl;
	cout << "Numero: " << conta.numero << endl;
	cout << "Saldo: " <<  conta.saldo << endl;
	cout << "------------------" << endl;
}

void Transferencia(ContaBancaria& c1, ContaBancaria& c2, double valor){
   Saque (c1, valor);
   Deposito (c2, valor);
}
