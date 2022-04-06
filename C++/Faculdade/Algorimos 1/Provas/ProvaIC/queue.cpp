#include <iostream>
#include <queue>

using namespace std;

std::queue<int> soma_filas(std::queue<int>, std::queue<int>);

queue<int> soma_filas(queue<int> F1, queue<int> F2){
    queue<int> Aux1, Aux2, Soma;

    while(!F1.empty()){
        Aux1.push(F1.front());
        F1.pop();
    }

    while(!F2.empty()){
        Aux2.push(F2.front());
        F2.pop();
    }

    while(!Aux1.empty() || !Aux2.empty()){

        if(!Aux1.empty() && !Aux2.empty()){
            int soma = Aux1.front() + Aux2.front();
            Soma.push(soma);
        }

        else if(!Aux1.empty() && Aux2.empty()){
            Soma.push(Aux1.front());
        }

        else if(Aux1.empty() && !Aux2.empty()){
            Soma.push(Aux2.front());
        }

        if(!Aux1.empty()){
            F1.push(Aux1.front());
            Aux1.pop();
        }

        if(!Aux2.empty()){
            F2.push(Aux2.front());
            Aux2.pop();
        }
    }
    return Soma;
}

int main(){
    queue<int> F1, F2, soma;

    F1.push(1);
    F1.push(1);
    F1.push(1);
    F1.push(1);
    F1.push(5);

    F2.push(2);
    F2.push(2);
    F2.push(2);

    soma = soma_filas(F1, F2);

    while(!soma.empty()){
        cout << soma.front() << " ";
        soma.pop();
    }
    cout << endl;
    while(!F1.empty()){
        cout << F1.front() << " ";
        F1.pop();
    }
    cout << endl;
    while(!F2.empty()){
        cout << F2.front() << " ";
        F2.pop();
    }

    return 0;
}