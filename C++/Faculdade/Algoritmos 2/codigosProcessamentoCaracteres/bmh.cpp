#include<iostream>
#include <bitset>
#define MAXCHAR 255
using namespace std;


void BMH(string T, int n, string P, int m)
{
    cout<<"Texto: "<<T<<" Tam: "<<n<<endl;
    cout<<"Padrao: "<<P<<" Tam: "<<m<<endl;
    int i,j,k,d[MAXCHAR];
    for(i=0;i<MAXCHAR;i++)
        d[i]=m;
    for(i=1;i<m;i++)
        d[P[i-1]]= m-i;

    cout<<"\nTabela d\n";
    for(i=0;i<MAXCHAR;i++)
    {
        cout<<char(i)<<" "<<d[i]<<endl;
    }

    cout<<"\nIniciando a busca pelo padrao no texto.\n";
    i=m;
    while(i<=n)
    {
        k=i;
        j=m;
        while(T[k-1]==P[j-1]&&j>0)
        {
            cout<<T[k-1]<<" == "<<P[j-1]<<endl;
            k--;
            j--;
        }

        if(j==0)
            cout<<"Casamento na posicao "<<k+1<<endl;
        else
            cout<<T[k-1]<<" <> "<<P[j-1]<<endl;
        cout<<endl;

        i+=d[T[i-1]];
    }
}

int main()
{
    string T="ctctactatagtagtagtac";
    string P="gtag";
    int m=P.size(),n=T.size();
    BMH(T, n, P, m);
    return 0;
}
