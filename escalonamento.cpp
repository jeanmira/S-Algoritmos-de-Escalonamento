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
        cout << "Processo(" << i + 1 << "):" << endl;
        cout << "Tempo total transcorrido: " << p[i].getTempoTotal() << endl;
        cout << "Tempo médio de espera: " << p[i].getTempoEspera() << endl;
        cout << "Número de trocas: " << p[i].getnTroca() << endl;
    }
    cout << endl
         << " Tempo  P1  P2  P3  P4" << endl;
    int aux2 = 0;

    for (int j = 0; j < p[0].getEstadoSize(); j++)
    {
        cout << " " << j << " - " << j + 1;
        if (j < 9)
            cout << "  ";
        else if (j == 9)
            cout << " ";
        else
            cout << "";
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i].getEstado(j) == 1)
                cout << "##"
                     << "  ";
            else if (p[i].getEstado(j) == 2)
                cout << "--"
                     << "  ";
            else
                cout << "  "
                     << "  ";
        }
        cout << endl;
    }
}

void Escalonamento::fcfs()
{
    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criacao
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
    p[0].setTempoTotal(p[0].getDuracao());
    p[0].setTempIni(0);
    p[0].setTempFin(p[0].getDuracao());
    int tempexectot = 0;
    for (int i = 1; i < p.size(); i++)
    {
        tempexectot += p[i - 1].getDuracao();
        p[i].setTempIni(tempexectot);
        p[i].setTempFin(tempexectot + p[i].getDuracao());
        p[i].setTempoEspera(tempexectot - p[i].getCriacao());
        p[i].setTempoTotal(p[i].getTempoEspera() + p[i].getDuracao());
    }

    tempexectot += p[p.size() - 1].getDuracao();
    //---------------------------------------------------
    for (int i = 0; i < p.size(); i++)
    {
        // 0 = ' ', 1 = ##, 2 = --
        for (int j = 0; j < tempexectot; j++)
        {
            if (j < p[i].getCriacao() || j >= p[i].getTempFin())
                p[i].setEstado(0);
            else if (j < p[i].getTempFin() && j >= p[i].getTempIni())
                p[i].setEstado(1);
            else
            {
                p[i].setEstado(2);
            }
        }
    }
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