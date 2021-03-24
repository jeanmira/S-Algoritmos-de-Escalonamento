#ifndef PROCESO_H
#define PROCESO_H

#include <vector>
#include <string>
#include "entrada.h"

class Processo
{
private:
    int id;             // Identidade do p[rocesso
    int criacao;        // Tempo de criacao do processo
    int duracao;        // Tempo de duracao do processo
    int prioridade;     // Prioridade do processo
    int tempoTotal;     // Tempo total (espera + execucao)
    int tempoEspera;    // Tempo de espera
    int nTroca;         // Numero de trocas de contexto
    int tempIni;        // Tempo inicial de execucao do processo
    int tempFin;        // Tempo final de execucao do processo
    vector<int> estado; // Guarda todos os estados do processo durante execucao(inicio ate o fim)

public:
    Processo(int c, int d, int p, int i); // Construtor padrão
    Processo(const Processo &outro);      // Construtor por copia
    ~Processo();                          // Destrutor padrão
    int getId();                          // Retorna a identidade do processo
    int getCriacao();                     // Retorna o tempo de criacao do processo
    int getDuracao();                     // Retorna o tempo de duracao do processo
    int getPrioridade();                  // Retorna a prioridade do processo
    int getTempoTotal();                  // Retorna o tempo total (espera + execucao)
    int getTempoEspera();                 // Retorna o tempo de espera
    int getnTroca();                      // Retorna a quantidade de trocas de contexto
    int getTempIni();                     // Retorna o tempo inicial de execucao
    int getTempFin();                     // Retorna o tempo final de execucao
    int getEstadoSize();                  // Retorna o tamanho do vetor do estado(vetor que guarda todos os estados do processo durante execucao)
    int getEstado(int j);                 // Retorna o vetor que guarda todos os estados do processo durante execucao
    void setEstado(int e);                // Altera o vetor que guarda todos os estados do processo durante execucao
    void setTempoTotal(int tempoTotal);   // Altera o tempo total (espera + execucao)
    void setTempoEspera(int tempoEspera); // Altera o tempo de espera
    void setTempIni(int t);               // Altera o tempo inicial de execucao
    void setTempFin(int t);               // Altera o tempo final de execucao
    void setnTroca(int nTroca);           // Altera a quantidade de trocas de contexto
    void imprimiProcesso();               // Imprimi os dados dos processos
    void incrementaContexto();            // Altera incrementando as trocas de contextom de um processo
    void limpaDados();                    // limpa os dados para a proxima analise de escalonamento
};

#endif