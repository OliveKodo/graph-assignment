// tomergal40@gmail.com
#include "graph.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "union_find.hpp"
#include "algorithms.hpp"
#include <iostream>

// Utility function to create a demo graph
graph::Graph createDemoGraph() {
    graph::Graph g(6);  // 6 vertices
    
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

// Demonstrates Graph functionality
void demoGraph() {
    std::cout << "\n============ GRAPH DEMONSTRATION ============\n" << std::endl;
    
    try {
        // Create a graph with 5 vertices
        graph::Graph g(5);
        
        // Add edges
        std::cout << "Adding edges to the graph..." << std::endl;
        g.addEdge(0, 1);
        g.addEdge(0, 4);
        g.addEdge(1, 2, 2);
        g.addEdge(1, 3, 3);
        g.addEdge(1, 4, 10);
        g.addEdge(3, 4);
        
        // Print the graph
        std::cout << "\nOriginal graph:" << std::endl;
        g.print_graph();
        
        // Remove an edge
        std::cout << "\nRemoving edge (1,4)..." << std::endl;
        g.removeEdge(1, 4);
        
        // Print again after removal
        std::cout << "After removal:" << std::endl;
        g.print_graph();
        
        // Check edge existence
        std::cout << "\nChecking edge existence:" << std::endl;
        std::cout << "Edge (0,1) exists: " << (g.hasEdge(0, 1) ? "Yes" : "No") << std::endl;
        std::cout << "Edge (1,4) exists: " << (g.hasEdge(1, 4) ? "Yes" : "No") << std::endl;
        
        // Try to remove a non-existent edge - will throw an exception
        std::cout << "\nTrying to remove non-existent edge (2,4)..." << std::endl;
        g.removeEdge(2, 4);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

// Demonstrates Queue functionality
void demoQueue() {
    std::cout << "\n============ QUEUE DEMONSTRATION ============\n" << std::endl;
    
    try {
        // Create a queue
        std::cout << "Creating a queue and adding elements..." << std::endl;
        graph::Queue q;
        
        // Add elements
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        
        std::cout << "Queue size: " << q.getSize() << std::endl;
        std::cout << "Front element: " << q.peek() << std::endl;
        
        // Dequeue elements
        std::cout << "\nDequeuing elements: ";
        while (!q.isEmpty()) {
            std::cout << q.dequeue() << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Queue is now empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
        
        // Test copy constructor
        graph::Queue q1;
        q1.enqueue(100);
        q1.enqueue(200);
        
        std::cout << "\nCreating a copy of a queue with elements 100, 200..." << std::endl;
        graph::Queue q2(q1);
        
        std::cout << "Elements in the copy: ";
        while (!q2.isEmpty()) {
            std::cout << q2.dequeue() << " ";
        }
        std::cout << std::endl;
    }
    catch (const graph::QueueException& e) {
        std::cerr << "Queue Exception: " << e.what() << std::endl;
    }
}

// Demonstrates Priority Queue functionality
void demoPriorityQueue() {
    std::cout << "\n========= PRIORITY QUEUE DEMONSTRATION =========\n" << std::endl;
    
    try {
        // Create a priority queue
        std::cout << "Creating a priority queue..." << std::endl;
        graph::PriorityQueue pq(10);
        
        // Insert elements with priorities
        std::cout << "Inserting elements with priorities..." << std::endl;
        pq.insert(0, 10);
        pq.insert(1, 5);
        pq.insert(2, 15);
        pq.insert(3, 7);
        
        std::cout << "Priority queue size: " << pq.getSize() << std::endl;
        
        // Decrease priority
        std::cout << "\nDecreasing priority of vertex 2 from 15 to 3..." << std::endl;
        pq.decreasePriority(2, 3);
        
        // Extract elements in priority order
        std::cout << "\nExtracting elements in priority order:" << std::endl;
        while (!pq.isEmpty()) {
            graph::PQNode node = pq.extractMin();
            std::cout << "Vertex: " << node.vertex << ", Priority: " << node.priority << std::endl;
        }
    }
    catch (const graph::PriorityQueueException& e) {
        std::cerr << "Priority Queue Exception: " << e.what() << std::endl;
    }
}

// Demonstrates Union Find functionality
void demoUnionFind() {
    std::cout << "\n========= UNION-FIND DEMONSTRATION =========\n" << std::endl;
    
    try {
        // Create a Union-Find structure
        std::cout << "Creating a Union-Find structure with 8 elements..." << std::endl;
        graph::UnionFind uf(8);
        
        // Perform some unions
        std::cout << "\nPerforming unions:" << std::endl;
        std::cout << "Union(0,1), Union(2,3), Union(4,5), Union(6,7)" << std::endl;
        uf.unionSets(0, 1);
        uf.unionSets(2, 3);
        uf.unionSets(4, 5);
        uf.unionSets(6, 7);
        
        // Check some sets
        std::cout << "\nChecking sets:" << std::endl;
        std::cout << "0 and 1 in same set: " << (uf.sameSet(0, 1) ? "Yes" : "No") << std::endl;
        std::cout << "1 and 2 in same set: " << (uf.sameSet(1, 2) ? "Yes" : "No") << std::endl;
        
        // Perform more unions
        std::cout << "\nMore unions: Union(1,3), Union(5,7)" << std::endl;
        uf.unionSets(1, 3);  // Now 0,1,2,3 should be in the same set
        uf.unionSets(5, 7);  // Now 4,5,6,7 should be in the same set
        
        // Check again
        std::cout << "\nChecking sets again:" << std::endl;
        std::cout << "0 and 3 in same set: " << (uf.sameSet(0, 3) ? "Yes" : "No") << std::endl;
        std::cout << "4 and 7 in same set: " << (uf.sameSet(4, 7) ? "Yes" : "No") << std::endl;
        std::cout << "3 and 4 in same set: " << (uf.sameSet(3, 4) ? "Yes" : "No") << std::endl;
        
        // Final union
        std::cout << "\nFinal union: Union(3,4) - connects all sets" << std::endl;
        uf.unionSets(3, 4);
        
        // Check if all elements are in the same set
        bool allConnected = true;
        for (int i = 0; i < 7; i++) {
            if (!uf.sameSet(i, i+1)) {
                allConnected = false;
                break;
            }
        }
        std::cout << "All elements in the same set: " << (allConnected ? "Yes" : "No") << std::endl;
    }
    catch (const graph::UnionFindException& e) {
        std::cerr << "Union-Find Exception: " << e.what() << std::endl;
    }
}

// Demonstrates graph algorithms
void demoAlgorithms() {
    std::cout << "\n========= GRAPH ALGORITHMS DEMONSTRATION =========\n" << std::endl;
    
    try {
        // Create a demo graph
        std::cout << "Creating a demo graph..." << std::endl;
        graph::Graph g = createDemoGraph();
        
        std::cout << "\nOriginal graph:" << std::endl;
        g.print_graph();
        
        // BFS algorithm
        std::cout << "\n--- BFS Algorithm ---" << std::endl;
        std::cout << "Running BFS from vertex 0..." << std::endl;
        graph::Graph bfsResult = graph::Algorithms::bfs(g, 0);
        std::cout << "BFS Result (spanning tree):" << std::endl;
        bfsResult.print_graph();
        
        // DFS algorithm
        std::cout << "\n--- DFS Algorithm ---" << std::endl;
        std::cout << "Running DFS from vertex 0..." << std::endl;
        graph::Graph dfsResult = graph::Algorithms::dfs(g, 0);
        std::cout << "DFS Result (spanning forest):" << std::endl;
        dfsResult.print_graph();
        
        // Dijkstra algorithm
        std::cout << "\n--- Dijkstra's Algorithm ---" << std::endl;
        std::cout << "Running Dijkstra from vertex 0..." << std::endl;
        graph::Graph dijkstraResult = graph::Algorithms::dijkstra(g, 0);
        std::cout << "Dijkstra Result (shortest path tree):" << std::endl;
        dijkstraResult.print_graph();
        
        // Prim algorithm
        std::cout << "\n--- Prim's Algorithm ---" << std::endl;
        std::cout << "Running Prim's algorithm..." << std::endl;
        graph::Graph primResult = graph::Algorithms::prim(g);
        std::cout << "Prim Result (minimum spanning tree):" << std::endl;
        primResult.print_graph();
        
        // Kruskal algorithm
        std::cout << "\n--- Kruskal's Algorithm ---" << std::endl;
        std::cout << "Running Kruskal's algorithm..." << std::endl;
        graph::Graph kruskalResult = graph::Algorithms::kruskal(g);
        std::cout << "Kruskal Result (minimum spanning tree):" << std::endl;
        kruskalResult.print_graph();
    }
    catch (const std::exception& e) {
        std::cerr << "Algorithm Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "   GRAPH DATA STRUCTURES AND ALGORITHMS DEMO" << std::endl;
    std::cout << "==================================================" << std::endl;
    
    // Demonstrate Graph operations
    demoGraph();
    
    // Demonstrate Queue operations
    demoQueue();
    
    // Demonstrate Priority Queue operations
    demoPriorityQueue();
    
    // Demonstrate Union-Find operations
    demoUnionFind();
    
    // Demonstrate Graph Algorithms
    demoAlgorithms();
    
    return 0;
}