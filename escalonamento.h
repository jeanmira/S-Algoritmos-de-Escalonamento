#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include <string>
#include "entrada.h"
class Escalonamento
{
private:
    vector<int> criacao;
    vector<int> duracao;
    vector<int> prioridade;

public:
    Escalonamento(string caminho); // Construtor padrão
    ~Escalonamento();              // Destrutor padrão
};

#endif