
# Minimum Spanning Tree Algorithms Implementation in C++
This repository hosts an implementation of three fundamental Minimum Spanning Tree (MST) algorithms—Prim's, Kruskal's, and Dijkstra's—utilizing C++. These algorithms employ disjoint set data structures for efficient handling of connected components and use merge sort for sorting edges by weight. Additionally, the repository includes functionalities for graph visualization to depict the resulting MST.

## Overview
The primary objective of this project is to provide optimized implementations of MST algorithms in C++ while incorporating disjoint set data structures and merge sort for efficient operations. These algorithms facilitate the identification of the minimum spanning tree within a graph and enable graph visualization for better comprehension of the resulting tree structure.

## Deployment

To deploy this project on linux, run:

```bash
  git clone https://github.com/zthsk/minimum_spanning_tree.git

  cd minimum_spanning_tree

  make kruskal | prim | dijkstra
```

## Implemented Algorithms:

- **Prim's Algorithm**: A greedy approach that constructs a minimum spanning tree by selecting the minimum weight edge at each step from a starting vertex.

- **Kruskal's Algorithm**: Another greedy algorithm that builds a minimum spanning tree by iteratively selecting edges in ascending order of weight while avoiding cycles.

- **Dijkstra's Algorithm**: While primarily used for finding the shortest path in weighted graphs, this implementation is adapted to find the MST using specialized modifications.

## Usage

Utilize the provided C++ files to incorporate these algorithms into your project. The disjoint set, merge sort, and graph visualization functionalities are encapsulated within their respective header files for ease of integration. Refer to the example usage within the source files to understand how to employ these algorithms and visualize the resulting minimum spanning tree.
