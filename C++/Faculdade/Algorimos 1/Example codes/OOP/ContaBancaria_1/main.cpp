// Programa principal - Conta Bancárica
# include <iostream>
# include "ContaBancaria.h"

using namespace std;

int main (int argc, char **argv){
	
	ContaBancaria conta1; //chamada do construtor default 
	ContaBancaria conta2 (500); // chamada do construtor sobrecarregado 01 (com saldo inicial)
	ContaBancaria conta3(100, "Joana"); // chamada do construtor sobrecarregado 02 (saldo e nome)
	
	cout << "Contas antes das movimentacoes:\n";
	conta1.Imprime();
	conta2.Imprime();
	conta3.Imprime();
	
	// Movimentando as contas
	conta1.Deposito(600);
	conta2.Saque(100);
	conta3.Deposito(300);

    cout << "Contas depois de uma movimentacao:\n";
	conta1.Imprime();
	conta2.Imprime();
	conta3.Imprime();
	
	// Realizando uma transferencia
	conta3.Transferencia(&conta1, 300);
	
	cout << "Contas depois da transferencia:\n";
	conta1.Imprime();
	conta3.Imprime();
	
	// Chamando o metodo para pegar o saldo da conta 2
	cout << "Saldo da conta 2: " << conta2.getSaldo() << endl;
	cout << endl;
	
	// Chamando o metodo Inicializa para uma nova conta
   {
	ContaBancaria conta4;
	conta4.Inicializa(3,800,"Maria");
	conta4.Imprime();
   }
   
   return 0;
}
