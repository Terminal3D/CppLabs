#include "Graph.h"

template <int N, bool Acyclic>
Graph<N, Acyclic>::Graph() {
    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

template <int N, bool Acyclic>
bool Graph<N, Acyclic>::add_edge(int u, int v) {
    if (u < 0 || u >= N || v < 0 || v >= N || u == v) {
        return false;
    }

    if (Acyclic) {
        int parent_u = find_set(u);
        int parent_v = find_set(v);

        if (parent_u == parent_v) {
            return false;
        }

        union_sets(parent_u, parent_v);
    }

    edges.emplace_back(u, v);
    return true;
}

template <int N, bool Acyclic>
bool Graph<N, Acyclic>::are_adjacent(int u, int v) const {
    for (const auto& edge : edges) {
        if ((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u)) {
            return true;
        }
    }
    return false;
}

template <int N, bool Acyclic>
int Graph<N, Acyclic>::find_set(int u) {
    if (u != parent[u]) {
        parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

template <int N, bool Acyclic>
void Graph<N, Acyclic>::union_sets(int u, int v) {
    parent[u] = v;
}


