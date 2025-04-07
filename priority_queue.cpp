// tomergal40@gmail.com
#include "priority_queue.hpp"

namespace graph {
    
    // Constructor
    PriorityQueue::PriorityQueue(int maxSize) : capacity(maxSize), size(0) {
        if (maxSize <= 0) {
            throw PriorityQueueException("Priority queue capacity must be positive");
        }
        
        array = new PQNode*[maxSize];
        for (int i = 0; i < maxSize; i++) {
            array[i] = nullptr;
        }
    }
    
    // Copy constructor
    PriorityQueue::PriorityQueue(const PriorityQueue& other) : capacity(other.capacity), size(other.size) {
        array = new PQNode*[capacity];
        
        for (int i = 0; i < size; i++) {
            if (other.array[i] != nullptr) {
                array[i] = new PQNode(other.array[i]->vertex, other.array[i]->priority);
            } else {
                array[i] = nullptr;
            }
        }
        
        for (int i = size; i < capacity; i++) {
            array[i] = nullptr;
        }
    }
    
    // Assignment operator
    PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
        if (this != &other) {
            // Free existing memory
            for (int i = 0; i < capacity; i++) {
                if (array[i] != nullptr) {
                    delete array[i];
                }
            }
            delete[] array;
            
            // Allocate new memory
            capacity = other.capacity;
            size = other.size;
            array = new PQNode*[capacity];
            
            // Copy nodes
            for (int i = 0; i < size; i++) {
                if (other.array[i] != nullptr) {
                    array[i] = new PQNode(other.array[i]->vertex, other.array[i]->priority);
                } else {
                    array[i] = nullptr;
                }
            }
            
            for (int i = size; i < capacity; i++) {
                array[i] = nullptr;
            }
        }
        return *this;
    }
    
    // Insert a new node or update priority if vertex already exists
    void PriorityQueue::insert(int vertex, int priority) {
        if (size == capacity) {
            throw PriorityQueueException("Priority queue is full");
        }
        
        // Check if vertex already exists
        int index = getVertexIndex(vertex);
        if (index != -1) {
            // Vertex already exists, update its priority if new one is lower
            if (priority < array[index]->priority) {
                array[index]->priority = priority;
                heapifyUp(index);
            }
            return;
        }
        
        // Create new node
        array[size] = new PQNode(vertex, priority);
        heapifyUp(size);
        size++;
    }
    
    // Extract and return the node with minimum priority
    PQNode PriorityQueue::extractMin() {
        if (isEmpty()) {
            throw PriorityQueueException("Cannot extract from an empty priority queue");
        }
        
        // Store the minimum node
        PQNode result = *array[0];
        
        // Replace root with last node
        delete array[0];
        size--;
        
        if (size > 0) {
            array[0] = array[size];
            array[size] = nullptr;
            heapifyDown(0);
        } else {
            array[0] = nullptr;
        }
        
        return result;
    }
    
    // Decrease the priority of a vertex
    void PriorityQueue::decreasePriority(int vertex, int newPriority) {
        int index = getVertexIndex(vertex);
        
        if (index == -1) {
            throw PriorityQueueException("Vertex not found in priority queue");
        }
        
        if (newPriority > array[index]->priority) {
            throw PriorityQueueException("New priority is greater than current priority");
        }
        
        array[index]->priority = newPriority;
        heapifyUp(index);
    }
    
    // Check if the queue contains a vertex
    bool PriorityQueue::contains(int vertex) const {
        return getVertexIndex(vertex) != -1;
    }
    
    // Get the priority of a vertex
    int PriorityQueue::getPriority(int vertex) const {
        int index = getVertexIndex(vertex);
        
        if (index == -1) {
            throw PriorityQueueException("Vertex not found in priority queue");
        }
        
        return array[index]->priority;
    }
    
    // Check if queue is empty
    bool PriorityQueue::isEmpty() const {
        return size == 0;
    }
    
    // Get the current size
    int PriorityQueue::getSize() const {
        return size;
    }
    
    // Find the index of a vertex in the array
    int PriorityQueue::getVertexIndex(int vertex) const {
        for (int i = 0; i < size; i++) {
            if (array[i]->vertex == vertex) {
                return i;
            }
        }
        return -1;  // Vertex not found
    }
    
    // Helper function to maintain heap property when inserting or decreasing priority
    void PriorityQueue::heapifyUp(int index) {
        if (index <= 0) return;
        
        int parent = (index - 1) / 2;
        
        if (array[index]->priority < array[parent]->priority) {
            // Swap with parent
            PQNode* temp = array[index];
            array[index] = array[parent];
            array[parent] = temp;
            
            // Recursively heapify up
            heapifyUp(parent);
        }
    }
    
    // Helper function to maintain heap property when removing min
    void PriorityQueue::heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && array[left]->priority < array[smallest]->priority) {
            smallest = left;
        }
        
        if (right < size && array[right]->priority < array[smallest]->priority) {
            smallest = right;
        }
        
        if (smallest != index) {
            // Swap with smallest child
            PQNode* temp = array[index];
            array[index] = array[smallest];
            array[smallest] = temp;
            
            // Recursively heapify down
            heapifyDown(smallest);
        }
    }
    
    // Destructor
    PriorityQueue::~PriorityQueue() {
        for (int i = 0; i < capacity; i++) {
            if (array[i] != nullptr) {
                delete array[i];
            }
        }
        delete[] array;
    }
}