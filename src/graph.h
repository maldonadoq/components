#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <map>
#include "edge.h"

using std::cout;
using std::endl;
using std::map;
using std::vector;

template <class G>
class Graph
{
private:
    typedef typename G::N N;
    typedef typename G::E E;
    typedef typename G::node node;
    typedef typename G::edge edge;

    vector<node *> nodes;
    unsigned quantityVertices;
    unsigned quantityEdges;

public:
    Graph();
    ~Graph();

    bool find(N, unsigned &);
    bool insert(N);
    bool insert(N, N, E = 0);
    bool remove(N, N);
    bool remove(N);

    void depthFirstSearch(int, unordered_map<int, bool> &);
    unsigned connectedComponents();

    unsigned qVertices();
    unsigned qEdges();
    void info();
    void print();
};

template <class G>
Graph<G>::Graph()
{
    quantityVertices = 0;
    quantityEdges = 0;
}

template <class G>
bool Graph<G>::find(N _data, unsigned &index)
{
    for (index = 0; index < nodes.size(); index++)
        if (nodes[index]->data == _data)
            return true;
    return false;
}

template <class G>
bool Graph<G>::insert(N _data)
{
    node *nodeTmp = new node(_data);
    nodes.push_back(nodeTmp);
    quantityVertices += 1;

    return true;
}

template <class G>
bool Graph<G>::insert(N _dataA, N _dataB, E _weight)
{
    unsigned indexA;
    if (!find(_dataA, indexA))
    {
        insert(_dataA);
        indexA = nodes.size() - 1;
    }

    unsigned indexB;
    if (!find(_dataB, indexB))
    {
        insert(_dataB);
        indexB = nodes.size() - 1;
    }

    edge *edgeTmp = new edge(_weight);
    nodes[indexA]->edges.push_back(edgeTmp);
    nodes[indexB]->edges.push_back(edgeTmp);
    edgeTmp->nodes[0] = nodes[indexA];
    edgeTmp->nodes[1] = nodes[indexB];

    quantityEdges += 1;
    return true;
}

template <class G>
bool Graph<G>::remove(N _dataA, N _dataB)
{
    unsigned indexA, indexB;
    if (find(_dataA, indexA) and find(_dataB, indexB))
    {
        return false;
    }

    nodes[indexA]->removeEdge(nodes[indexB]);
    quantityEdges -= 1;
    return true;
}

template <class G>
bool Graph<G>::remove(N _data)
{
    unsigned index;
    if (!find(_data, index))
    {
        return false;
    }

    quantityEdges -= nodes[index]->edges.size();
    nodes[index]->removeEdges();

    delete nodes[index];
    nodes.erase(nodes.begin() + index);
    quantityVertices -= 1;

    return true;
}

template <class G>
void Graph<G>::info()
{
    cout << "------------------------------" << endl;
    cout << "   Nodes: " << quantityVertices << "    Edges: " << quantityEdges << endl;
    cout << "------------------------------" << endl;
}

template <class G>
void Graph<G>::print()
{
    info();
    for (unsigned i = 0; i < quantityVertices; i++)
    {
        nodes[i]->print();
    }
}

template <class G>
unsigned Graph<G>::qVertices()
{
    return quantityVertices;
}

template <class G>
unsigned Graph<G>::qEdges()
{
    return quantityEdges;
}

template <class G>
void Graph<G>::depthFirstSearch(int vertex, unordered_map<int, bool> &visited)
{
    visited[vertex] = true;
    for (unsigned i = 0; i < graph->qVertices(); i++)
    {
        // Iterator Between Edge List
    }
}

template <class G>
unsigned Graph<G>::connectedComponents()
{
    unsigned components = 0;
    unordered_map<int, bool> visited;
    for (unsigned i = 0; i < graph->qVertices(); i++)
    {
        visited[graph->nodes[i]->data] = false;
    }

    for (unsigned i = 0; i < graph->qVertices(); i++)
    {
        if (!visited[graph->nodes[i]->data])
        {
            // depthFirstSearch(_graph->nodes[i]->data, _graph, visited);
            components += 1;
        }
    }

    return components;
}

template <class G>
Graph<G>::~Graph()
{
    for (unsigned i = 0; i < nodes.size(); i++)
    {
        delete nodes[i];
    }
}

#endif