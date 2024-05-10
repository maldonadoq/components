#include <iostream>
#include <unordered_map>
#include "src/graph.h"
#include "src/edge.h"
#include "src/trait.h"

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

template <class G>
void depthFirstSearch(int vertex, Graph<G> *_graph, unordered_map<int, bool> &visited)
{
    visited[vertex] = true;
    for (unsigned i = 0; i < _graph->qVertices(); i++)
    {
        // Iterator Between Edge List
    }
}

template <class G>
unsigned connectedComponents(Graph<G> *_graph)
{
    unsigned components = 0;
    unordered_map<int, bool> visited;
    for (unsigned i = 0; i < _graph->qVertices(); i++)
    {
        visited[_graph->nodes[i]->data] = false;
    }

    for (unsigned i = 0; i < _graph->qVertices(); i++)
    {
        if (!visited[_graph->nodes[i]->data])
        {
            depthFirstSearch(_graph->nodes[i]->data, _graph, visited);
            components += 1;
        }
    }

    return components;
}

typedef Trait<int, double> Box;
int main(int argc, char const *argv[])
{
    unsigned vertices = 13;
    Graph<Box> *graph = new Graph<Box>();

    graph->insert(1, 2);
    graph->insert(1, 3);
    graph->insert(1, 4);
    graph->insert(2, 3);
    graph->insert(3, 5);
    graph->insert(3, 6);
    graph->insert(4, 5);

    graph->insert(7, 8);
    graph->insert(7, 9);

    graph->insert(10, 11);
    graph->insert(10, 12);

    unsigned components = connectedComponents(graph);
    cout << "Connected Components: " << components << endl;
    return 0;
}