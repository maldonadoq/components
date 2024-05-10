#ifndef _TRAIT_H_
#define _TRAIT_H_

#include "graph.h"
#include "edge.h"
#include "node.h"

template <class _N, class _E>
class Trait
{
public:
    typedef Trait<_N, _E> self;
    typedef _N N;
    typedef _E E;

    typedef Graph<self> graph;
    typedef Node<self> node;
    typedef Edge<self> edge;

    typedef typename list<node *>::iterator niterator;
    typedef typename list<edge *>::iterator eiterator;
};

#endif