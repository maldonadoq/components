#ifndef _EDGE_H_
#define _EDGE_H_

template <class G>
class Edge
{
public:
    typedef typename G::E E;
    typedef typename G::node node;

    node *nodes[2];
    E weight;

    Edge(E);
    ~Edge();
};

template <class G>
Edge<G>::Edge(E _weight)
{
    weight = _weight;
}

template <class G>
Edge<G>::~Edge()
{
}

#endif