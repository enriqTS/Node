#include<iostream>
using namespace std;

class dados
{
    int chave;
    string nome;
public:
    dados()
    {
        chave=-1;
    }
    dados(int k, string n)
    {
        nome = n;
        chave=k;
    }
    friend ostream& operator<<(ostream &out, dados &t)
    {
        out<<" Chave: "<<t.chave;
        out<<" , Nome: "<<t.nome;
        return out;
    }
     friend istream& operator>>(istream &in, dados &t)
    {
        cout<<"\nDigite a chave (a mesma do mapa, neste exemplo): ";
        in>>t.chave;
        cout<<"Digite o nome: ";
        in>>t.nome;
        return in;
    }
    void setNome(string n)
    {
        nome=n;
    }
     void setChave(int c)
    {
        chave=c;
    }
    int getChave()
    {
        return chave;
    }
};

template <class K, class T>
class no
{
private:
    no<K,T> *prox;
    T reg;
    K chave;
public:
    no()
    {
        prox=NULL;
    }
    no(K c, T r)
    {
        chave=c;
        reg=r;
        prox=NULL;
    }
    void setProx(no<K,T> *p)
    {
        prox=p;
    }
    void setReg(T r)
    {
        reg=r;
    }
    void setChave(K c)
    {
        chave=c;
    }
    no<K,T>* getProx()
    {
        return prox;
    }
    T& getReg()
    {
        return reg;
    }
    K& getChave()
    {
        return chave;
    }
    void imprime()
    {
        cout<<"Chave no Mapa: [ "<<chave<<" ]"<<endl;
        cout<<"Objeto: [ "<<reg<<" ]"<<endl<<endl;
    }
};

template <class K, class T>
class mapa //implementado como uma lista encadeada
{
private:
    no<K,T> *ini, *fim;
public:
    mapa()
    {
        ini=NULL;
        fim=NULL;
    }
    bool vazia()
    {
        if(ini==fim && ini==NULL)
            return true;
        else
            return false;
    }
    pair<T&,bool> insere(K c, T r) //retorna uma pair com o registro e um bool (false, j� est� no mapa, true foi inserido)
    {
        no<K,T> *aux;
        aux=ini;
        while(aux!=NULL) //verifica se j� tem um registro com c
        {
            if(aux->getChave()==c) // se tiver retorna o registro da chave c
                {   return pair<T&,bool> (aux->getReg(),false);

                }
            aux=aux->getProx();
        }

        aux=new no<K,T>(c,r); //como n�o encontrou cria o no
        if(vazia())
        {
            ini=aux;
            fim=aux;
        }
        else
        {
            fim->setProx(aux);
            fim=aux;
        }
        return pair<T&,bool>(aux->getReg(),true);
    }

    void imprime()
    {
        no<K,T> *aux;
        aux=ini;
        cout<<"\nImpressao do Mapa:\n\n";
        if(vazia())
        {
            cout<<"Lista Vazia!!!"<<endl;
            return;
        }
        while(aux!=NULL)
        {
            aux->imprime();
            aux=aux->getProx();
        }
    }

    T& operator [](K m)
    {

        return insere(m,T()).first; //retorna o primeiro elemento do pair retornado pelo insere.

    }
};


int main()
{
    int op=1;
    mapa<int,dados> m;
    dados x;
    int chave;

    cout<<"\n==============================\n";
    cout<<"Digite a chave do Mapa: ";
    cin>>chave;
    cout<<"\nDigite a informacao do objeto:";
    cout<<"\n==============================\n";
    cin>>x;
    m.insere(chave,x);
    cout<<"\n==============================\n";
    cout<<"\nDigite a chave do Mapa:";
    cin>>chave;
    cout<<"\nDigite a informacao do objeto:";
    cout<<"\n==============================\n";
    cin>>x;
    m.insere(chave,x);

    cout<<"\nDigite o valor da chave do Mapa: ";
    cin>>chave;
    cout<<endl;

    x.setChave(chave);
    x.setNome("Rafael");
    m[chave]=x;

    x.setChave(23);
    x.setNome("Maria");
    m[x.getChave()]=x;

    m.imprime();

    return 0;
}

