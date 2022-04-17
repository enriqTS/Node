#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

char *tok;
char caractere[201];
ifstream ifs;
ofstream ofs;

float x[201];
float y[201];

void learquivo();
void trocavirgula();
void funcao();

int main()
{
    learquivo();
    trocavirgula();
    funcao();
    
    return 0;
}

void learquivo()
{
    ifs.open("arq03.txt");
    ofs.open("arq02.txt");
    if (ifs.is_open() && ofs.is_open())
    {
        while (ifs.good())
        {
            ifs.getline(caractere, 201);
            tok = strtok(caractere, "\t\n");
            ofs << tok << "\n";
        }
    }
    else
    {
        cout << "Erro: Os arquivos não podem ser abertos.\n";
    }

    ifs.close();
    ofs.close();
}

void trocavirgula()
{
    fstream fs("arq02.txt", fstream::in | fstream::out);
    if (fs.is_open())
    {
        while (fs.good())
        {
            if (fs.get() == ',')
            {
                fs.seekp((fs.tellp() - static_cast<streampos>(1)));
                fs.put('.');
                fs.seekp(fs.tellp());
            }
        }
        fs.close();
    }
    else
    {
        cout << "Erro: Os arquivos nao podem ser abertos." << '\n';
    }
}

void funcao()
{
    float num, num2, result;
    int cont = 0;
    fstream fs("arq02.txt", fstream::in);
    fstream fs2("arq_result.txt", fstream::out);
    if (fs.is_open())
    {
        while (fs.good())
        {
            fs.getline(caractere, 201);
            num = atof(caractere);
            if (cont < 201)
            {
                x[cont] = num;
                y[cont] = num;
                cont++;
            }
        }
        for (int i = 0; i < 201; i++)
        {
            for (int j = 0; j < 201; j++)
            {
                result = pow(x[i], 2) + pow(y[j], 2) - cos(18 * x[i]) - cos(18 * y[j]);
                fs2 << result << endl;
            }
        }
        fs.close();
    }
}
