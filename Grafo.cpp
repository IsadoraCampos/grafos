#include "Grafo.h"
#include <iostream>
#include <vector>
#include <queue>

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

bool Grafo::eh_vizinho(int v1, int v2)
{
    if (matriz_adj_[v1][v2] != 0 || matriz_adj_[v2][v1] != 0)
    {
        return true;
    }

    return false;
}

bool Grafo::eh_passeio(vector<int> vertices)
{
    for (size_t i = 0; i < vertices.size() - 1; i++)
    {
        if (!eh_vizinho(vertices[i], vertices[i + 1]))
        {
            return false;
        }
    }

    return true;
}

bool Grafo::eh_caminho(int v1, int v2, int marcado[], int chamadas)
{
    imprimir_caminho(v1, v2, chamadas);

    if (v1 == v2)
    {
        return true;
    }

    marcado[v1] = 1;
    for (int u = 0; u < num_vertices_; u++)
    {
        if (eh_vizinho(v1, u))
        {
            if (marcado[u] == 0)
            {
                chamadas++;
                if (eh_caminho(u, v2, marcado, chamadas))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void Grafo::imprimir_caminho(int v1, int v2, int chamadas)
{
    for (int i = 0; i < chamadas; i++)
    {
        cout << "--";
    }

    cout << "eh_caminho(" << v1 << ", " << v2 << ")" << "\n";
}

void Grafo::busca_profundidade(int v, std::vector<int> &marcado)
{
    printf("%d\n", v);
    marcado[v] = 1;

    for (int u = 0; u < num_vertices_; u++)
    {
        if (eh_vizinho(v, u))
        {
            if (marcado[u] == 0)
            {
                printf("%d -> %d\n", v, u);
                busca_profundidade(u, marcado);
            }
        }
    }
}

bool Grafo::eh_conexo()
{
    std::vector<int> marcado(num_vertices_, 0);
    busca_profundidade(0, marcado);

    for (int i = 0; i < num_vertices_; i++)
    {
        if (marcado[i] == 0)
        {
            return false;
        }
    }

    return true;
}

std::vector<int> Grafo::busca_largura(int v, int timeToLive)
{
    queue<int> fila;
    std::vector<int> marcado(num_vertices_, 0);
    std::vector<int> pai(num_vertices_, -1);
    std::vector<int> distancia(num_vertices_, -1);
    std::vector<int> vetoresNaoVisitados;

    marcado[v] = 1;
    pai[v] = -1;
    distancia[v] = 0;
    fila.push(v);

    while (!fila.empty())
    {
        int w = fila.front();
        fila.pop();

        for (int u = 0; u < num_vertices_; u++)
        {
            if (eh_vizinho(w, u) && marcado[u] == 0)
            {
                if (timeToLive > 0) {
                    marcado[u] = 1;
                    pai[u] = w;
                    distancia[u] = distancia[w] + 1;
                    fila.push(u);
                    timeToLive--;
                } else {
                    vetoresNaoVisitados.push_back(u);
                }    
            }
        }
    }
    
    for (size_t i = 0; i < vetoresNaoVisitados.size(); i++) {
        printf("Vertices não visitados: %d\n", vetoresNaoVisitados[i]);
    }
    
    return vetoresNaoVisitados;
}
