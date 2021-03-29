#ifndef PROCESO_H
#define PROCESO_H

#include <vector>
#include <string>
#include "entrada.h"

class Processo
{
private:
    int id;                 // Identidade do p[rocesso
    int criacao;            // Tempo de criação do processo
    int duracao;            // Tempo de duração do processo
    int prioridade;         // Prioridade do processo
    int prioridadeDinamica; // Prioridade dinâmica
    int tempoTotal;         // Tempo total (espera + execucao)
    int tempoEspera;        // Tempo de espera
    int nTroca;             // Número de trocas de contexto
    int tempIni;            // Tempo inicial de execução do processo
    int tempFin;            // Tempo final de execução do processo
    vector<int> estado;     // Guarda todos os estados do processo durante execucao(início até o fim)

public:
    Processo(int c, int d, int p, int i);  // Construtor padrão
    Processo(const Processo &outro);       // Construtor por cópia
    ~Processo();                           // Destrutor padrão
    int getId();                           // Retorna a identidade do processo
    int getCriacao();                      // Retorna o tempo de criação do processo
    int getDuracao();                      // Retorna o tempo de duração do processo
    int getPrioridade();                   // Retorna a prioridade do processo
    int getTempoTotal();                   // Retorna o tempo total (espera + execucao)
    int getTempoEspera();                  // Retorna o tempo de espera
    int getnTroca();                       // Retorna a quantidade de trocas de contexto
    int getTempIni();                      // Retorna o tempo inicial de execução
    int getTempFin();                      // Retorna o tempo final de execução
    int getEstadoSize();                   // Retorna o tamanho do vetor do estado(vetor que guarda todos os estados do processo durante execucao)
    int getEstado(int j);                  // Retorna o vetor que guarda todos os estados do processo durante execucao
    void setEstado(int e);                 // Altera o vetor que guarda todos os estados do processo durante execucao
    void decrementaDuracao();              // Decrementa 1 da duração do processo
    void setTempoTotal(int tempoTotal);    // Altera o tempo total (espera + execucao)
    void setTempoEspera(int tempoEspera);  // Altera o tempo de espera
    void setTempIni(int t);                // Altera o tempo inicial de execução
    void setTempFin(int t);                // Altera o tempo final de execução
    void setnTroca(int nTroca);            // Altera a quantidade de trocas de contexto
    void imprimiProcesso();                // Imprime os dados dos processos
    void incrementaContexto();             // Altera incrementando as trocas de contexto de um processo
    void limpaDados();                     // limpa os dados para a próxima análise de escalonamento
    void invalidaDados();                  // Inválida dados de cópias para análise
    void diminuiTempo(int);                // Diminui o tempo quando interrompe a execução
    bool verificaVazio();                  // Se estiver vazio por se prempretivo preenche na impressão
    void incrementaDinamica(int alpha);    // Incrementa no valor de alpha a prioridade dinâmica
    int getPrioridadeDinamica();           // Retorna a prioridade dinâmica
    void reiniciaPriDinamica();            // Reinicia a prioridade dinâmica com a estática
    void setPrioridadeDinamica(int valor); // Coloca o valor inicial na prioridade dinâmica
};

#endif
