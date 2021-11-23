#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
class Eleitor
{
    static int total;
    static int analfabetos;
    char escolaridade; //A-Analfabeto, P-Primeiro Grau, S-Segundo Grau, U-Superior
    string nome;

public:
    Eleitor(string name, char e)
    {
        this->nome = name;
        this->escolaridade = e;
        total++;
        if (e == 'A')
        {
            analfabetos++;
        }
    };
    ~Eleitor(){};
    static void ResultadoGeral()
    {
        cout << "Total de eleitores: " << total << endl;
        double p = 1.0 * analfabetos/total;
        cout << "Porcentagem de analfabetos: ";
        cout << fixed << setprecision(2) << p*100 << "%" <<endl;
    };
};

int Eleitor::total = 0;
int Eleitor::analfabetos = 0;

int main()
{
    string name;
    char e;

    cout << "Digite o nome:";
    cin >> name;
    cout << endl;
    cout << "Digite a escolaridade: ";
    cin >> e;
    cout << endl;

    Eleitor e1(name, e);

    cout << "Digite o nome:";
    cin >> name;
    cout << endl;
    cout << "Digite a escolaridade: ";
    cin >> e;
    cout << endl;

    Eleitor e2(name, e);

    cout << "Digite o nome:";
    cin >> name;
    cout << endl;
    cout << "Digite a escolaridade: ";
    cin >> e;
    cout << endl;

    Eleitor e3(name, e);


    Eleitor::ResultadoGeral();

    return 0;
}