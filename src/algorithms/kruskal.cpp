#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w < b.w;
    }
};


std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    std::vector<Edge> MST;
    DisjointSet T(edges.size());
    std::sort(edges.begin(), edges.end(), EdgeKeyComparison());

    for(int i=0; i < edges.size(); i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int value = T.isOnSameSet(u, v);
        if(value != 1){
            Edge temp(u,v,w);
            MST.push_back(temp);
            T.join(u,v);
        }
    }

    return MST;
}