#include "Grafo.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    try
    {
        int num_vertices;
        int num_arestas;
        int qtd_casos;
        vector<int> verticesEntrada;
        vector<int> timeToLive;

        cin >> num_vertices >> num_arestas;
        Grafo g(num_vertices);

        for (int i = 0; i < num_arestas; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            g.inserir_aresta(Aresta(v1, v2));
        }

        cin >> qtd_casos;
        for (int i = 0; i < qtd_casos; i++)
        {
            int v, ttl;
            cin >> v >> ttl;

            verticesEntrada.push_back(v);
            timeToLive.push_back(ttl);
        }

        for (int i = 0; i < qtd_casos; i++)
        {
            int v = verticesEntrada[i];
            int ttl = timeToLive[i];

            vector<int> vertices = g.nao_recebem_mensagem(v, ttl);

            cout << v << " " << ttl << ":";

            for (size_t j = 0; j < vertices.size(); j++)
            {
                cout << " " << vertices[j];
            }

            cout << "\n";
        }
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
