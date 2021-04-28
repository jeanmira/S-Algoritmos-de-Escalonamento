# **Simulação de Algoritmos de Escalonamento**

[![Generic badge](https://img.shields.io/badge/Status-Finalizado-<red>.svg)](https://shields.io/)

### Como executar o programa:
   • No ubuntu ou derivado abra o terminal, para uma melhor experiência expanda ao máximo a tela
   • Execute o comando: make all
   • Como primeiro parâmetro deve colocar o arquivo que deseja simular dentro do código na main.cpp (exemplo: entrada1.txt)
   • Após fornecer essa informação o programa irá executar.

### Objetivo:

O presente trabalho tem por objetivo escrever um programa para simular o escalonamento de um 
conjunto de processos/threads através do uso de algoritmos de escalonamento de processos conhecidos 
na literatura. O programa deve suportar os seguintes algoritmos de escalonamento de processos:

         • FCFS (First Come, First Served)
         • Shortest Job First
         • Por prioridade, sem preempção
         • Por prioridade, com preempção por prioridade
         • Round-Robin com quantum = 2s, sem prioridade
         • Round-Robin com prioridade e envelhecimento (tq=2, α=1)
