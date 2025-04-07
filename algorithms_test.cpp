// tomergal40@gmail.com
#include "algorithms.hpp"
#include <iostream>

// Utility function to create a test graph
graph::Graph createTestGraph() {
    graph::Graph g(6);  // 6 vertices
    
    // Add edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);
    
    return g;
}

int main() {
    try {
        // Create a test graph
        std::cout << "Creating test graph..." << std::endl;
        graph::Graph testGraph = createTestGraph();
        
        std::cout << "Original Graph:" << std::endl;
        testGraph.print_graph();
        
        // Test BFS
        std::cout << "\n---------- BFS Test ----------" << std::endl;
        std::cout << "Running BFS starting from vertex 0..." << std::endl;
        graph::Graph bfsResult = graph::Algorithms::bfs(testGraph, 0);
        std::cout << "BFS Result:" << std::endl;
        bfsResult.print_graph();
        
        // Test DFS
        std::cout << "\n---------- DFS Test ----------" << std::endl;
        std::cout << "Running DFS starting from vertex 0..." << std::endl;
        graph::Graph dfsResult = graph::Algorithms::dfs(testGraph, 0);
        std::cout << "DFS Result:" << std::endl;
        dfsResult.print_graph();
        
        // Test Dijkstra
        std::cout << "\n---------- Dijkstra Test ----------" << std::endl;
        std::cout << "Running Dijkstra starting from vertex 0..." << std::endl;
        graph::Graph dijkstraResult = graph::Algorithms::dijkstra(testGraph, 0);
        std::cout << "Dijkstra Result:" << std::endl;
        dijkstraResult.print_graph();
        
        // Test Prim
        std::cout << "\n---------- Prim Test ----------" << std::endl;
        std::cout << "Running Prim's algorithm..." << std::endl;
        graph::Graph primResult = graph::Algorithms::prim(testGraph);
        std::cout << "Prim Result:" << std::endl;
        primResult.print_graph();
        
        // Test Kruskal
        std::cout << "\n---------- Kruskal Test ----------" << std::endl;
        std::cout << "Running Kruskal's algorithm..." << std::endl;
        graph::Graph kruskalResult = graph::Algorithms::kruskal(testGraph);
        std::cout << "Kruskal Result:" << std::endl;
        kruskalResult.print_graph();
        
    }
    catch (const graph::QueueException& e) {
        std::cerr << "Queue Exception: " << e.what() << std::endl;
    }
    catch (const graph::PriorityQueueException& e) {
        std::cerr << "Priority Queue Exception: " << e.what() << std::endl;
    }
    catch (const graph::UnionFindException& e) {
        std::cerr << "Union Find Exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << std::endl;
    }
    
    return 0;
}