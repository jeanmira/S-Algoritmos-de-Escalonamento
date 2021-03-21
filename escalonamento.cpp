#include "escalonamento.h"

//----- Construtor padrão
Escalonamento::Escalonamento()
{
}

//----- Destrutor padrão
Escalonamento::~Escalonamento()
{
}

void Escalonamento::setParametros(Processo pn)
{
    p.push_back(pn);
}

void Escalonamento::imprimiDados()
{
    Processo aux(0, 0, 0, 0);
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].id() < p[i].id())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout << "Processo(" << i << "):" << endl;
        cout << "Tempo total transcorrido: " << p[i].getTempoTotal() << endl;
        cout << "Tempo médio de espera: " << p[i].getTempoEspera() << endl;
        cout << "Número de trocas: " << p[i].getnTroca() << endl;
    }
}

void Escalonamento::fcfs()
{
    Processo aux(0, 0, 0, 0);

    // Ordena a "fila" vetor de processos pela orde de criacao
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() < p[i].getCriacao())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    p[0].setTempoEspera(0);
    for (int i = 1; i < p.size(); i++)
    {
        p[i].setTempoEspera(p[i - 1].getDuracao() + p[i - 1].getTempoEspera());
        p[i].setTempoTotal(p[i].getTempoTotal());
        p[i].setTempoEspera(0);
        p[i].setTempoTotal(0);
    }

    /* // Inicia Simulacao
    for (int i = 0; i < p.size(); i++)
    {
        p[i].incrementaContexto();
        sleep(p[i].getDuracao());
    } */
}

void Escalonamento::sjf()
{
}

void Escalonamento::psp()
{
}

void Escalonamento::pcp()
{
}

void Escalonamento::rrsp()
{
}

void Escalonamento::rrcp()
{
}