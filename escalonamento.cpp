#include "escalonamento.h"

//----- Construtor padrão
Escalonamento::Escalonamento()
{
}

//----- Destrutor padrão
Escalonamento::~Escalonamento()
{
}

// Cria os objetos e adiciona os parâmetros
void Escalonamento::setParametros(Processo pn)
{
    p.push_back(pn);
}

//----- Verifica se é preemptivo
bool Escalonamento::verificaPreEmpetivo()
{
    int cont = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].verificaVazio() == true)
            cont++;
    }
    if (cont == p.size())
        return true;
    else
        return false;
}

//----- Imprime os dados dos processos
void Escalonamento::imprimiDados()
{
    // Se o código for preemptive calculamos os tempos com os gráficos para
    int tempoMax = 0, tempoEspera = 0;
    if (verificaPreEmpetivo())
    {
        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < p[0].getEstadoSize(); j++)
            {
                if (p[i].getEstado(j) == 2)
                    tempoEspera++;
                else if (p[i].getEstado(j) == 1)
                    tempoMax++;
            }
            p[i].setTempoEspera(tempoEspera);
            p[i].setTempoTotal(tempoMax + tempoEspera);
            tempoMax = 0;
            tempoEspera = 0;
        }
    }

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
    //----- Limpar os dados que são compartilhados
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
    }

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
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
    //----- Limpar os dados que são compartilhados
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
    // Ordena a "fila" vetor de processos pela ordem de criação
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
    //----- Ordena a "fila" vetor de processos pela ordem de criação igual trocando as durações
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

    //----- Lógica responsável por calcular os tempos
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

    //----- Lógica responsável por transformar os dados do tempo em um vetor para impressão
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
    //----- Limpar os dados que são compartilhados
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
    // Ordena a "fila" vetor de processos pela ordem de criação
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

    //----- Ordena a "fila" vetor de processos pela ordem de criação igual trocando as prioridades
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

    // Ordena por ordem de prioridade baseado na criação
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

    //----- Lógica responsável por calcular os tempos
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

    //----- Lógica responsável por transformar os dados do tempo em um vetor para impressão
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
    //----- Limpa os dados que são compartilhados e calcula tempo máximo
    int tempoTotal = 0;
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
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

    //----- Ordena a "fila" vetor de processos pela ordem de criação igual trocando as prioridades
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

    // Ordena por ordem de prioridade baseado na criação
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

    vector<Processo> copia = p;
    int tempo_Aux = 0;
    aux = p[0];

    for (int tick = 0; tick < tempo_Atual; tick++)
    {
        for (int tack = 0; tack < p.size(); tack++)
        {
            //Verifica se o vetor já foi criado
            if (copia[tack].getCriacao() <= tick)
            {
                //Maior prioridade
                if (aux.getPrioridade() < copia[tack].getPrioridade())
                {
                    // Verifica se o dado não foi invalidado
                    if (aux.getDuracao() != -1)
                    {
                        for (int k = 0; k < copia.size(); k++)
                        {
                            if (aux.getId() == copia[k].getId())
                            {
                                // Diminui um tempo que foi executado
                                copia[k].diminuiTempo(tempo_Aux);
                                p[k].incrementaContexto(); // Aumenta troca de contexto
                            }
                        }
                    }

                    aux = copia[tack]; // Processo que está no CPU
                    tempo_Aux = 0;
                }

                // Tempo de execução for igual ao tempo de duração
                if (tempo_Aux == aux.getDuracao())
                {
                    // Zera objeto que guarda o tempo de execução
                    tempo_Aux = 0;
                    for (int i = 0; i < copia.size(); i++)
                    {
                        // Compare aux(Processo que está no CPU) com a cópia
                        if (aux.getId() == copia[i].getId())
                        {
                            copia[i].invalidaDados(); // apaga os dados -1
                            aux.invalidaDados();      // apaga os dados -1
                        }
                    }
                }
            }
        }
        // Preenche o vetor de estados de acordo com o processo que está sendo executado no momento
        for (int i = 0; i < p.size(); i++)
        {

            if (aux.getId() == p[i].getId())
            {
                p[i].setEstado(1);
            }
            else if (p[i].getCriacao() <= tick && copia[i].getCriacao() != -1)
            {
                p[i].setEstado(2);
            }
            else
            {
                p[i].setEstado(0);
            }
        }

        tempo_Aux++;
    }
}

//----- Escalonamento por Round-Robin com quantum = 2s, sem prioridade
void Escalonamento::rrsp(int quantum)
{
    cout << "----- Escalonamento por Round-Robin com quantum = 2s, sem prioridade -----" << endl;
    int tempoTotal = 0;
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
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
    vector<Processo> temp = p;
    vector<Processo> arrumaPosExecucao = p;
    queue<Processo> copia;
    aux = p[0];

    int clock = 0;

    for (int tick = 0; tick < tempoTotal; tick++)
    {
        // Conforme o tempo passa coloca o processo dentro da fila
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].getCriacao() <= tick && temp[i].getCriacao() != -1)
            {
                copia.push(temp[i]);     // Adiciona na fila
                temp[i].invalidaDados(); // Mata o vetor temporário
            }
        }

        //Maior prioridade
        if (clock == quantum || copia.front().getDuracao() == clock)
        {
            copia.front().diminuiTempo(quantum); // Diminui o tempo do processo que está executando
            // Se o tempo do vetor que está na cópia estiver com tempo zerado apaga esse vetor para ele não entrar na análise novamente
            if (copia.front().getDuracao() <= 0)
            {
                for (int k = 0; k < p.size(); k++)
                {
                    if (aux.getId() == p[k].getId())
                    {
                        arrumaPosExecucao[k].invalidaDados();
                    }
                }
                copia.pop();         // Apaga o vetor
                aux = copia.front(); // Adiciona o próximo na CPU
            }
            // Se ele nao tiver com o tempo zerado incrementa um no contexto dele
            else
            {
                for (int k = 0; k < p.size(); k++)
                {
                    if (aux.getId() == p[k].getId())
                    {
                        p[k].incrementaContexto(); // Aumenta troca de contexto
                    }
                }
                copia.push(copia.front()); //Adiciona o primeiro no final da fila
                copia.pop();               // Apaga o primeiro
                aux = copia.front();       // Adiciona o novo primeiro a CPU
            }
            clock = 0; // Zera o clock
        }
        // Preenche o vetor de estados de acordo com o processo que está sendo executado no momento
        for (int i = 0; i < p.size(); i++)
        {

            if (aux.getId() == p[i].getId())
            {
                p[i].setEstado(1);
            }
            else if (p[i].getCriacao() <= tick && arrumaPosExecucao[i].getCriacao() != -1)
            {
                p[i].setEstado(2);
            }
            else
            {
                p[i].setEstado(0);
            }
        }
        clock++;
    }
}

//----- Escalonamento por Round-Robin com prioridade e envelhecimento (tq=2, α=1)
void Escalonamento::rrcp(int tq, int alpha)
{
    cout << "----- Escalonamento por Round-Robin com prioridade e envelhecimento (tq=2, α=1) -----" << endl;
    int tempoTotal = 0;
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
        p[i].setPrioridadeDinamica(p[i].getPrioridade());
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
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

    //----- Ordena a "fila" vetor de processos pela ordem de criação igual trocando as prioridades
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

    vector<Processo> copia;
    Processo aux2(0, 0, 0, 0);
    copia = p;
    int q = 0;

    for(int i=0; i<tempoTotal; i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            for (int k = j + 1; k < p.size(); k++)
            {
                if (p[j].getCriacao() <= i && p[k].getCriacao() <= i && copia[k].getDuracao() > 0 && (p[k].getPrioridadeDinamica() > p[j].getPrioridadeDinamica() || copia[j].getDuracao() <= 0 || q >= tq))
                {
                    if(j==0 && copia[j].getDuracao()>0)p[j].incrementaContexto();
                    aux = p[j];
                    aux2 = copia[j];
                    p[j] = p[k];
                    copia[j] = copia[k];
                    p[k] = aux;
                    copia[k] = aux2;
                    q=0;
                }   
            }
        }
        p[0].setPrioridadeDinamica(p[0].getPrioridade());   //Reiniciando prioridade        
        p[0].setEstado(1);                                  //Define estado do processo para impressao do diagrama
        copia[0].decrementaDuracao();                       //Decrementa duração da copia de vetor de processos
        q++;
        for (int y = 1; y < p.size(); y++)
        {
            if(copia[y].getDuracao()>0 && p[y].getCriacao()<=i)
            {
                if(q >= tq)p[y].incrementaDinamica(alpha);   //Envelhecendo Processo        
                p[y].setEstado(2);                //Define estado do processo para impressao do diagrama
            }
            else
            {
                p[y].setEstado(0);
            }
        }    
    }
}
