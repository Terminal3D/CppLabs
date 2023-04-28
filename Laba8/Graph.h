#include <vector>


#ifndef CPPLABS_GRAPH_H
#define CPPLABS_GRAPH_H

template <int N, bool Acyclic>
class Graph {
public:
    Graph();

    bool add_edge(int u, int v);
    bool are_adjacent(int u, int v) const;

private:
    std::vector<std::pair<int, int>> edges;
    std::vector<int> parent;

    int find_set(int u);
    void union_sets(int u, int v);
};

#include "Graph.cpp"

#endif //CPPLABS_GRAPH_H
