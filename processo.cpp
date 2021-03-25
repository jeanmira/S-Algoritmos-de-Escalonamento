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
}

//----- Construtor por copia
Processo::Processo(const Processo &outro)
{

    this->id = outro.id;
    this->criacao = outro.criacao;
    this->duracao = outro.duracao;
    this->prioridade = outro.prioridade;
    this->tempoEspera = outro.tempoEspera;
    this->tempoTotal = outro.tempoTotal;
    this->nTroca = outro.nTroca;
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

//----- Retorna o tempo de criacao do processo
int Processo::getCriacao()
{
    return this->criacao;
}

//----- Retorna o tempo de duracao do processo
int Processo::getDuracao()
{
    return this->duracao;
}

//----- Retorna a prioridade do processo
int Processo::getPrioridade()
{
    return this->prioridade;
}

//----- Imprimi os dados dos processos
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

//----- Altera incrementando as trocas de contextom de um processo
void Processo::incrementaContexto()
{
    nTroca++;
}

//----- Altera o tempo inicial de execucao
void Processo::setTempIni(int t)
{
    this->tempIni = t;
}

//----- Altera o tempo final de execucao
void Processo::setTempFin(int t)
{
    this->tempFin = t;
}

//----- Retorna o tempo inicial de execucao
int Processo::getTempIni()
{
    return this->tempIni;
}

//----- Retorna o tempo final de execucao
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

//----- limpa os dados para a proxima analise de escalonamento
void Processo::limpaDados()
{
    estado.erase(estado.begin(), estado.end()); // Limpa o vetor que continha os estados
    this->tempoTotal = 0;                       // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempoEspera = 0;                      // Zera os dados para que outro escalonamento possa gerar seus dados
    this->nTroca = 0;                           // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempIni = 0;                          // Zera os dados para que outro escalonamento possa gerar seus dados
    this->tempFin = 0;                          // Zera os dados para que outro escalonamento possa gerar seus dados
}

void Processo::invalidaDados()
{
    this->criacao = -1;
    this->duracao = -1;
    this->prioridade = -1;
}

void Processo::diminuiTempo(int qtd)
{
    this->duracao -= qtd;
}
bool Processo::verificaVazio()
{
    if (this->tempoTotal == 0 && this->tempoEspera == 0)
        return true;
    else
        return false;
}
