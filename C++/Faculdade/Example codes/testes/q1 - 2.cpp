/*
Implemente um programa ampliando a classe Eleitor. O usu�rio dever� digitar as
especifica��es de um eleitor (nome e escolaridade). Ao final, o programa deve mostrar
o total de eleitores e o percentual de analfabetos (m�todo ResultadoGeral).
*/


#include <iostream>
using namespace std;

class Eleitor 
{
	private:
	static int total;
	static int analfabetos;
	string nome;
	char escolaridade; //A-Analfabeto, P-Primeiro Grau, S-Segundo Grau, U-Superior
		
	public :
		Eleitor(); //construtor
		~Eleitor();  // isso � pra que? destrutor
		void analfabetos_();
		void total_();
		static void ResultadoGeral();
	
};

int Eleitor::analfabetos = 0;
int Eleitor::total = 0;

void Eleitor::total_ ()  //o que coloca aqui dentro?
{
	total++; // usa this mesmo?
}

void Eleitor::analfabetos_ () 
{
	analfabetos++;  
}

void Eleitor :: ResultadoGeral()
{
	float porcentagem;
	porcentagem = (analfabetos / total) * 100;
	cout << porcentagem;
}

int main() 
{
	Eleitor E1;
	string nome;
	char escolaridade;
	int resposta, total=0;
	float porcentagem, analfabeto=0;
	
	do
	{
		cout << "Nome: ";
		cin >> nome;
		cout << "Escolaridade: ";
		cin >> escolaridade;
		cout << "Digite 0 para inserir novos dados ou 1 para terminar: ";
		cin >> resposta;
		
		if (escolaridade == 'a' || escolaridade == 'p' || escolaridade == 's' || escolaridade == 'u') 
			E1.total_();
	
		if (escolaridade == 'a')
			E1.analfabetos_();
	}
	while (resposta != 1);
	
	E1.ResultadoGeral();
	
	cout << endl;
	cout << "Total de eleitores: " << total << endl;
	cout << "total de analfabetos: " << analfabeto << endl; 
	cout << "Porcentagem de analfabetos: " << porcentagem << " % ";
	
	return 0;
}
