// Código de definição : ContaBancaria.h

# ifndef CONTA_H
# define CONTA_H

// definição da classe
class ContaBancaria {
	private:
	   int numero;
	   double saldo;
	   char nome[40];
	public:
       ContaBancaria (); // default
       ContaBancaria (double); // construindo com saldo
       ContaBancaria (double, const char*); // construindo com saldo e nome
       ~ContaBancaria(); // destrutor
       void Inicializa(int, double, const char*);
       double getSaldo();
       void Deposito (double);
       void Saque (double);
       void Imprime ();
       void Transferencia(ContaBancaria*, double);
};

#endif
