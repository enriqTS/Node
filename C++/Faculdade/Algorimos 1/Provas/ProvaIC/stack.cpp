#include <iostream>
#include <stack>

using namespace std;

bool pilhas_iguais(std::stack<int>, std::stack<int>);

bool pilhas_iguais(stack<int> P1,stack<int> P2){
    stack<int> Aux1, Aux2;
    bool igual = true;

    while(!P1.empty() && !P2.empty()){
        Aux1.push(P1.top());
        P1.pop();
        Aux2.push(P2.top());
        P2.pop();
    }

    while(!Aux1.empty() && !Aux2.empty()){
        if( Aux1.top() != Aux2.top()){
            igual = false;
        }    
        P1.push(Aux1.top());
        Aux1.pop();
        P2.push(Aux2.top());  
        Aux2.pop();  
    }
    
    if(!Aux1.empty() && Aux2.empty()){
        igual =  false;
        P1.push(Aux1.top());
        Aux1.pop();
    }

    if(Aux1.empty() && !Aux2.empty()){
        igual = false;
        P2.push(Aux2.top());
        Aux2.pop();
    }
    return igual;
}

int main(){
    stack<int> P1, P2;

    P1.push(2);
    P1.push(3);
    
    P2.push(2);
    P2.push(3);

    if(pilhas_iguais(P1,P2)){
        cout << "Sao iguais" << endl;
    }
    else{
        cout << "Sao diferentes" << endl;
    }    

    cout << P1.top() << endl;
    P1.pop();
    cout << P1.top() << endl;

    cout << P2.top() << endl;
    P2.pop();
    cout << P2.top() << endl;
    
    return 0;
}