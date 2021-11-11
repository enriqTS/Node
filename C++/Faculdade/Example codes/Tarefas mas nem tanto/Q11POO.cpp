#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Restaurante {  
  private:
    float precomed;
    char tipo[80], nome[80], endereco[80]; 

  public:
    Restaurante(){
       precomed = 0;
       strcpy(tipo,"sasisos");
       strcpy(nome,"sasisos");
       strcpy(endereco, "sasisos"); 
    }

    Restaurante(float a, char b[80], char n[80], char m[80]){
		precomed = a;
		strcpy(tipo, b); 
        strcpy(nome, n);
        strcpy(endereco, m);
	}

    ~Restaurante(){
       cout << "Destruindo o "<< nome << endl;
    }


    void Inicia (float a, char b[80], char n[80], char m[80]){ 
		precomed = a;
		strcpy(tipo, b); 
        strcpy(nome, n);
        strcpy(endereco, m);;
    }

    void ImprimeDados (){ 
           cout << "Preco Medio: " << precomed << ". Tipo de comida: " << tipo;
           cout << ". Nome do restaurante: " << nome << ". Endereco do restaurante"<< endereco << endl;
    }
};

int main () {
    Restaurante R1, R2, R3(5,"Churrasco","MamaJulia","Casa da mae Joana"); 
    R1.Inicia(5,"Torresmo Engordurado","Birosca do Ze","Esquina de qualquer rua");
    R1.ImprimeDados();
    R3.ImprimeDados();

    return 0;
}
