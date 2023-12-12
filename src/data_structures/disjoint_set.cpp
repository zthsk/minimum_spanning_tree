#include <disjoint_set.hpp>

DisjointSet::DisjointSet(int n) {
    this->parent = std::vector<int>(n, -1);
}

int DisjointSet::find(int u) {
    if (this->parent[u] == -1)
        return u;
    else
        return this->parent[u] = this->find(parent[u]);
}

int DisjointSet::isOnSameSet(int u, int v) {
    return (this->find(u) == this->find(v)) ? 1 : 0;
}

void DisjointSet::join(int u, int v) {
    int pu = this->find(u);
    int pv = this->find(v);
    if (pu != pv)
        this->parent[pu] = pv;
}
