// tomergal40@gmail.com

#include "queue.hpp"
#include <iostream>  // מותר לשימוש להדפסה בלבד

int main() {
    try {
        // Create a queue
        std::cout << "Creating a new queue..." << std::endl;
        graph::Queue q;
        
        // Test empty queue
        std::cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Queue size: " << q.getSize() << std::endl;
        
        // Add elements
        std::cout << "\nEnqueueing elements: 10, 20, 30, 40" << std::endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        
        // Check size and front element
        std::cout << "Queue size: " << q.getSize() << std::endl;
        std::cout << "Front element: " << q.peek() << std::endl;
        std::cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
        
        // Remove and display elements
        std::cout << "\nDequeuing elements:" << std::endl;
        while (!q.isEmpty()) {
            std::cout << q.dequeue() << " ";
        }
        std::cout << std::endl;
        
        // Check empty queue again
        std::cout << "\nAfter dequeuing all elements:" << std::endl;
        std::cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Queue size: " << q.getSize() << std::endl;
        
        // Test copy constructor
        std::cout << "\nTesting copy constructor:" << std::endl;
        graph::Queue q1;
        q1.enqueue(100);
        q1.enqueue(200);
        q1.enqueue(300);
        
        graph::Queue q2(q1);  // Copy constructor
        
        std::cout << "Original queue elements: ";
        while (!q1.isEmpty()) {
            std::cout << q1.dequeue() << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copied queue elements: ";
        while (!q2.isEmpty()) {
            std::cout << q2.dequeue() << " ";
        }
        std::cout << std::endl;
        
        // Test exception handling
        std::cout << "\nTesting exception handling:" << std::endl;
        std::cout << "Trying to dequeue from an empty queue..." << std::endl;
        q.dequeue();  // Should throw an exception
    }
    catch (const graph::QueueException& e) {
        std::cerr << "Queue Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}