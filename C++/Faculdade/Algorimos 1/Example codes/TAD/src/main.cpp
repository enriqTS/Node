// Programa principal

# include <iostream>
# include "ContaBancaria.h"

using namespace std;

int main (){

    ContaBancaria conta1, conta2, conta3;

	Inicializa(conta1, 1234, 300.00);
	Inicializa(conta2, 5678, 500.00);
    Inicializa(conta3, 5679);

	cout << "Antes da movimentacao:" << endl;

	Imprime(conta1);
	Imprime(conta2);
	Imprime(conta3);

	Deposito(conta1, 50.00);
	Saque(conta1, 70.00);

	cout << "Depois da movimentacao:" << endl;

	Imprime (conta1);
	Imprime (conta2);

	Transferencia(conta2, conta1, 100);

	Imprime (conta1);
	Imprime (conta2);

	return 0;
}