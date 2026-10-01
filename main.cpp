#include "Grafo.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    try
    {
        Grafo g(6);
        Aresta a1(2, 5);
        Aresta a2(0, 4);
        Aresta a3(3, 5);
        Aresta a4(1, 3);
        Aresta a5(0, 5);
        Aresta a6(2, 4);
    

        g.inserir_aresta(a1);
        g.inserir_aresta(a2);
        g.inserir_aresta(a3);
        g.inserir_aresta(a4);
        g.inserir_aresta(a5);
        g.inserir_aresta(a6);


        /*g.imprime();
        if (g.eh_passeio({2, 0, 4, 1, 0, 4, 3}))
        {
            cout << "Grafo é um passeio! \n";
        }
        else
        {
            cout << "Grafo não é um passeio! \n";
        }*/

        /*if (g.eh_caminho(0, 4, new int[g.num_vertices()]{0}, 0))
        {
            cout << "Grafo é um caminho! \n";
        }
        else
        {
            cout << "Grafo não é um caminho! \n";
        }*/
        // vector<int> marcado(g.num_vertices(), 0);
        // g.busca_profundidade(0, marcado);
        g.busca_largura(5,2);
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
