// Definição da classe Matriz
#ifndef MATRIZ_H
#define MATRIZ_H
class Matriz
{
private: // atributos
    int linhas, colunas;
    int *matriz;

public:
    Matriz(int linha, int coluna); // construtor
    ~Matriz();                     // destrutor
    void insere(int elemento);     // insere dados na matriz
    void mostra();                 // exibe o conteúdo da matriz
    int soma_diagonal();           //retorna a soma da diagonal principal
    int maximo();                  // retorna o maior valor da matriz
    friend Matriz operator+(Matriz &m1, Matriz &m2);
    inline Matriz& operator = (Matriz );
};
#endif