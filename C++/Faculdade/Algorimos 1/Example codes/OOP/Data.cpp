// Data.cpp

/* Tarefas:
 * 
 * 1) Implementar a sobrecarga para os operadores + e - (adição e subtração).
 * 2) Ver a necessidade de sobrecarregar o operador = (se sim, implementar - caso contrário, justifique).
 * 3) Sobrecarregar os operadore ++ e --. Eles devem incrementar/decrementar a data em um dia.
 *    Atenção para o caso de ultrapassar um mês.
 * */
  
#include <iostream>
#include <string.h>

using namespace std;
 
class Data {
  private:
     int dia, mes, ano;
     static int cont;
 public :
  Data();
  int Bissexto(){return (ano%4 == 0) && (ano%100) || (ano%400 == 0);}
  void InitData(int, int, int);  
  void PrintData();
  void PrintBissexto();
  void PrintDataExtenso();
  void PrintSigno();
};

int Data::cont = 0;

Data::Data(): dia(1), mes(1), ano(2020){}

void Data :: InitData(int dia, int mes, int ano){
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  cont++;
}

void Data::PrintData(){
   cout << dia << "/" << mes << "/" << ano << endl;
   cout << "Quantidade de datas " << cont<< endl;	
}

void Data::PrintDataExtenso(){
   char nome[13][10] = {"","Janeiro", "Fevereiro","Marco","Abril", 
	                    "Maio", "Junho", "Julho", "Agosto", "Setembro",
	                    "Outubro", "Novembro", "Dezembro"};
   cout << dia << " de " << nome[mes] << " de " << ano << endl;	
}

void Data::PrintSigno(){
	char nsigno[15][13] = {"","Capricórnio","Aquário", "Peixes", "Áries","Touro", "Gêmeos", "Câncer", "Leão", "Virgem", "Libra", "Escorpião", "Sagitário", "Capricórnio"};
     int  sig[] = {0, 20, 19, 20, 20, 20, 20, 21, 22, 22, 22, 21, 21};
     if(dia < sig[mes])
        cout << "Signo: " << nsigno[mes] << endl;
     else cout << "Signo: " << nsigno[mes+1] << endl;		                   
}

  
void Data::PrintBissexto(){
	if(Bissexto())
	  cout << "Ano bissexto." << endl;
	  else cout << "Ano nao bissexto." << endl;
}  
  
int main() {
    Data x, y, z;
    
    x.InitData(12,5,1972);
    y.InitData(1,11,1977);
    z.InitData(6,8,2015);
        
    x.PrintData();
    x.PrintBissexto();
    x.PrintDataExtenso();
    x.PrintSigno();
    
    y.PrintData();
    y.PrintBissexto();
    y.PrintDataExtenso();
    y.PrintSigno();
    
    z.PrintData();
    z.PrintBissexto();
    z.PrintDataExtenso();
    z.PrintSigno();
    
    Data w;
    w.PrintData();
    w.PrintBissexto();
    w.PrintDataExtenso();
    w.PrintSigno();

   
   
   
  return 0;
}
