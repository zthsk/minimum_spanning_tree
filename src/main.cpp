#include <iostream>
#include <vector>
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <cmath>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif



#if PRIM || KRUSKAL
bool testMST() {
    Graph G(6);
    G.insertEdge(0, 1, 1);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 3);
    G.insertEdge(2, 4, 4);
    G.insertEdge(4, 3, 5);
    G.insertEdge(4, 5, 6);
    
#ifdef PRIM
    std::vector<Edge> tree = constructMSTPrim(G);
#else
    std::vector<Edge> tree = constructMSTKruskal(G);
#endif


    int totalCost = 0;
    for (int i = 0; i < tree.size(); ++i) {
        totalCost += tree[i].w;
    }
    std::cout << "Total Cost of Minimum Spanning Tree: " << totalCost << std::endl;
    //exit(0);

    return true;
}


void mstOnCampus() {
    std::ifstream reader("assets/map_info.txt");
    int n, m;
    reader >> n >> m;
    std::map<std::string, int> name2index;
    std::map<int, std::string> index2name;
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < n; ++i) {
        int index, x, y;
        std::string name;
        reader >> index >> name >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        name2index[name] = index;
        index2name[index] = name;
    }

    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        reader >> u >> v;
        int dx = xs[u] - xs[v];
        int dy = ys[u] - ys[v];
        int w = (int)sqrt(dx * dx + dy * dy);
        G.insertEdge(u, v, w);
    }
    
#ifdef PRIM
    std::vector<Edge> tree = constructMSTPrim(G);
#else
    std::vector<Edge> tree = constructMSTKruskal(G);
#endif

    int totalCost = 0;
    for (int i = 0; i < tree.size(); ++i) {
        totalCost += tree[i].w;
    }

    std::cout << "Total Cost of Minimum Spanning Tree: " << totalCost << std::endl;


#ifdef OPENCV
    cv::Mat image = cv::imread("assets/map.png");
    for (int i = 0; i < n; ++i) {
        cv::circle(image, cv::Point(xs[i], ys[i]), 5, cv::Scalar(255, 0, 0), -1);
        cv::putText(image, index2name[i],  cv::Point(xs[i], ys[i]-10),  cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 0), 1);
    }
    for (int i = 0; i < tree.size(); ++i) {
        int u = tree[i].u;
        int v = tree[i].v;
        cv::line(image, cv::Point(xs[u], ys[u]), cv::Point(xs[v], ys[v]), cv::Scalar(255, 0, 0), 4);
    }
    //cv::resize(image, image, cv::Size(), 0.75, 0.75);
    cv::imshow("Minimum Spanning Tree", image);
    cv::waitKey(0);

#else
    std::cout << "You have to use OpenCV to visualize your map\n";
#endif
}
#endif


#ifdef DIJKSTRA

bool testShortestPath() {
    Graph G(6);
    G.insertEdge(0, 1, 1);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 3);
    G.insertEdge(2, 4, 4);
    G.insertEdge(4, 3, 5);
    G.insertEdge(4, 5, 6);


    std::cout << "Path from 0 to 5: ";
    std::vector<int> path = G.search(0, 5);
    for (int i = 0; i < path.size(); ++i) 
        std::cout << path[i] << " ";
    std::cout << std::endl;
    
    return true;
}


void searchOnCampus(std::string start = "BELL", std::string destination = "HAPG") {
    std::ifstream reader("assets/map_info.txt");
    int n, m;
    reader >> n >> m;
    std::map<std::string, int> name2index;
    std::map<int, std::string> index2name;
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < n; ++i) {
        int index, x, y;
        std::string name;
        reader >> index >> name >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        name2index[name] = index;
        index2name[index] = name;
    }

    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        reader >> u >> v;
        int dx = xs[u] - xs[v];
        int dy = ys[u] - ys[v];
        int w = (int)sqrt(dx * dx + dy * dy);
        G.insertEdge(u, v, w);
    }

    std::vector<int> path = G.search(name2index[start], name2index[destination]);

    std::cout << "Path from " << start  << " to " << " detination: " << start;
    for (int i = 1; i < path.size(); ++i)
        std::cout << " -> " << index2name[path[i]];
    
    std::cout << "\n";

#ifdef OPENCV
    cv::Mat image = cv::imread("assets/map.png");
    for (int i = 0; i < n; ++i) {
        cv::circle(image, cv::Point(xs[i], ys[i]), 5, cv::Scalar(255, 0, 0), -1);
        cv::putText(image, index2name[i],  cv::Point(xs[i], ys[i]-10),  cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 0, 0), 1);
    }

    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) 
            cv::line(image, cv::Point(xs[path[i]], ys[path[i]]), cv::Point(xs[path[i-1]], ys[path[i-1]]), cv::Scalar(255, 0, 0), 4);
    }
    //cv::resize(image, image, cv::Size(), 0.75, 0.75);
    cv::imshow("Path from " + start + " to " + destination, image);
    cv::waitKey(0);

#else
    std::cout << "You have to use OpenCV to visualize your map road\n";
#endif
}
#endif

int main(int argc, char **args) {

#ifdef PRIM
    std::cout << std::endl << "Perform unit test of the Prim's algorithm"<< std::endl;
    testMST();

    std::cout << std::endl;
    mstOnCampus();
#endif

#ifdef KRUSKAL
    std::cout << std::endl << "Perform unit test of the Kruskal's algorithm"<< std::endl;
    testMST();

    std::cout << std::endl;
    mstOnCampus();
#endif

#ifdef DIJKSTRA
    std::cout << std::endl << "Perform unit test of the Dijkstra algorithm"<< std::endl;
    testShortestPath();

    std::cout << std::endl;
    searchOnCampus("SAEF", "GRAD");
#endif
    
    
}
