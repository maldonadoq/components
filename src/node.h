#ifndef _NODE_H_
#define _NODE_H_

#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::list;

template <class G>
class Node
{
public:
    typedef typename G::N N;
    typedef typename G::edge edge;
    typedef typename G::node node;
    typedef typename G::eiterator eiterator;

    list<edge *> edges;
    N data;

    Node(N);
    ~Node();

    bool removeEdge(node);
    bool removeEdges();
    void print();
};

template <class G>
Node<G>::Node(N _data)
{
    data = _data;
}

template <class G>
bool Node<G>::removeEdge(node _node)
{
    eiterator itA, itB;
    for (itA = edges.begin(); itA != edges.end(); itA++)
    {
        for (itB = _node->edges.begin(); itB != _node->edges.end(); itB++)
            if (*itA == *itB)
            {
                edges.remove(*itA);
                _node->edges.remove(*itB);
                delete *itA;
                break;
            }
    }
    return false;
}

template <class G>
bool Node<G>::removeEdges()
{
    edge *tmp;
    while (!edges.empty())
    {
        tmp = edges.front();
        ((tmp->nodes[0])->edges).remove(tmp);
        ((tmp->nodes[1])->edges).remove(tmp);

        delete tmp;
    }

    return true;
}

template <class G>
void Node<G>::print()
{
    eiterator it;
    cout << "[" << data << "]:\t";
    for (it = edges.begin(); it != edges.end(); it++)
    {
        if ((*it)->nodes[1]->data != data)
        {
            cout << (*it)->weight << "->[" << (*it)->nodes[1]->data << "]\t";
        }
        if ((*it)->nodes[0]->data != data)
        {
            cout << (*it)->weight << "->[" << (*it)->nodes[0]->data << "]\t";
        }
    }

    cout << endl;
}

template <class G>
Node<G>::~Node()
{
}

#endif