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
    // arquivo.imprimiArquivo();
    Escalonamento e;

    // Cria os processos
    for (int i = 0; i < dados.size() / 3; i++)
    {
        Processo aux(dados[i + (2 * cont)], dados[i + (2 * cont) + 1], dados[i + (2 * cont) + 2], i + 1);
        e.setParametros(aux);
        cont++;
    }

    // Escalonamento por FCFS (First Come, First Served)
    e.fcfs();
    e.imprimiDados();

    // Escalonamento por Shortest Job First
    e.sjf();
    e.imprimiDados();

    // Escalonamento por prioridade, sem preempção
    e.psp();
    e.imprimiDados();

    // Escalonamento por prioridade, com preempção por prioridade
    e.pcp();
    e.imprimiDados();

    //----- Escalonamento por Round-Robin com quantum = 2s, sem prioridade
    e.rrsp(2);
    e.imprimiDados();

    //----- Escalonamento por Round-Robin com prioridade e envelhecimento (tq=2, α=1)
    e.rrcp(2, 1);
    e.imprimiDados();

    return 0;
}
