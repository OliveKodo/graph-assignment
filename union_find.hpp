// tomergal40@gmail.com
#pragma once

namespace graph {
    // Custom exception class for UnionFind errors
    class UnionFindException {
    private:
        const char* message;
    
    public:
        UnionFindException(const char* msg) : message(msg) {}
        
        const char* what() const {
            return message;
        }
    };
    
    // UnionFind (Disjoint Set) data structure for Kruskal's algorithm
    class UnionFind {
    private:
        int* parent;    // Parent array for tracking sets
        int* rank;      // Rank array for union by rank optimization
        int size;       // Number of elements
        
    public:
        // Constructor
        UnionFind(int n);
        
        // Copy constructor
        UnionFind(const UnionFind& other);
        
        // Assignment operator
        UnionFind& operator=(const UnionFind& other);
        
        // Make a new set with a single element
        void makeSet(int x);
        
        // Find the representative (root) of a set
        int find(int x);
        
        // Union two sets
        void unionSets(int x, int y);
        
        // Check if two elements are in the same set
        bool sameSet(int x, int y);
        
        // Get number of elements
        int getSize() const;
        
        // Destructor
        ~UnionFind();
    };
}