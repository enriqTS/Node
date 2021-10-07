// Codigo de definicao : ContaBancaria.h

# ifndef CONTA_H
# define CONTA_H

// definicao do tipo
typedef struct {
	int numero;
	double saldo;
} ContaBancaria;

// Prototipo das funcoes
void Inicializa(ContaBancaria&, int, double);
void Inicializa(ContaBancaria&, int, float);
void Inicializa(ContaBancaria&, int);

void Deposito (ContaBancaria&, double);
void Saque (ContaBancaria&, double);
void Imprime (ContaBancaria);

void Transferencia(ContaBancaria&, ContaBancaria&, double);
//

#endif
