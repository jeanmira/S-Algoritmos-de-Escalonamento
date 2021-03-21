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
            if (p[j].getId() < p[i].getId())
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
    cout << p.size() << endl;
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
    cout << p.size() << endl;
    p[0].setTempoEspera(0);
    p[0].setTempoTotal(p[0].getDuracao());
    int tempexectot = 0;
    for (int i = 1; i < p.size(); i++)
    {
        tempexectot += p[i - 1].getDuracao();
        p[i].setTempoEspera(tempexectot - p[i].getCriacao());
        p[i].setTempoTotal(p[i].getTempoEspera() + p[i].getDuracao());
    }
    cout << p.size() << endl;
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