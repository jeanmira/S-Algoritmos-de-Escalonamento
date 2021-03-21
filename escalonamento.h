#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>
#include "processo.h"
#include "entrada.h"

class Escalonamento
{
private:
    vector<Processo> p;

public:
    Escalonamento();  // Construtor padrão
    ~Escalonamento(); // Destrutor padrão
    void setParametros(Processo pn);
    void imprimiDados();
    void fcfs();
    void sjf();
    void psp();
    void pcp();
    void rrsp();
    void rrcp();
};

#endif