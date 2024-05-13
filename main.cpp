#include <iostream>
#include <unordered_map>
#include "src/graph.h"
#include "src/edge.h"
#include "src/trait.h"

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

typedef Trait<int, double> Box;
int main(int argc, char const *argv[])
{
    unsigned vertices = 13;
    Graph<Box> *graph = new Graph<Box>();

    /* graph->insert(1, 2);
    graph->insert(1, 3);
    graph->insert(1, 4);
    graph->insert(2, 3);
    graph->insert(3, 5);
    graph->insert(3, 6);
    graph->insert(4, 5);

    graph->insert(7, 8);
    graph->insert(7, 9);

    graph->insert(10, 11);
    graph->insert(10, 12); */

    graph->insert(1, 2);
    graph->insert(1, 3);
    graph->insert(2, 3);

    graph->insert(4, 5);

    graph->insert(8);

    graph->insert(6, 7);

    unsigned components = graph->connectedComponents();
    cout << "Connected Components: " << components << endl;
    return 0;
}