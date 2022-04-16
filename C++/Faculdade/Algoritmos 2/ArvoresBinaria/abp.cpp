#include<iostream>
#include<windows.h> //para a fun��o gotoxy
#include<cstdio> //para o comando system
#include<cmath>
using namespace std;

void gotoxy(int x, int y)   //posicionar cursor na tela
{
    COORD coord;
    coord.X = x-1;
    coord.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(coord));
    // {
    //     x-1,y-1
    // });
}


template <class TipoItem>
class No
{
    private:
        No *esq, *dir;
        TipoItem item;

    public:
        No()
        {
            esq=NULL;
            dir=NULL;            
        }
        No(TipoItem x)
        {
            item=x;
            esq=NULL;
            dir=NULL;
        }
        
        No*& getEsq()
        {
            return esq;
        }
        void setEsq(No *p)
        {
            esq=p;
        }
        
        No*& getDir()
        {
            return dir;
        }
        void setDir(No *p)
        {
            dir=p;
        }
        TipoItem getItem()
        {
            return item;
        }
        void setItem(TipoItem x)
        {
            item=x;
        }
};

template <class TipoItem>
class ABP
{
    private:
        No<TipoItem> *raiz;
        void insere(TipoItem x, No<TipoItem> * &p)
        {
            TipoItem aux;
            if(p==NULL)
            {
                p = new No<TipoItem>;
                p->setItem(x);
                cout<<"Item "<<x<<" inserido na arvore"<<endl;
                return;
            }
            aux=p->getItem();
            if(x<aux)
            {
                insere(x,p->getEsq());
                return;
            }
            if(x>aux)
            {
                insere(x,p->getDir());
                return;
            }
            cout<<"Item ja esta na arvore"<<endl;
        }

        void imprime(No<TipoItem> * &p)  //percorre a árvore in-ordem
        {
            if(p==NULL)
                return;
            imprime(p->getEsq());
            cout<<p->getItem()<<endl;
            imprime(p->getDir());
        }
        
        void apagaArvore(No<TipoItem> * &p)
        {
            if(p==NULL)
                return;
            apagaArvore(p->getEsq());
            apagaArvore(p->getDir());
            delete p;
        }

        bool pesquisa(TipoItem &x, No<TipoItem> * &p)
        {
            TipoItem aux;
            if(p==NULL)
            {
                //cout<<"Item "<<x<<" nao esta na arvore!"<<endl;
                return false;
            }
            aux=p->getItem();
            if(x<aux)
            {
                return pesquisa(x,p->getEsq());
                
            }
            if(x>aux)
            {
                return pesquisa(x,p->getDir());
                
            }
            //cout<<"Item encontrado!!!"<<endl;
            x=aux;
            return true;
        }

       
        void antecessor(No<TipoItem> * q,No<TipoItem> * &r) //utilizado pele método retira
        {
            if(r->getDir()!=NULL)
            {
                antecessor(q,r->getDir());
                return;
            }
            q->setItem(r->getItem());
            q=r;
            r=r->getEsq();
            delete q;
        }

        void retira(TipoItem &x, No<TipoItem> * &p)
        {
            No<TipoItem> *aux;
            if(p==NULL)
            {
                cout<<"Item "<<x<<" nao esta na arvore!"<<endl;
                return;
            }
            if(x<p->getItem())
            {
                retira(x,p->getEsq());
                return;                
            }
            if(x>p->getItem())
            {
                retira(x,p->getDir());
                return;                
            }
            if(p->getDir()==NULL)
            {
                aux=p;
                p=p->getEsq();
                delete aux;
                return;
            }
            if(p->getEsq()!=NULL)
            {
                antecessor(p,p->getEsq());
                return;
            }
            aux=p;
            p=p->getDir();
            delete aux;
        }
       

        int altura(No<TipoItem> * &p, int h) //calcula a altura da árvore
        {
            int h_esq, h_dir;
            if(p==NULL)
                return h;
            h_esq=altura(p->getEsq(),h+1);
            h_dir=altura(p->getDir(),h+1);
            if(h_esq>=h_dir)
                return h_esq;
            else
                return h_dir;
        }
        
        void imprimiNo(No<TipoItem> * &p, int x, int y, int tam) //usado para imprimir a árvore no formato de árvore
        {
            if (p == NULL)
                return;

            gotoxy(x,y);
            cout<<p->getItem();
            
            int pos= tam/pow(2,y+1);
            imprimiNo(p->getEsq(),x-pos,y+1,tam);
            imprimiNo(p->getDir(),x+pos,y+1,tam);
        }

        
        
        
    public:
        ABP()
        {
            raiz = NULL;
        }
        void insere(TipoItem x)
        {
            insere(x, raiz);
        }
        void imprime()
        {
            imprime(raiz);            
        }
        bool pesquisa(TipoItem &x)
        {
            return pesquisa(x, raiz);
        }

        void retira(TipoItem &x)
        {
            retira(x, raiz);
        }
        
        void imprimeArvore() //imprimir a árvore no formato de árvore
        {
            int h,x,y,tam;
            system("cls");

            if(raiz==NULL)
            {
                cout<<"\n\nArvore vazia!!!\n\n";
                return;
            }
            h= altura(raiz,0);
            tam=pow(2,h)*3;
            x=tam/2;
            y=1;
            imprimiNo(raiz, x,  y, tam);

            gotoxy(2,20);
            system("pause");
        }
       
       ~ABP()
       {
          apagaArvore(raiz);
       }
};

int main()
{
    int op=1;
    ABP<int> a; //lista de inteiros com MAXTAM=15
    //Lista<Pessoa,5> l; //lista de Pessoa com MAXTAM=5
    int x;
    //Pessoa x;
    
    
    while(op!=0)
    {
        cout<<"\n\n  Menu de opcoes"<<endl;
        cout<<"=================="<<endl;
        cout<<"1 - Insere na arvore"<<endl;
        cout<<"2 - Retira da arvore"<<endl;
        cout<<"3 - Pesquisa na arvore"<<endl;
        cout<<"4 - Imprime os dados da arvore"<<endl;
        cout<<"5 - Imprime a arvore no formato de arvore"<<endl;
        cout<<"0 - Sair"<<endl;
        cout<<"Digite uma opcao: ";
        cin>>op;
        cout<<endl;
        switch(op)
        {
           case 1:
                cout<<"Entre com o item: "<<endl;
                cin>>x;
                a.insere(x);
                break;
            
            case 2:
                cout<<"Entre com o item: "<<endl;
                cin>>x;
                a.retira(x);
                break;
            
            case 3:
                cout<<"Entre com o item: "<<endl;
                cin>>x;
                if(a.pesquisa(x))
                    cout<<"O item "<<x<<" esta na arvore."<<endl;
                else
                    cout<<"O item "<<x<<" nao esta na arvore."<<endl;
                break;
            
            
            case 4:
                a.imprime();
                break;

            case 5:
                a.imprimeArvore();
                break;
            
            case 0:
                break;
            
            default:
                cout<<"Opcao invalida!!!"<<endl;
        }
    }
}
