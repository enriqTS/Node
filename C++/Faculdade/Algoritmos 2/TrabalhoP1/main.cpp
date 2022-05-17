#include<iostream>
#include<cstring>
using namespace std;
#define MAXCHAR 26

void processingdata(string &T){
    int m = T.size();
    int chartoascii;
    
    for(int i = 0; i < m; i++){
        if(T[i] >= 65 && T[i] <= 90){
            T[i] = tolower(T[i]);
        }
    }    
    for(int i=0; i<=m;i++){
        if(!isprint(T[i])){
            if(T[i] >=192 && T[i] <= 198 || T[i] >=224 && T[i] <= 230){
                chartoascii = T[i];
                chartoascii = 97;
                T[i] = chartoascii;
            }
            if(T[i] >=200 && T[i] <= 203 && T[i] >=232 && T[i] <= 235){
                T[i] = 'e';
            }
            if(T[i] >=204 && T[i] <= 207 && T[i] >=236 && T[i] <= 239){
                T[i] = 'i';
            }
            if(T[i] >=210 && T[i] <= 242 && T[i] >=224 && T[i] <= 246){
                T[i] = 'o';
            }
            if(T[i] == 199 && T[i] == 231){
                T[i] = 'c';
            }
        }
    }

    for(int i=0; i<m;i++){
        if(ispunct(T[i])){
            T[i] = ' ';
        }
    }
}

int main(){
    // char lowerc[MAXCHAR] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // char upperc[MAXCHAR] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string T = "AJGDSAYID!,.#@áÁÉé";
    
    processingdata(T);
    cout << T << endl;

    return 0;
}