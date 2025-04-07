// tomergal40@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "decotest.h"
#include "graph.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "union_find.hpp"
#include "algorithms.hpp"

// Utility function to create a test graph
graph::Graph createTestGraph() {
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

TEST_CASE("Graph basic operations") {
    // Create a graph with 5 vertices
    graph::Graph g(5);
    
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 10);
    g.addEdge(3, 4);
    
    // Check edge existence
    CHECK(g.hasEdge(0, 1) == true);
    CHECK(g.hasEdge(0, 4) == true);
    CHECK(g.hasEdge(1, 2) == true);
    CHECK(g.hasEdge(1, 3) == true);
    CHECK(g.hasEdge(1, 4) == true);
    CHECK(g.hasEdge(3, 4) == true);
    CHECK(g.hasEdge(2, 4) == false);
    
    // Check edge weights
    CHECK(g.getEdgeWeight(1, 2) == 2);
    CHECK(g.getEdgeWeight(1, 3) == 3);
    CHECK(g.getEdgeWeight(1, 4) == 10);
    
    // Remove an edge
    g.removeEdge(1, 4);
    
    // Check after removal
    CHECK(g.hasEdge(1, 4) == false);
    
    // Check exception when removing non-existent edge
    CHECK_THROWS(g.removeEdge(2, 4));
}

TEST_CASE("Queue operations") {
    // Create a queue
    graph::Queue q;
    
    // Check empty queue
    CHECK(q.isEmpty() == true);
    CHECK(q.getSize() == 0);
    
    // Add elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    // Check after adding
    CHECK(q.isEmpty() == false);
    CHECK(q.getSize() == 4);
    CHECK(q.peek() == 10);
    
    // Check dequeuing
    CHECK(q.dequeue() == 10);
    CHECK(q.dequeue() == 20);
    CHECK(q.dequeue() == 30);
    CHECK(q.dequeue() == 40);
    
    // Check empty again
    CHECK(q.isEmpty() == true);
    
    // Check exceptions
    CHECK_THROWS(q.dequeue());
    CHECK_THROWS(q.peek());
    
    // Test copy constructor
    graph::Queue q1;
    q1.enqueue(100);
    q1.enqueue(200);
    
    graph::Queue q2(q1);
    CHECK(q2.getSize() == 2);
    CHECK(q2.dequeue() == 100);
    CHECK(q2.dequeue() == 200);
}

TEST_CASE("Priority Queue operations") {
    // Create a priority queue
    graph::PriorityQueue pq(10);
    
    // Check empty queue
    CHECK(pq.isEmpty() == true);
    CHECK(pq.getSize() == 0);
    
    // Insert elements with priorities
    pq.insert(0, 10);
    pq.insert(1, 5);
    pq.insert(2, 15);
    pq.insert(3, 7);
    
    // Check after insertion
    CHECK(pq.isEmpty() == false);
    CHECK(pq.getSize() == 4);
    CHECK(pq.contains(0) == true);
    CHECK(pq.contains(4) == false);
    CHECK(pq.getPriority(1) == 5);
    
    // Decrease priority
    pq.decreasePriority(2, 3);
    CHECK(pq.getPriority(2) == 3);
    
    // Extract in order
    graph::PQNode node = pq.extractMin();
    CHECK(node.vertex == 2);
    CHECK(node.priority == 3);
    
    node = pq.extractMin();
    CHECK(node.vertex == 1);
    CHECK(node.priority == 5);
    
    node = pq.extractMin();
    CHECK(node.vertex == 3);
    CHECK(node.priority == 7);
    
    node = pq.extractMin();
    CHECK(node.vertex == 0);
    CHECK(node.priority == 10);
    
    // Check empty again
    CHECK(pq.isEmpty() == true);
}

TEST_CASE("Union Find operations") {
    // Create a Union-Find structure
    graph::UnionFind uf(8);
    
    // Check initial state
    for (int i = 0; i < 8; i++) {
        CHECK(uf.find(i) == i);
    }
    
    // Perform unions
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    uf.unionSets(6, 7);
    
    // Check after unions
    CHECK(uf.sameSet(0, 1) == true);
    CHECK(uf.sameSet(2, 3) == true);
    CHECK(uf.sameSet(4, 5) == true);
    CHECK(uf.sameSet(6, 7) == true);
    CHECK(uf.sameSet(1, 2) == false);
    
    // More unions
    uf.unionSets(1, 3);  // Now 0,1,2,3 should be in the same set
    uf.unionSets(5, 7);  // Now 4,5,6,7 should be in the same set
    
    CHECK(uf.sameSet(0, 3) == true);
    CHECK(uf.sameSet(4, 7) == true);
    CHECK(uf.sameSet(3, 4) == false);
    
    // Final union
    uf.unionSets(3, 4);
    
    // Check all connected
    for (int i = 0; i < 7; i++) {
        CHECK(uf.sameSet(i, i+1) == true);
    }
}

TEST_CASE("Graph Algorithms") {
    // Create a test graph
    graph::Graph g = createTestGraph();
    
    // Test BFS
    graph::Graph bfsResult = graph::Algorithms::bfs(g, 0);
    
    // The BFS tree should have all vertices
    CHECK(bfsResult.getNumVertices() == g.getNumVertices());
    
    // In BFS from vertex 0, vertices 1 and 2 should be directly connected to 0
    CHECK(bfsResult.hasEdge(0, 1) == true);
    CHECK(bfsResult.hasEdge(0, 2) == true);
    
    // Test DFS
    graph::Graph dfsResult = graph::Algorithms::dfs(g, 0);
    
    // The DFS tree should have all vertices
    CHECK(dfsResult.getNumVertices() == g.getNumVertices());
    
    // Test Dijkstra
    graph::Graph dijkstraResult = graph::Algorithms::dijkstra(g, 0);
    
    // The Dijkstra tree should have all vertices
    CHECK(dijkstraResult.getNumVertices() == g.getNumVertices());
    
    // Test Prim
    graph::Graph primResult = graph::Algorithms::prim(g);
    
    // The MST should have n-1 edges for n vertices
    int edgeCount = 0;
    for (int i = 0; i < primResult.getNumVertices(); i++) {
        graph::Neighbor* neighbor = primResult.getNeighbors(i);
        while (neighbor != nullptr) {
            if (i < neighbor->dest) { // Count each edge only once
                edgeCount++;
            }
            neighbor = neighbor->next;
        }
    }
    CHECK(edgeCount == primResult.getNumVertices() - 1);
    
    // Test Kruskal
    graph::Graph kruskalResult = graph::Algorithms::kruskal(g);
    
    // The MST should have n-1 edges for n vertices
    edgeCount = 0;
    for (int i = 0; i < kruskalResult.getNumVertices(); i++) {
        graph::Neighbor* neighbor = kruskalResult.getNeighbors(i);
        while (neighbor != nullptr) {
            if (i < neighbor->dest) { // Count each edge only once
                edgeCount++;
            }
            neighbor = neighbor->next;
        }
    }
    CHECK(edgeCount == kruskalResult.getNumVertices() - 1);
    
    // Prim and Kruskal should find MSTs with the same total weight
    int primWeight = 0;
    int kruskalWeight = 0;
    
    for (int i = 0; i < primResult.getNumVertices(); i++) {
        graph::Neighbor* neighbor = primResult.getNeighbors(i);
        while (neighbor != nullptr) {
            if (i < neighbor->dest) {
                primWeight += neighbor->weight;
            }
            neighbor = neighbor->next;
        }
    }
    
    for (int i = 0; i < kruskalResult.getNumVertices(); i++) {
        graph::Neighbor* neighbor = kruskalResult.getNeighbors(i);
        while (neighbor != nullptr) {
            if (i < neighbor->dest) {
                kruskalWeight += neighbor->weight;
            }
            neighbor = neighbor->next;
        }
    }
    
    CHECK(primWeight == kruskalWeight);
}