#include <iostream>

template<typename T, int n=10>
class Pilha
{
    private:
        T Dados[n];
        int topo;

    public:
        Pilha(){
            topo = 0;
        }
        void Empilha(T d){
            if(topo<n){
                Dados[topo]=d;
                topo++;
            }
        }
        T Desempilha(){
            if(topo>0){
                topo--;
                return Dados[topo];
            }
        }
        void Imprime(){
            for(int i = 0; i<topo;i++)
                std::cout<<Dados[i]<<"\n";
        }
};

int main()
{
    Pilha<int, 5> p;
    p.Empilha(8);
    p.Empilha(6);

    p.Imprime();
    int n = p.Desempilha();
    std::cout << "Desempilhado: " << n << std::endl;
    p.Imprime();
    return 0;
}