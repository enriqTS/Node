// Class1.cpp
// Mostra a classe retangulo

#include <iostream>
using namespace std;

class Retangulo {  //Definição da classe
  private:
    int base, altura; //membros de dados - atributos

  public:
    Retangulo(){
       base = 0;
       altura = 0;
    }

    Retangulo(int b, int a){
		base = b;
		altura = a;
	}

    ~Retangulo(){
       cout << "Destruindo o cara " << base << " - " << altura << endl;
    }


    void Inicia (int b, int h){ //Função membro para inicializar dados
           base = b;
           altura = h;
    }

    void ImprimeArea (){  // Função membro que imprime dados
           cout << "Base: " << base << " Altura: " << altura;
           cout << " Area: " << (base*altura) << endl;
    }
};

int main () {
    Retangulo R1, R2, R3(5,7); // Declara dois objetos da classe Retangulo
    R1.Inicia(2,6);
    R1.ImprimeArea();

    R2.Inicia(8,3);
    R2.ImprimeArea();

    {

    Retangulo R4(10,10);

    }

    R3.ImprimeArea();

    return 0;
}
