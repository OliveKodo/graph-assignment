// tomergal40@gmail.com
#include "priority_queue.hpp"
#include <iostream>  // for printing only

int main() {
    try {
        // Create a priority queue
        std::cout << "Creating a priority queue with capacity 10..." << std::endl;
        graph::PriorityQueue pq(10);
        
        // Test empty queue
        std::cout << "Priority queue is empty: " << (pq.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Priority queue size: " << pq.getSize() << std::endl;
        
        // Insert elements
        std::cout << "\nInserting elements with various priorities:" << std::endl;
        pq.insert(0, 10);  // Vertex 0 with priority 10
        std::cout << "Inserted vertex 0 with priority 10" << std::endl;
        
        pq.insert(1, 5);   // Vertex 1 with priority 5
        std::cout << "Inserted vertex 1 with priority 5" << std::endl;
        
        pq.insert(2, 15);  // Vertex 2 with priority 15
        std::cout << "Inserted vertex 2 with priority 15" << std::endl;
        
        pq.insert(3, 7);   // Vertex 3 with priority 7
        std::cout << "Inserted vertex 3 with priority 7" << std::endl;
        
        // Check size after insertions
        std::cout << "\nPriority queue size after insertions: " << pq.getSize() << std::endl;
        std::cout << "Priority queue is empty: " << (pq.isEmpty() ? "Yes" : "No") << std::endl;
        
        // Check if vertices exist
        std::cout << "\nChecking if vertices exist in the queue:" << std::endl;
        std::cout << "Vertex 1 exists: " << (pq.contains(1) ? "Yes" : "No") << std::endl;
        std::cout << "Vertex 5 exists: " << (pq.contains(5) ? "Yes" : "No") << std::endl;
        
        // Get priority
        std::cout << "\nGetting priorities:" << std::endl;
        std::cout << "Priority of vertex 1: " << pq.getPriority(1) << std::endl;
        std::cout << "Priority of vertex 3: " << pq.getPriority(3) << std::endl;
        
        // Decrease priority
        std::cout << "\nDecreasing priority of vertex 2 from 15 to 3..." << std::endl;
        pq.decreasePriority(2, 3);
        std::cout << "New priority of vertex 2: " << pq.getPriority(2) << std::endl;
        
        // Extract elements in priority order
        std::cout << "\nExtracting elements in priority order:" << std::endl;
        while (!pq.isEmpty()) {
            graph::PQNode node = pq.extractMin();
            std::cout << "Vertex: " << node.vertex << ", Priority: " << node.priority << std::endl;
        }
        
        // Queue should be empty now
        std::cout << "\nPriority queue is empty: " << (pq.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Priority queue size: " << pq.getSize() << std::endl;
        
        // Test exception handling
        std::cout << "\nTesting exception handling:" << std::endl;
        std::cout << "Trying to extract from an empty priority queue..." << std::endl;
        pq.extractMin();  // Should throw an exception
    }
    catch (const graph::PriorityQueueException& e) {
        std::cerr << "Priority Queue Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}