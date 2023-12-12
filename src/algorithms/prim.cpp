#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>
#include <set>
#include <tuple>
#include <limits>
#define INF 0x3f3f3f3f


/*struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};
*/

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

std::vector<int> remove_visited(std::vector<int> V, std::vector<int> T ){
    for (int i = 0; i < V.size(); ++i) {
        for (int j = 0; j < T.size(); ++j){
            if(V[i] == T[j]){
                V.erase(V.begin()+i);
            }
        }        
    }
    return V;
}

bool has_edge(std::vector<Edge> edges, int u, int v){
    for(int i=0; i < edges.size(); i++){
        if(edges[i].u == u && edges[i].v == v){
            return 1;
        }
    }
    return 0;
}

int get_weight(std::vector<Edge> edges, int u, int v){
    for(int i=0; i < edges.size(); i++){
        if(edges[i].u == u && edges[i].v ==v){
            return edges[i].w;
        }
    }
    return 0;

}

int get_minimum_distance(std::vector<int> distance, std::vector<int> V){
    std::vector<int> new_dist(0);
    for(int i = 0; i < V.size(); ++i){ 
        new_dist.push_back(distance[V[i]]);
    }
    int min = *std::min_element(new_dist.begin(), new_dist.end());
    auto it = std::find(distance.begin(), distance.end(), min);
    int vertex = it - distance.begin();
    return vertex;
}

std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    std::vector<int> V = getVertices(edges);
    std::vector<Edge> MST; 
    std::vector<int> T{0};
    std::vector<int> distance(V);
    std::vector<int> parent(V);
    std::vector<int> new_V = V;

    for(int i = 0; i < V.size(); i++){
        int v = V[i];
        if(has_edge(edges, 0, v)){
            int weight = get_weight(edges,0, v);
            distance[v] = weight;
            parent[v] = 0;
        }else{
            distance[v] = INF;
            parent[v] = -1;
        }
    }

    for(int i = 0; i < V.size()-1; ++i){
        new_V = remove_visited(new_V, T);
        int u = get_minimum_distance(distance, new_V);
        distance[u] = INF;
        int weight = get_weight(edges, u, parent[u]);
        Edge temp(parent[u], u, weight);
        MST.push_back(temp);
        T.push_back(u);
        new_V = remove_visited(new_V, T);
        for(int i = 0; i < new_V.size(); ++i){
            int v = new_V[i];
            int weight = get_weight(edges, u, v);
            if(has_edge(edges, u, v) && weight < distance[v]){
                distance[v] = weight;
                parent[v] = u;
            }
        } 
    }
    return MST;
}

