#include <iostream>
#include <vector>
#include "Maquina.hpp"

using namespace std;

// Fun��o para verificar se h� transi��es duplicadas
int deterministica(vector<Transicao *> lista_transi)
{
    // Cria uma c�pia da lista_transi em auxiliar
    vector<Transicao*> auxiliar;
    auxiliar = lista_transi;

    // Verifica duplicatas comparando cada par de transi��es
    for(int i = 0; i < lista_transi.size(); i++)
    {
        for(int j = 0; j < lista_transi.size(); j++)
        {
            if(lista_transi[i]->getTransicao() == auxiliar[j]->getTransicao() &&
               lista_transi[i]->getLocal() == auxiliar[j]->getLocal())
            {
                // Retorna 1 se uma duplicata for encontrada
                return 1;
            }
        }
    }

    // Retorna 0 se n�o houver duplicatas
    return 0;
}

int main()
{
    // Vari�veis para armazenar dados de entrada
    int T, N, i, local, destino, Numfim, auxiliar, inicio = 0, aceita;
    string transicao, entrada_str;
    char *ponteiro;

    // Vetores para armazenar informa��es
    vector<char> lista_entrada;
    vector<Transicao *> lista_transi;
    vector<Transicao*> fim;

    // Entrada do n�mero de estados (N) e transi��es (T)
    cin >> N >> T;

    // Entrada das transi��es
    for (i = 0; i < T; i++)
    {
        cin >> local >> transicao >> destino;
        Transicao *trans = new Transicao(local, transicao, destino);
        lista_transi.push_back(trans);
    }

    // Entrada do n�mero de estados finais (Numfim) e estados finais (auxiliar)
    cin >> Numfim;
    for (int a = 0; a < Numfim; a++)
    {
        cin >> auxiliar;
        // Busca e adiciona transi��es correspondentes aos estados finais
        for(int i = 0; i < lista_transi.size(); i++)
        {
            if(lista_transi[i]->getDestino() == auxiliar)
            {
                fim.push_back(lista_transi[i]);
            }
        }
    }

    // Verifica se a m�quina de Turing � determin�stica
    int D = deterministica(lista_transi);

    // Cria��o da m�quina de Turing
    Turing *Maquina = new Turing(N, T, lista_transi, inicio, fim, D);

    // Entrada da string a ser processada
    cin >> entrada_str;

    // Preenche o vetor lista_entrada com os caracteres da string
    for (char b : entrada_str)
    {
        lista_entrada.push_back(b);
    }

    // Adiciona um caractere 'b' ao final da lista_entrada
    lista_entrada.push_back('b');

    // Inicializa o ponteiro para apontar para o in�cio da lista_entrada
    ponteiro = &lista_entrada[0];

    // Realiza o teste da m�quina de Turing
    int j = Maquina->test(lista_entrada, 0, ponteiro);

    // Exibe o resultado do teste
    if(j == 1)
    {
        cout << entrada_str << " aceita: ";
        // Imprime a configura��o atual da lista_entrada
        Maquina->Imprimir(lista_entrada);
        cout << endl;
    }
    else
    {
        cout << entrada_str << " rejeitada." << endl;
    }

    // Limpeza da lista de entrada e libera��o de mem�ria para objetos Transicao
    lista_entrada.clear();
    delete Maquina;

    // Aguarda um caractere antes de encerrar
    cin.get();
    return 0;
}
