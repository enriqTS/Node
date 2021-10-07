#include <cstdlib> 
#include <ctime> 
#include <iostream> 
using namespace std; 
 
const int MAX_CONTRIBUINTES = 5; 
const int TAMANHO_NIF = 9; 
const int ANO_ATUAL = 2021; 
 
struct Contribuinte { 
    int nif[TAMANHO_NIF]; 
    int anoNascimento; 
    bool cidadaoPortugues; 
}; 

int calculeDV (int nif[TAMANHO_NIF]) { 
    int dv = 0; 
    for (int i = 0; i < TAMANHO_NIF-1; i++) { 
        dv = dv + nif[i] * (9 - i); 
    } 
    dv = dv % 11; 
    if (dv == 1 || dv == 0) 
        dv = 0; 
    else  
        dv = 11 - dv; 
    return dv; 
} 

void criaNIF (int nif [TAMANHO_NIF], int categoria) { 
    srand (time(0)); 
    nif[0] = categoria; 
    for (int i = 1; i < TAMANHO_NIF-1; i++) { 
        nif[i] = rand() % 10; 
    } 
    nif[TAMANHO_NIF-1] = calculeDV(nif); 
} 

bool confereCidadania(int cidadania, int cidadaoPortugues, int contaContribuintes){
    Contribuinte contribuintes[MAX_CONTRIBUINTES];
    if(cidadania == 1){
        return contribuintes[contaContribuintes].cidadaoPortugues = false;
    }  
    else{
        return contribuintes[contaContribuintes].cidadaoPortugues = true;
    }  
}
 
void imprimeNIF (int nif [TAMANHO_NIF]) { 
    cout << "NIF completo: "; 
    for (int i = 0; i < TAMANHO_NIF; i++) { 
        if (i == TAMANHO_NIF-1) 
            cout << "-"; 
        cout << nif[i]; 
    } 
} 

int main() { 
    int opcao, categoria, cidadania, contaContribuintes = 0;
    Contribuinte contribuintes[MAX_CONTRIBUINTES]; 

    do { 
        cout << "\nOPCOES:\n" 
             << "1 - Criar um NIF de um contribuinte fiscal\n" 
             << "2 - Mostrar todos os contribuintes\n" 
             << "9 - Sair\n" 
             << "Opcao? ";  
        cin >> opcao; 

        switch (opcao) { 
            case 1: 
                if (contaContribuintes < MAX_CONTRIBUINTES) { 
                    cout << "Qual a categoria desejada?" << endl;
                    cin >> categoria;
                    while (categoria != 1 && categoria !=2){
                        cout << "Categoria inválida, as categorias válidas são 1 ou 2, digite novamente." << endl;
                        cin >> categoria; 
                    }
                    criaNIF(contribuintes[contaContribuintes].nif, categoria);

                    cout << "Você tem cidadania portuguesa?" << endl;
                    cout << "Se sim digite 0, se não digite 1." << endl;
                    cin >> cidadania;
                    while (cidadania != 0 && cidadania != 1){
                        cout << "Valor inválido, digite novamente." << endl;
                        cin >> cidadania;
                    }
                    confereCidadania(cidadania, contribuintes[contaContribuintes].cidadaoPortugues,contaContribuintes);

                    cout << "Em que ano você nasceu?" << endl;
                    cin >> contribuintes[contaContribuintes].anoNascimento;
                    while (contribuintes[contaContribuintes].anoNascimento < 1901 && contribuintes[contaContribuintes].anoNascimento > 2021){
                        cout << "Data inválida, insira uma data entre os anos de 1900 e 2022." << endl;
                        cin >> contribuintes[contaContribuintes].anoNascimento;
                    }
                    cout << "Cadastro finalizado." << endl; 
                    contaContribuintes++; 
                }else { 
                    cout << "Lista de contribuintes cheia.\n"; 
                } 
            break; 

            case 2: 
                if (contaContribuintes > 0) { 
                    for (int i = 0; i < contaContribuintes; i++) { 
                        imprimeNIF(contribuintes[i].nif); 
                        cout << "\t" << ANO_ATUAL - contribuintes[i].anoNascimento << " anos"; 
                        if (contribuintes[i].cidadaoPortugues) 
                            cout << "\tCidadao Portugues"; 
                            cout << endl; 
                    } 
                }else 
                    cout << "Lista de contribuintes vazia.\n"; 
            break; 

            case 9: 
                cout << "Terminando...\n"; 
            break;

        default: 
            cout << "Opcao invalida!\n"; 
        }

    }while (opcao != 9); 

return 0; 
} 