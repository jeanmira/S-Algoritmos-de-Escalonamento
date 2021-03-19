#include "escalonamento.h"

//----- Construtor padrão
Escalonamento::Escalonamento(string caminho)
{
    Entrada teste(caminho);

    teste.retornaPrimeiraColuna(criacao);
    teste.retornaSegundaColuna(duracao);
    teste.retornaTerceiraColuna(prioridade);
    cout << "c: ";
    for (int i = 0; i < criacao.size(); i++)
    {
        cout << criacao[i] << " ";
    }
    cout << "d: ";
    for (int i = 0; i < duracao.size(); i++)
    {
        cout << duracao[i] << " ";
    }
    cout << "p: ";
    for (int i = 0; i < prioridade.size(); i++)
    {
        cout << prioridade[i] << " ";
    }
}
//----- Destrutor padrão
Escalonamento::~Escalonamento() {}