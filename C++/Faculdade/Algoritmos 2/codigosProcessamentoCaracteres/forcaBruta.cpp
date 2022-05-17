#include<iostream>
#include <bitset>
#define MAXCHAR 26
using namespace std;

void ForcaBruta(string T, int n, string P, int m)
{  int i , j , k;
   for (i = 1; i <= (n -m + 1); i++)
   {
     k = i ; j = 1;
     while(T[k-1] == P[ j-1] && j <=m)
     {
        cout<<T[k-1]<<" == "<<P[j-1]<<endl;
        j ++; k++;
     }
     if(j>m)
        cout<<"Casamento na posicao "<<i<<endl;
     else
        cout<<T[k-1]<<" <> "<<P[j-1]<<endl;
    cout<<endl;
   }
}

int main()
{
    string T="ostestestesta";
    string P="teste";
    int m=P.size(),n=T.size();
    ForcaBruta(T, n, P, m);
    return 0;
}
