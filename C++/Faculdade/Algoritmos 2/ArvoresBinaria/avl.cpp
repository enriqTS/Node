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

typedef long tipoChave;

typedef struct tipoRegistro
{
    tipoChave chave;
    /* outros componentes */
} tipoRegistro;

typedef struct tipoNo * tipoApontador;

typedef struct tipoNo
{
    tipoRegistro reg;
    tipoApontador esq, dir;
    int altura, fator;
} tipoNo;


void inicializa(tipoApontador &raiz)
{
    raiz = NULL;
}

int maior(int a, int b)
{
    if(a>b)
        return a;
    return b;
}


void atualizaNo(tipoApontador p)
{
    int e=0,d=0;
    if(p==NULL)
        return;
    if(p->esq!=NULL)
        e=p->esq->altura;
    if(p->dir!=NULL)
        d=p->dir->altura;
    p->altura=maior(e,d)+1;
    p->fator=d-e;
}

void rotacaoDir(tipoApontador &p)
{
    tipoApontador aux;
    aux=p;
    p=p->esq;
    aux->esq=p->dir;
    p->dir=aux;
    atualizaNo(aux);
    atualizaNo(p);
}

void rotacaoEsq(tipoApontador &p)
{
    tipoApontador aux;
    aux=p;
    p=p->dir;
    aux->dir=p->esq;
    p->esq=aux;
    atualizaNo(aux);
    atualizaNo(p);
}


void balancear(tipoApontador &p)
{
    if(p==NULL)
        return;

    if(p->fator!=2 && p->fator!=-2)
        return;

    if(p->fator==2)
    {
        if(p->dir->fator >= 0)
        {
            cout<<"\n\nRotacao Simples E\n\n ";
            rotacaoEsq(p);
        }
        else //rotacao dupla
        {
            cout<<"\n\nRotacao Dupla D-E\n\n ";
            rotacaoDir(p->dir);
            rotacaoEsq(p);
        }
    }
    if(p->fator==-2)
    {
        if(p->esq->fator <= 0)
        {
            cout<<"\n\nRotacao Simples D\n\n ";
            rotacaoDir(p);
        }
        else //rotacao dupla
        {
            cout<<"\n\nRotacao Dupla E-D\n\n ";
            rotacaoEsq(p->esq);
            rotacaoDir(p);
        }
    }
}

void insere(tipoRegistro x, tipoApontador &p)
{
    if (p == NULL)
    {
        p = new tipoNo;
        p->reg = x;
        p->esq = NULL;
        p->dir = NULL;
        p->altura=1;
        p->fator=0;
        return;
    }
    if (x.chave < p->reg.chave)
        insere(x, p->esq);
    else if (x.chave > p->reg.chave)
        insere(x, p->dir);
    else
        cout<< "Erro : Registro ja existe na arvore\n";

    atualizaNo(p); //atualiza a altura dos n�s

    balancear(p);
}

void antecessor(tipoApontador q, tipoApontador &r)
{
    if (r->dir != NULL)
    {
        antecessor(q, r->dir);
        return;
    }
    q->reg = r->reg;
    q = r;
    r = r->esq;
    delete(q);
}

void retira(tipoRegistro x, tipoApontador &p)
{
    tipoApontador Aux;
    if(p == NULL)
    {
        cout<<"Erro : Registro nao esta na arvore\n";
        return;
    }
    if(x.chave < p->reg.chave)
        retira(x, p->esq);
    else if(x.chave > p->reg.chave)
        retira(x, p->dir);
    else if(p->dir == NULL)
    {
        Aux = p;
        p = p->esq;
        delete(Aux);
    }
    else if(p->esq == NULL)
    {
        Aux = p;
        p = p->dir;
        delete (Aux);
    }
    else
        antecessor(p, p->esq);

    atualizaNo(p); //atualiza a altura dos n�s

    balancear(p);
}

void pesquisa(tipoRegistro &x, tipoApontador p)
{
    if(p == NULL)
    {
        cout<< "Erro: Registro nao esta presente na arvore\n";
        return;
    }
    if(x.chave < p->reg.chave)
    {
        pesquisa(x, p->esq);
        return;
    }
    if (x.chave > p->reg.chave)
        pesquisa(x, p->dir);
    else
        x = p->reg;
}

void imprimiNo(tipoApontador p, int x, int y, int tam)
{
    if (p == NULL)
        return;

    gotoxy(x,y);
    cout<<p->reg.chave;
    cout<<"["<<p->fator<<"]";

    int pos= tam/pow(2,y+1);
    imprimiNo(p->esq,x-pos,y+1,tam);
    imprimiNo(p->dir,x+pos,y+1,tam);
}

void imprime(tipoApontador p)
{
    int h,x,y,tam;
    system("cls");

    if(p==NULL)
    {
        cout<<"\n\nArvore vazia!!!\n\n";
        return;
    }
    h= p->altura;
    tam=pow(2,h)*3;
    x=tam/2;
    y=1;
    imprimiNo(p, x,  y, tam);

    gotoxy(2,20);
    system("pause");
}

int main()
{
    tipoApontador raiz;
    tipoRegistro x;
    inicializa(raiz);
    int op=1;
    while (op!=0)
    {
        cout<<"Menu\n";
        cout<<"1 - Inserir\n";
        cout<<"2 - Remover\n";
        cout<<"3 - Imprimir\n";
        cout<<"0 - Sair\n";
        cout<<"Digite uma opcao: ";
        cin>>op;
        switch(op)
        {
        case 1:
            cout<<"\n\nDigite a chave a inserir: ";
            cin>>x.chave;
            insere(x,raiz);
            break;
        case 2:
            cout<<"\n\nDigite a chave a remover: ";
            cin>>x.chave;
            retira(x,raiz);
            cout<<"\n\nRemovido : "<<x.chave<<"\n\n";
            break;
        case 3:
            imprime(raiz);
            break;
        case 0:
            break;
        }
    }

    return 0;
}
