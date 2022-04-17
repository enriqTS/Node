#include<iostream>

class pessoa
{
    private:
        int idade;
        std::string nome;

    public:
        pessoa(){
            idade = 0;
        }    
        pessoa(std::string nome, int idade){
            this->nome = nome;
            this->idade = idade;
        }
        friend std::ostream& operator<<(std::ostream &out,pessoa &t){
            out<<"Nome: " << t.nome<<std::endl;
            out<<"Idade: " << t.idade<<std::endl;
            return out;
        }
};

int main()
{
    pessoa P("Antonio", 19);
    std::cout << P << std::endl;
}