#ifndef PROCESO_H
#define PROCESO_H

#include <vector>
#include <string>
#include "entrada.h"

class Processo
{
private:
    int criacao;
    int duracao;
    int prioridade;

public:
    Processo(int c, int d, int p); // Construtor padrão
    ~Processo();                   // Destrutor padrão
};

#endif