#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices)
{
    if (num_vertices <= 0)
    {
        throw invalid_argument("Erro no construtor Grafo(int): o número de vértices " +
                               to_string(num_vertices) + " é inválido!");
    }

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        matriz_adj_[i].resize(num_vertices, 0);
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;
}

int Grafo::num_vertices()
{
    return num_vertices_;
}

int Grafo::num_arestas()
{
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e)
{
    if (matriz_adj_[e.v1][e.v2] != 0)
    {
        return true;
    }

    return false;
}

void Grafo::inserir_aresta(Aresta e)
{
    // Aresta já existe
    if (tem_aresta(e))
    {
        return;
    }

    // Laço na aresta
    if (e.v1 == e.v2)
    {
        return;
    }

    matriz_adj_[e.v1][e.v2] = 1;
    matriz_adj_[e.v2][e.v1] = 1;
    num_arestas_++;
}

void Grafo::remover_aresta(Aresta e)
{
    if (!tem_aresta(e))
    {
        return;
    }

    matriz_adj_[e.v1][e.v2] = 0;
    matriz_adj_[e.v2][e.v1] = 0;
    num_arestas_--;
}

void Grafo::imprime()
{
    cout << "Grafo: \n";
    for (int v = 0; v < num_vertices_; v++)
    {
        cout << v << ": ";
        for (int u = 0; u < num_vertices_; u++)
        {
            if (matriz_adj_[v][u] != 0)
            {
                cout << u << " ";
            }
        }
        cout << "\n";
    }
}