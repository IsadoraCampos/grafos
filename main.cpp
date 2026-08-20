#include "Grafo.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        //int vertices;

        //cout << "Digite a quantidade de vértices para o Grafo: ";
        //cin >> vertices;

        Grafo g(6);
        Aresta e(1, 3);


        cout << "Tem aresta em (" << e.v1 << "," << e.v2 << "): " << g.tem_aresta(e) << "\n";
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
