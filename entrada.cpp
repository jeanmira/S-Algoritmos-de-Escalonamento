#include "entrada.h"

//----- Construtor padrão
Entrada::Entrada(string caminho)
{
    meuArquivo.open(caminho);
    this->nome = caminho;
    tamanhoArquivo();
}

//----- Destrutor padrão
Entrada::~Entrada()
{
    meuArquivo.close();
}

//----- Retorna o tamanho do arquivo
void Entrada::tamanhoArquivo()
{
    int lin = 0;

    if (meuArquivo.is_open())
    {
        string aux;
        while (getline(meuArquivo, aux))
        {
            lin++;
        }
    }
    else
    {
        cout << "Impossivel Abrir o Arquivo ( " << nome << " )!" << endl;
    }
    setPonteiro();

    this->linhas = lin;

    char caractere;
    while (meuArquivo >> noskipws >> caractere)
    {
        if (caractere != ' ' && caractere != '\n')
        {
            dadosCentral.push_back(caractere - 48); // Carácter - 48 (48 é o valor ASCII de 0)
        }
    }
    setPonteiro();
}

//----- Elimina e retorna o marcador para posição inicial do arquivo
void Entrada::setPonteiro()
{
    meuArquivo.clear();
    meuArquivo.seekg(0);
}

//----- Retorna o arquivo em forma de matriz
void Entrada::retornaMatriz(vector<int> &dados)
{
    char caractere;
    while (meuArquivo >> noskipws >> caractere)
    {
        if (caractere != ' ' && caractere != '\n')
        {
            dados.push_back(caractere - 48); // Carácter - 48 (48 é o valor ASCII de 0)
        }
    }
    setPonteiro();
}

//----- Retorna somente a primeira coluna do arquivo em forma de vetor
void Entrada::retornaPrimeiraColuna(vector<int> &dados)
{
    char caractere;
    int contador = 0;
    while (meuArquivo >> noskipws >> caractere)
    {
        if (caractere != ' ' && caractere != '\n' && contador == 0)
        {
            dados.push_back(caractere - 48); // Carácter - 48 (48 é o valor ASCII de 0)
        }
        contador++;
        if (contador == 3)
            contador = 0;
    }
    setPonteiro();
    /* cout << "Primeira coluna: ";
   imprimiDados(dados); */
}

//----- Retorna somente a segunda coluna do arquivo em forma de vetor
void Entrada::retornaSegundaColuna(vector<int> &dados)
{
    char caractere;
    int contador = 0;
    while (meuArquivo >> noskipws >> caractere)
    {
        if (caractere != ' ' && caractere != '\n' && contador == 2)
        {
            dados.push_back(caractere - 48); // Carácter - 48 (48 é o valor ASCII de 0)
        }
        contador++;
        if (contador == 3)
            contador = 0;
    }
    setPonteiro();
    /* cout << "Segunda coluna: ";
   imprimiDados(dados); */
}

//----- Retorna somente a terceira coluna do arquivo em forma de vetor
void Entrada::retornaTerceiraColuna(vector<int> &dados)
{
    char caractere;
    int contador = 0;
    while (meuArquivo >> noskipws >> caractere)
    {
        if (caractere != ' ' && caractere != '\n' && contador == 1)
        {
            dados.push_back(caractere - 48); // Carácter - 48 (48 é o valor ASCII de 0)
        }
        contador++;
        if (contador == 3)
            contador = 0;
    }
    setPonteiro();
    /* cout << "Terceira coluna: ";
   imprimiDados(dados); */
}

//----- Imprime os dados de um vetor
void Entrada::imprimiDados(vector<int> &dados)
{
    for (auto i : dados)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Imprime os dados do arquivo
void Entrada::imprimiArquivo()
{
    cout << "- - -" << endl;
    for (int i = 0; i < dadosCentral.size(); i++)
    {
        cout << dadosCentral[i] << " ";
        if (((i + 1) % 3) == 0)
            cout << endl;
    }
    cout << "- - -" << endl;
    cout << "N° de Processos: " << linhas;
    cout << endl;
    cout << endl;
}
