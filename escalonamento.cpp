#include "escalonamento.h"

//----- Construtor padrão
Escalonamento::Escalonamento()
{
}

//----- Destrutor padrão
Escalonamento::~Escalonamento()
{
}

// Cria os objetos e adiciona os parametros
void Escalonamento::setParametros(Processo pn)
{
    p.push_back(pn);
}

//----- Imprimi os dados dos processos
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
         << " Tempo    P1  P2  P3  P4" << endl;
    int aux2 = 0;

    for (int j = 0; j < p[0].getEstadoSize(); j++)
    {
        cout << " " << j << " - " << j + 1;
        if (j < 9)
            cout << "    ";
        else if (j == 9)
            cout << "   ";
        else
            cout << "  ";
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
    cout << endl;
}

//----- Escalonamento por FCFS (First Come, First Served)
void Escalonamento::fcfs()
{
    cout << "----- FCFS (First Come, First Served) -----" << endl;
    //----- Limpa os dados que sao compartilhados
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
    }

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

//----- Escalonamento por Shortest Job First
void Escalonamento::sjf()
{
    cout << "----- Shortest Job First -----" << endl;
    //----- Limpa os dados que sao compartilhados
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
    }

    int tempoTotal = 0;
    for (int i = 1; i < p.size(); i++)
    {
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

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
    //----- Ordena a "fila" vetor de processos pela ordem de criacao igual trocando as duracoes
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() == p[i].getCriacao() && p[j].getDuracao() < p[i].getDuracao())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    aux = p[0];
    int tempo_Atual = p[0].getDuracao();

    for (int i = 1; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (tempo_Atual >= p[i].getCriacao() && tempo_Atual >= p[j].getCriacao())
            {
                //cout << "A - " << i << " - " << j << endl;
                if (p[j].getDuracao() < p[i].getDuracao())
                {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                    //cout << "B - " << i << " - " << j << endl;
                }
            }
        }
        tempo_Atual += p[i].getDuracao();
    }

    /* for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].getCriacao() << p[i].getDuracao() << p[i].getPrioridade() << endl;
    } */

    //----- Lógica responsavel por calcular os tempos
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

    //----- Lógica responsavel por transformar os dados do tempo em um vetor para impressão
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

//----- Escalonamento por prioridade, sem preempção
void Escalonamento::psp()
{
    cout << "----- Por prioridade, sem preempção -----" << endl;
    //----- Limpa os dados que sao compartilhados
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
    }

    int tempoTotal = 0;
    for (int i = 1; i < p.size(); i++)
    {
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

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

    //----- Ordena a "fila" vetor de processos pela ordem de criacao igual trocando as prioridades
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() == p[i].getCriacao() && p[j].getPrioridade() > p[i].getPrioridade())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    // Ordena por ordem de prioridade baseado na criacao
    aux = p[0];
    int tempo_Atual = p[0].getDuracao();
    for (int i = 1; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (tempo_Atual >= p[i].getCriacao() && tempo_Atual >= p[j].getCriacao())
            {
                if (p[j].getPrioridade() > p[i].getPrioridade())
                {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
        tempo_Atual += p[i].getDuracao();
    }

    //----- Lógica responsavel por calcular os tempos
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

    //----- Lógica responsavel por transformar os dados do tempo em um vetor para impressão
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

//----- Escalonamento por prioridade, com preempção por prioridade
void Escalonamento::pcp()
{
    cout << "----- Por prioridade, com preempção por prioridade -----" << endl;
    //----- Limpa os dados que sao compartilhados e calcula tempo maximo
    int tempoTotal = 0;
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

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

    //----- Ordena a "fila" vetor de processos pela ordem de criacao igual trocando as prioridades
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() == p[i].getCriacao() && p[j].getPrioridade() > p[i].getPrioridade())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    // Ordena por ordem de prioridade baseado na criacao
    aux = p[0];
    int tempo_Atual = p[0].getDuracao();
    for (int i = 1; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (tempo_Atual >= p[i].getCriacao() && tempo_Atual >= p[j].getCriacao())
            {
                if (p[j].getPrioridade() > p[i].getPrioridade())
                {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
        tempo_Atual += p[i].getDuracao();
    }

    vector<Processo> temp;
    temp.push_back(p[0]);
    vector<Processo> copia = p;
    int tempo_Aux = 0;
    aux = p[0];

    for (int tick = 0; tick < tempo_Atual; tick++)
    {
        for (int tack = 0; tack < p.size(); tack++)
        {
            if (copia[tack].getCriacao() <= tick)
            {
                if (aux.getPrioridade() < copia[tack].getPrioridade())
                {
                    temp.push_back(copia[tack]);
                    if (aux.getDuracao() != -1)
                    {
                        for (int k = 0; k < copia.size(); k++)
                        {
                            if (aux.getId() == copia[k].getId())
                            {
                                copia[k].diminuiTempo(tempo_Aux);
                                p[k].incrementaContexto(); // Aumenta troca de contexto
                            }
                        }
                    }
                    aux = copia[tack]; // Processo que esta no CPU
                    tempo_Aux = 0;
                }
                if (tempo_Aux == aux.getDuracao())
                {
                    tempo_Aux = 0;
                    for (int i = 0; i < copia.size(); i++)
                    {
                        if (aux.getId() == copia[i].getId())
                        {
                            copia[i].invalidaDados();
                            aux.invalidaDados();
                        }
                    }
                }
            }
        }

        for (int i = 0; i < p.size(); i++)
        {
            if (aux.getId() == p[i].getId())
            {
                p[i].addTempEmqExe(tick);
            }
        }

        tempo_Aux++;
    }

    for (int tick = 0; tick < tempo_Atual; tick++)
    {
        for (int tack = 0; tack < p.size(); tack++)
        {
            for (int i = 0; i < p[tack].getTempEmqExeSize(); i++)
            {
                if (p[tack].getTempEmqExe(i) == tick)
                {
                    p[tack].incrementaTotal();
                }
                else if (p[tack].getCriacao() >= tick && p[tack].verificaIntervalo(tick) != true)
                {
                    p[tack].incrementaEspera();
                    cout << "T[" << tick << "] P(" << p[tack].getId() << ") - " << p[tack].getTempoEspera() << endl;
                }
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].getId() << ": ";
        for (int j = 0; j < p[i].getTempEmqExeSize(); j++)
        {
            cout << p[i].getTempEmqExe(j) << " ";
        }
        cout << endl;
    }
    /* for (int i = 0; i < temp.size(); i++)
    {
        cout << " ";
        temp[i].imprimiProcesso();
    } */
}

//----- Escalonamento por Round-Robin com quantum = 2s, sem prioridade
void Escalonamento::rrsp()
{
}

//----- Escalonamento por Round-Robin com prioridade e envelhecimento (tq=2, α=1)
void Escalonamento::rrcp()
{
}