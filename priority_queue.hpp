// tomergal40@gmail.com
#pragma once

namespace graph {
    // Custom exception class for Priority Queue errors
    class PriorityQueueException {
    private:
        const char* message;
    
    public:
        PriorityQueueException(const char* msg) : message(msg) {}
        
        const char* what() const {
            return message;
        }
    };
    
    // Structure to hold vertex and distance/weight
    struct PQNode {
        int vertex;   // Vertex identifier
        int priority; // Priority value (lower is higher priority)
        
        PQNode(int v, int p) : vertex(v), priority(p) {}
    };
    
    // Simple Priority Queue implementation for Dijkstra and Prim algorithms
    class PriorityQueue {
    private:
        PQNode** array;     // Array of pointers to nodes
        int capacity;       // Maximum capacity
        int size;           // Current size
        
    public:
        // Constructor
        PriorityQueue(int maxSize);
        
        // Copy constructor
        PriorityQueue(const PriorityQueue& other);
        
        // Assignment operator
        PriorityQueue& operator=(const PriorityQueue& other);
        
        // Basic priority queue operations
        void insert(int vertex, int priority);
        PQNode extractMin();
        void decreasePriority(int vertex, int newPriority);
        bool contains(int vertex) const;
        int getPriority(int vertex) const;
        bool isEmpty() const;
        int getSize() const;
        
        // Helper functions
        int getVertexIndex(int vertex) const;
        void heapifyUp(int index);
        void heapifyDown(int index);
        
        // Destructor
        ~PriorityQueue();
    };
}