#include <iostream>
#include <vector>

#include "escalonamento.h"
#include "entrada.h"
#include "processo.h"

int main()
{
    vector<int> dados;
    int cont = 0;
    Entrada arquivo("entrada1.txt");
    arquivo.retornaMatriz(dados);
    //arquivo.imprimiDados(dados);
    Escalonamento e;

    for (int i = 0; i < dados.size() / 3; i++)
    {
        Processo aux(dados[i + (2 * cont)], dados[i + (2 * cont) + 1], dados[i + (2 * cont) + 2], i + 1);
        e.setParametros(aux);
        cont++;
    }

    e.fcfs();
    e.imprimiDados();

    return 0;
}
