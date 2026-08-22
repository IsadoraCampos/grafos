#include "Grafo.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        // int vertices;

        // cout << "Digite a quantidade de vértices para o Grafo: ";
        // cin >> vertices;

        Grafo g(6);
        Aresta e(1, 3);
        Aresta e2(3, 1);

        cout << "Tem aresta em (" << e.v1 << "," << e.v2 << "): " << g.tem_aresta(e) << "\n";
        g.inserir_aresta(e);
        cout << "Tem aresta em (" << e.v1 << "," << e.v2 << "): " << g.tem_aresta(e) << "\n";
        cout << "Tem aresta em (" << e2.v1 << "," << e2.v2 << "): " << g.tem_aresta(e2) << "\n";
        cout << "Tem aresta em (" << e.v1 << "," << e.v2 << "): " << g.tem_aresta(e) << "\n";
        cout << "Tem aresta em (" << e2.v1 << "," << e2.v2 << "): " << g.tem_aresta(e2) << "\n";
        g.imprime();
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
