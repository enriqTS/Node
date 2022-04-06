#include <iostream>
#include <list>

using namespace std;

bool Membro(list<int> L, int info){
    list<int> Aux = L;
    while(!Aux.empty()){
        if(info == Aux.back()){
            return true;
        }
        Aux.pop_back();
    }
    return false;
}

list<int> Uniao(list<int> L1, list<int> L2){
    list<int> Aux1, Aux2, Unida;
    Aux1 = L1;
    Aux2 = L2;

    while(!Aux1.empty()){
        if(!Membro(Unida, Aux1.back())){
            Unida.push_back(Aux1.back());
        }
        Aux1.pop_back();
    }
    
    while(!Aux2.empty()){
        if(!Membro(Unida, Aux2.back())){
            Unida.push_back(Aux2.back());
        }
        Aux2.pop_back();
    }
    return Unida;
}

int main(){
    list<int> L1, L2, L3;
    
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(4);
    L1.push_back(6);   

    L2.push_back(2);
    L2.push_back(2);
    L2.push_back(7); 

    L3 = Uniao(L1, L2);

    while(!L3.empty()){
        cout << L3.front() << " ";
        L3.pop_front();
    }

    return 0;
}