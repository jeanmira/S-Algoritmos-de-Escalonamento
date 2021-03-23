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
    int tempIni;
    int tempFin;
    vector<int> estado;

public:
    Processo(int c, int d, int p, int i); // Construtor padrão
    ~Processo();                          // Destrutor padrão
    int getId();
    int getCriacao();
    int getDuracao();
    int getPrioridade();
    int getTempoTotal();
    int getTempoEspera();
    int getnTroca();
    int getTempIni();
    int getTempFin();
    int getEstadoSize();
    int getEstado(int j);
    void setEstado(int e);
    void setTempoTotal(int tempoTotal);
    void setTempoEspera(int tempoEspera);
    void setTempIni(int t);
    void setTempFin(int t);
    void setnTroca(int nTroca);
    void imprimiProcesso(); // Imprimi os dados dos processos
    void incrementaContexto();
    void limpaDados();
};

#endif