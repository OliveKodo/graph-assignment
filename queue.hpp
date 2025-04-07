// tomergal40@gmail.com
#pragma once

namespace graph {
    // Custom exception class for Queue errors
    class QueueException {
    private:
        const char* message;
    
    public:
        QueueException(const char* msg) : message(msg) {}
        
        const char* what() const {
            return message;
        }
    };
    
    // Simple Queue implementation for BFS algorithm
    class Queue {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int d, Node* n = nullptr) : data(d), next(n) {}
        };
        
        Node* front;
        Node* rear;
        int size;
        
    public:
        // Constructor
        Queue();
        
        // Copy constructor
        Queue(const Queue& other);
        
        // Assignment operator
        Queue& operator=(const Queue& other);
        
        // Basic queue operations
        void enqueue(int value);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
        int getSize() const;
        
        // Destructor
        ~Queue();
    };
}