#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u;
    int v;
    int w;
    Edge();
    Edge(int u, int v, int w);
    Edge(const Edge &e);
    bool operator<(const Edge &second);
    bool operator>(const Edge &second);
    bool operator==(const Edge &second);
    bool operator<=(const Edge &second);
    bool operator>=(const Edge &second);
};

class Graph {
    private:
        int n; // Number of vertices 
        //std::vector<std::vector<Edge> > e; // Adjacent list 
        std::vector<int> traces;
        std::vector<bool> visited;
        std::vector<int> dist;
    public:
        Graph(int n);
        ~Graph();
        void insertEdge(int u, int v, int w, bool directed = false);
        std::vector<Edge> exportEdges(); 
        std::vector<std::vector<Edge> > e;
        void reset();

        int &distance(int u);

        bool isVisited(int u);
        void setVisited(int u);
        
        int trace(int u);
        void setTrace(int u, int v);

#ifdef DIJKSTRA
        std::vector<int> search(int start, int destination);
        friend std::vector<int> searchShortestPath(Graph &G, int start, int destination);
#endif

#ifdef PRIM 
        friend std::vector<Edge> constructMSTPrim(Graph G);
#endif

#if KRUSKAL
        friend std::vector<Edge> constructMSTKruskal(Graph G);
#endif
};

