// tomergal40@gmail.com
#include "queue.hpp"
namespace graph {
    
    // Constructor
    Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    // Copy constructor
    Queue::Queue(const Queue& other) : front(nullptr), rear(nullptr), size(0) {
        Node* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }
    
    // Assignment operator
    Queue& Queue::operator=(const Queue& other) {
        if (this != &other) {
            // Clear current queue
            while (!isEmpty()) {
                dequeue();
            }
            
            // Copy elements from other queue
            Node* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Add element to the queue
    void Queue::enqueue(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        size++;
    }
    
    // Remove and return the front element
    int Queue::dequeue() {
        if (isEmpty()) {
            throw QueueException("Cannot dequeue from an empty queue");
        }
        
        Node* temp = front;
        int value = front->data;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        size--;
        return value;
    }
    
    // Return the front element without removing it
    int Queue::peek() const {
        if (isEmpty()) {
            throw QueueException("Cannot peek an empty queue");
        }
        
        return front->data;
    }
    
    // Check if queue is empty
    bool Queue::isEmpty() const {
        return front == nullptr;
    }
    
    // Get the number of elements in the queue
    int Queue::getSize() const {
        return size;
    }
    
    // Destructor
    Queue::~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
}