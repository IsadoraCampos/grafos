#include "Grafo.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Grafo g(6);
        Aresta a1(0, 1);
        Aresta a2(0, 2);
        Aresta a3(0, 5);
        Aresta a4(2, 5);
        Aresta a5(2, 3);
        Aresta a6(2, 4);
        Aresta a7(3, 5);
        Aresta a8(3, 4);

        g.inserir_aresta(a1);
        g.inserir_aresta(a2);
        g.inserir_aresta(a3);
        g.inserir_aresta(a4);
        g.inserir_aresta(a5);
        g.inserir_aresta(a6);
        g.inserir_aresta(a7);
        g.inserir_aresta(a8);

        /*g.imprime();
        if (g.eh_passeio({2, 0, 4, 1, 0, 4, 3}))
        {
            cout << "Grafo é um passeio! \n";
        }
        else
        {
            cout << "Grafo não é um passeio! \n";
        }*/

        if (g.eh_caminho(0, 4, new int[g.num_vertices()]{0}, 0))
        {
            cout << "Grafo é um caminho! \n";
        }
        else
        {
            cout << "Grafo não é um caminho! \n";
        }
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
