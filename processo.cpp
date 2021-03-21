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
// Destrutor padrão
Processo::~Processo() {}

int Processo::getId(){
    return id;
}

int Processo::getCriacao()
{
    return this->criacao;
}

int Processo::getDuracao()
{
    return this->duracao;
}

int Processo::getPrioridade()
{
    return this->prioridade;
}

//----- Imprimi os dados dos processos
void Processo::imprimiProcesso()
{
    cout << "c: " << this->criacao << " - d: " << this->duracao << " - p: " << this->prioridade << endl;
}

int Processo::getTempoTotal()
{
    return tempoTotal;
}
int Processo::getTempoEspera()
{
    return tempoEspera;
}
int Processo::getnTroca()
{
    return nTroca;
}

void Processo::setTempoTotal(int tempoTotal)
{
    this->tempoTotal = tempoTotal;
}
void Processo::setTempoEspera(int tempoEspera)
{
    this->tempoEspera = tempoEspera;
}
void Processo::setnTroca(int nTroca)
{
    this->nTroca = nTroca;
}

void Processo::incrementaContexto()
{
    nTroca++;
}
