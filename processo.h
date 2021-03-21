#ifndef PROCESO_H
#define PROCESO_H

#include <vector>
#include <string>
#include "entrada.h"

class Processo
{
private:
    int id;
    int criacao;
    int duracao;
    int prioridade;
    int tempoTotal;
    int tempoEspera;
    int nTroca;

public:
    Processo(int c, int d, int p, int i); // Construtor padrão
    ~Processo();                          // Destrutor padrão
    int getCriacao();
    int getDuracao();
    int getPrioridade();
    int getTempoTotal();
    int getTempoEspera();
    int getnTroca();
    void setTempoTotal(int tempoTotal);
    void setTempoEspera(int tempoEspera);
    void setnTroca(int nTroca);
    void imprimiProcesso(); // Imprimi os dados dos processos
    void incrementaContexto();
};

#endif