#ifndef GRAFO_H

#define GRAFO_H

#include <vector>
#include "Aresta.h"

class Grafo
{
public:
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);
    void inserir_aresta(Aresta e);
    void remover_aresta(Aresta e);

    void imprime();

    bool eh_passeio(std::vector<int> vertices);
    bool eh_vizinho(int v1, int v2);
    bool eh_caminho(int v1, int v2, int marcado[], int chamadas);
    bool eh_conexo();

    void busca_profundidade(int v, std::vector<int> &marcado);
    void busca_largura(int v, int timeToLive);

private:
    std::vector<std::vector<int>> matriz_adj_;
    int num_vertices_;
    int num_arestas_;

    void imprimir_caminho(int v1, int v2, int chamadas);
};

#endif /* GRAFO_H */
