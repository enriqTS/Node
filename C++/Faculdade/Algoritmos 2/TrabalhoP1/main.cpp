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
        if(T[i] >=-128 && T[i] <= 0){
            if(T[i] >=-128 && T[i] <= -122 || T[i] >=-96 && T[i] <= -91){
                T[i] = 'a';
            }
            else if(T[i] >=-120 && T[i] <= -117 && T[i] >=-88 && T[i] <= -85){
                T[i] = 'e';
            }
            else if(T[i] >=204 && T[i] <= 207 && T[i] >=236 && T[i] <= 239){
                T[i] = 'i';
            }
            else if(T[i] >=210 && T[i] <= 242 && T[i] >=224 && T[i] <= 246){
                T[i] = 'o';
            }
            else if(T[i] == -89 && T[i] == -121){
                T[i] = 'c';
            }
        }
    }

    for(int i=0; i<m;i++){
        if(ispunct(T[i])){
            T[i] = ' ';
        }
    }

    for(int i=0; i<m; i++){
        if(!isprint(T[i]))
            T[i] = '\0';
    }
}

int main(){
    // char lowerc[MAXCHAR] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // char upperc[MAXCHAR] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string T = "AJGDSAYID!,.#@áÁÉéçÇ";

    char a = 'ë';
    int x = a;
    cout << x << endl;
    
    processingdata(T);
    cout << T << endl;

    return 0;
}