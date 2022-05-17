#include<iostream>
#include <bitset>
#define MAXCHAR 26
using namespace std;


void ShiftAnd(string T, int n, string P, int m)
{
    cout<<"Texto: "<<T<<" Tam: "<<n<<endl;
    cout<<"Padrao: "<<P<<" Tam: "<<m<<endl;
    int Masc[MAXCHAR], i, R=0;
    for(i=0;i<MAXCHAR;i++)
        Masc[i]=0;
    for(i=1;i<=m;i++)
        Masc[P[i-1]-'a']|=1 << (m-i);
    cout<<"\nTabela M\n";
    for(i=0;i<MAXCHAR;i++)
    {
        cout<<char(i+'a')<<" "<<bitset<5>(Masc[i])<<endl;
    }

    cout<<"\nIniciando a busca pelo padrao no texto.\n";
    cout<<"R = " <<bitset<5>(R)<<endl;
    for(i=0; i<n; i++)
    {
        R=((R>>1)| (1<<(m-1)))& Masc[T[i]-'a'];
        cout<<"T["<<i+1<<"]: "<<T[i]<<" R = " <<bitset<5>(R)<<endl;
        if((R&1)!=0)
            cout<<"Casamento na posicao "<<i-m+2<<endl;
    }
}

int main()
{
    string T="ostestestesta";
    string P="teste";
    int m=P.size(),n=T.size();
    ShiftAnd(T, n, P, m);
    return 0;
}
