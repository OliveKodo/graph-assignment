// tomergal40@gmail.com
#pragma once
#include "graph.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "union_find.hpp"

namespace graph {
// Class for implementing graph algorithms
class Algorithms {
        public:
        // BFS algorithm - returns a tree (rooted at source)
        static Graph bfs(const Graph& g, int source);

        // DFS algorithm - returns a forest 
        static Graph dfs(const Graph& g, int start);

        // Dijkstra's algorithm - returns shortest path tree  
        static Graph dijkstra(const Graph& g, int start);

        // Prim's algorithm - returns minimum spanning tree
        static Graph prim(const Graph& g);

        // Kruskal's algorithm - returns minimum spanning tree
        static Graph kruskal(const Graph& g);

        private:
        // Helper function for DFS to visit vertices recursively
        static void dfsVisit(const Graph& g, int v, bool* visited, Graph& result);
              
    };
}