#include <iostream>

using namespace std;

template<class TipoItem>
class No {
     private:
          No *esq, *dir;
          TipoItem item;
     public:
          No ();
          No (TipoItem x);
          No*& getEsq ();
          void setEsq (No *p);
          No*& getDir ();
          void setDir (No *p);
          TipoItem getItem ();
          void setItem (TipoItem x);
};

     template<class TipoItem>
     No <class TipoItem> :: No (){ 
          esq = NULL;
          dir = NULL;
     }

     template<class TipoItem>
     No <class TipoItem> :: No (TipoItem x){
          int = x;
          esq = NULL;
          dir = NULL;
     }

     template<class TipoItem>
     No <TipoItem>::No getEsq (){
          return esq;
     }

     template<class TipoItem>
     void No <class TipoItem> :: setEsq (No *p){
           esq = p;
     }

     template<class TipoItem>
     No <TipoItem> :: No getDir (){
          return dir;
     }

     template<class TipoItem>
     void No <class TipoItem> :: setDir (No *p){
          dir = p;
     }

     template<class TipoItem>
     TipoItem No<class TipoItem>  :: getItem (){
          return item;
     }

     template<class TipoItem>
     void No <class TipoItem> :: setItem (TipoItem x){
          item = x;
     }
int main (){
     return 0;
}

template <class TipoItem>
class ABP {
     private:
          No<TipoItem> *raiz;
          void insere(TipoItem x, No<TipoItem> * &p);
          void imprime(No<TipoItem> * &p);
          void apagaArvore(No<TipoItem> * &p);
          bool pesquisa(TipoItem &x, No<TipoItem> * p);
          void antecessor(No<TipoItem> * q, No<TipoItem> * &r);
          void retira(TipoItem &x, No<TipoItem> * &p);
     public:
          ABP();
          void insere(TipoItem x);
          void imprime();
          bool pesquisa(TipoItem &x);
          void retira(TipoItem &x);
          ~ABP();
};
          template <class TipoItem>
          ABP <class TipoItem> :: ABP(){
               raiz = NULL;
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: insere(TipoItem x){
               insere(x, raiz);
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: insere(TipoItem x, No<TipoItem> * &p){
               if(p == NULL){
                    p = new No<TipoItem>;
                    p->setItem(x);
                    cout << "Item "<< x <<"inserido na arvore " << endl;
                    return;
               }
               if(x < p->getItem()){
                    insere(x, p->getEsq());
                    return;
               }
               if(x < p->getItem()){
                    insere(x, p->getDir());
                    return;
               }
               cout << "Item ja esta na arvore" << endl;
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: imprime(){}

          template <class TipoItem>
          bool ABP <class TipoItem> :: pesquisa(TipoItem &x){
               if(p == NULL){
                    //cout << "Item "<<x<<" nao esta na arvore!" << endl;
                    return false;
               }
               if(x < p->getItem()){
                    return pesquisa(x, p->getEsq());
               }
               if(x > p->getItem()){
                    return pesquisa(x, p->getDir());
               }
               //cout << "Item encontrado!!!" << endl;
               x = p->getItem();
               return true;
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: retira(TipoItem &x){
               retira(x, raiz);
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: retira(TipoItem &x, No<TipoItem> *&p){
               No<TipoItem> *aux;
               if(p == NULL){
                    cout << "Item "<< x <<" nao esta na arvore!" << endl;
                    return;
               }
               if(x < p->getItem()){
                    retira(x, p->getEsq());
                    return;
               }
                    if(x < p->getItem()){
                    retira(x, p->getDir());
                    return;
               }
               if(p-> getDir() == NULL){
                    aux = p;
                    p = p->getEsq();
                    delete aux;
                    return;
               }
               if(p->getEsq() != NULL){
                    antecessor(p, p->getEsq());
               }
               aux = p;
               p = p->getDir();
               delete aux;
          }

          template <class TipoItem>
          ABP <class TipoItem> :: ~ABP(){
               apagaArvore(raiz);
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: apagaArvore(No<TipoItem> * &p){
               if(p == NULL)
                    return;
               apagaArvore(p->getEsq());
               apagaArvore(p->getDir());
               delete p;
          }

          template <class TipoItem>
          void ABP <class TipoItem> :: antecessor(No<TipoItem> *q, No<TipoItem> * &r){
               if(r->getDir() != NULL){
                    antecessor(q, r->getDir());
                    return;
               }
               q->setItem(r->getItem());
               q = r;
               r = r->getEsq();
               delete q;
          }