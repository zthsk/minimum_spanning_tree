#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> getVertices(std::vector<Edge> edges){
    std::vector<int> ver;
    for(int i=0; i < edges.size(); i ++){
        int key1 = edges[i].u;
        int key2 = edges[i].v;

        if(std::find(ver.begin(), ver.end(), key1) == ver.end())
            ver.push_back(key1); 
        if(std::find(ver.begin(), ver.end(), key2) == ver.end())
            ver.push_back(key2); 
    }
    return ver;
}

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    
    std::vector<Edge> edges = G.exportEdges();
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    std::vector<int> path;
    std::vector<int> V = getVertices(edges);

    heap.push(Edge(start, -1, 0));
    for(int i =0; i<V.size(); ++i){
        Edge temp = heap.top();
        int u = temp.u;
        int dist = temp.w;
        heap.pop();

        G.setVisited(u);

        if(u == destination)
            break;
        
        for(int i =0; i< G.e[u].size(); ++i){
            int v = G.e[u][i].v;
            int w = G.e[u][i].w;
            if(G.isVisited(v))
                continue;
            if(dist + w < G.distance(v)){
                G.distance(v) = dist + w;
                heap.push(Edge(v, -1, G.distance(v)));
                G.setTrace(v,u);
            }
        }
    }

    int dest = destination;
    while(dest != -1){
        path.push_back(dest);
        dest =  G.trace(dest);
    }

    std::reverse(path.begin(), path.end());

    return path;
}
