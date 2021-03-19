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
    vector<Processo> P;
    for (int i = 0; i < dados.size(); i++)
    {
        Processo aux(dados[i + (3 * cont)], dados[i + (3 * cont) + 1], dados[i + (3 * cont) + 2]);
        P.push_back(aux);
        cont++;
    }

    return 0;
}
