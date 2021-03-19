#include "fcfs.h"
#include "sjf.h"
#include "psp.h"
#include "pcp.h"
#include "rrsp.h"
#include "rrcp.h"
#include "entrada.h"

int main(int argc, char const *argv[])
{
    vector<int> dados, dados1, dados2, dados3;
    Entrada teste("entrada1.txt");
    teste.imprimiArquivo();
    teste.retornaMatriz(dados);
    teste.retornaPrimeiraColuna(dados1);
    teste.retornaSegundaColuna(dados2);
    teste.retornaTerceiraColuna(dados3);

    return 0;
}
