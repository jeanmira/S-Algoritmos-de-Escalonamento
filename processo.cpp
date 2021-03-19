#include "processo.h"

// Construtor padrão
Processo::Processo(int c, int d, int p)
{
    this->criacao = c;
    this->duracao = d;
    this->prioridade = p;
}
// Destrutor padrão
Processo::~Processo() {}