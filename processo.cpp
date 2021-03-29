#include "processo.h"

// Construtor padrão
Processo::Processo(int c, int d, int p, int i)
{

    this->id = i;
    this->criacao = c;
    this->duracao = d;
    this->prioridade = p;
    this->tempoEspera = 0;
    this->tempoTotal = 0;
    this->nTroca = 0;
    this->prioridadeDinamica = prioridade;
}

//----- Construtor por cópia
Processo::Processo(const Processo &outro)
{

    this->id = outro.id;
    this->criacao = outro.criacao;
    this->duracao = outro.duracao;
    this->prioridade = outro.prioridade;
    this->tempoEspera = outro.tempoEspera;
    this->tempoTotal = outro.tempoTotal;
    this->nTroca = outro.nTroca;
    this->prioridadeDinamica = outro.prioridade;
}

//----- Destrutor padrão
Processo::~Processo()
{
}

//----- Retorna a identidade do processo
int Processo::getId()
{
    return id;
}

//----- Retorna o tempo de criação do processo
int Processo::getCriacao()
{
    return this->criacao;
}

//----- Retorna o tempo de duração do processo
int Processo::getDuracao()
{
    return this->duracao;
}

//----- Retorna a prioridade do processo
int Processo::getPrioridade()
{
    return this->prioridade;
}

//----- Imprime os dados dos processos
void Processo::imprimiProcesso()
{
    cout << "c: " << this->criacao << " - d: " << this->duracao << " - p: " << this->prioridade << endl;
}

//----- Retorna o tempo total (espera + execucao)
int Processo::getTempoTotal()
{
    return tempoTotal;
}

//----- Retorna o tempo de espera
int Processo::getTempoEspera()
{
    return tempoEspera;
}

//----- Retorna a quantidade de trocas de contexto
int Processo::getnTroca()
{
    return nTroca;
}

//----- Altera o tempo total (espera + execucao)
void Processo::setTempoTotal(int tempoTotal)
{
    this->tempoTotal = tempoTotal;
}

//----- Altera o tempo de espera
void Processo::setTempoEspera(int tempoEspera)
{
    this->tempoEspera = tempoEspera;
}

//----- Altera a quantidade de trocas de contexto
void Processo::setnTroca(int nTroca)
{
    this->nTroca = nTroca;
}

//----- Altera incrementando as trocas de contexto de um processo
void Processo::incrementaContexto()
{
    nTroca++;
}

//----- Altera o tempo inicial de execução
void Processo::setTempIni(int t)
{
    this->tempIni = t;
}

//----- Altera o tempo final de execução
void Processo::setTempFin(int t)
{
    this->tempFin = t;
}

//----- Retorna o tempo inicial de execução
int Processo::getTempIni()
{
    return this->tempIni;
}

//----- Retorna o tempo final de execução
int Processo::getTempFin()
{
    return this->tempFin;
}

//----- Altera o vetor que guarda todos os estados do processo durante execucao
void Processo::setEstado(int e)
{
    estado.push_back(e);
}

//----- Retorna o vetor que guarda todos os estados do processo durante execucao
int Processo::getEstado(int j)
{
    return this->estado[j];
}

//----- Retorna o tamanho do vetor do estado(vetor que guarda todos os estados do processo durante execucao)
int Processo::getEstadoSize()
{
    return this->estado.size();
}

//----- limpar os dados para a próxima análise de escalonamento
void Processo::limpaDados()
{
    estado.erase(estado.begin(), estado.end()); // Limpa o vetor que continha os estados
    this->tempoTotal = 0;                       // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempoEspera = 0;                      // Zera os dados para que outro escalonamento possa gerar seus dados
    this->nTroca = 0;                           // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempIni = 0;                          // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempFin = 0;                          // Zera os dados para que outro escalonamento possa gerar seus dados
}

//----- Invalida dados de cópias para análise
void Processo::invalidaDados()
{
    this->criacao = -1;
    this->duracao = -1;
    this->prioridade = -1;
    this->prioridadeDinamica = -1;
}

//----- Diminui o tempo quando interrompe a execução
void Processo::diminuiTempo(int qtd)
{
    this->duracao -= qtd;
}

//----- Se estiver vazio por se pre-empetivo preenche na impressão
bool Processo::verificaVazio()
{
    if (this->tempoTotal == 0 && this->tempoEspera == 0)
        return true;
    else
        return false;
}

//----- Incrementa no valor de alpha a prioridade dinâmica
void Processo::incrementaDinamica(int alpha)
{
    this->prioridadeDinamica = prioridadeDinamica + alpha;
}

//----- Retorna a prioridade dinâmica
int Processo::getPrioridadeDinamica()
{
    return this->prioridadeDinamica;
}

//----- Reinicia a prioridade dinâmica com a estática
void Processo::reiniciaPriDinamica()
{
    this->prioridadeDinamica = this->prioridade;
}

// Coloca o valor inicial na prioridade dinâmica
void Processo::setPrioridadeDinamica(int valor)
{
    this->prioridadeDinamica = valor;
}

void Processo::decrementaDuracao()
{
    this->duracao = this->duracao - 1;
}
