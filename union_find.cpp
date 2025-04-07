// tomergal40@gmail.com
#include "union_find.hpp"
    
  namespace graph {
    
    // Constructor
    UnionFind::UnionFind(int n) : size(n) {
        if (n <= 0) {
            throw UnionFindException("UnionFind size must be positive");
        }
        
        parent = new int[n];
        rank = new int[n];
        
        // Initialize each element as a separate set
        for (int i = 0; i < n; i++) {
            makeSet(i);
        }
    }
    
    // Copy constructor
    UnionFind::UnionFind(const UnionFind& other) : size(other.size) {
        parent = new int[size];
        rank = new int[size];
        
        for (int i = 0; i < size; i++) {
            parent[i] = other.parent[i];
            rank[i] = other.rank[i];
        }
    }
    
    // Assignment operator
    UnionFind& UnionFind::operator=(const UnionFind& other) {
        if (this != &other) {
            // Free existing memory
            delete[] parent;
            delete[] rank;
            
            // Allocate and copy new data
            size = other.size;
            parent = new int[size];
            rank = new int[size];
            
            for (int i = 0; i < size; i++) {
                parent[i] = other.parent[i];
                rank[i] = other.rank[i];
            }
        }
        return *this;
    }
    // Create a singleton set
    void UnionFind:: makeSet(int x) {
        if (x<0 || x>= size){
            throw UnionFindException("Element index out of bounds");
        }
        parent[x] = x;  // Each element is its own parent initially
        rank[x] = 0;    // Initial rank is 0
    }
    // Find the representative (root) of x's set with path compression
    int UnionFind:: find(int x){
        if(x<0|| x>=size){
            throw UnionFindException("Element index out of bounds");
        }
    // Path compression: make all nodes on the path point directly to the root
    if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return  parent[x];
    }
    // Union two sets by rank
    void UnionFind:: unionSets(int x, int y){
        if (x <0 || x>= size || y < 0 || y >= size){
            throw UnionFindException("Element index out of bounds");
        }
        int rootx = find(x);
        int rooty = find(y);

    // Already in the same set
    if (rootx == rooty){
            return;
        }
    // Union by rank: attach smaller rank tree under root of higher rank tree
    if (rank[rootx] < rank[rooty]){
        parent[rootx] = rooty;
        }else if (rank[rootx] > rank[rooty])
        {
        parent[rooty] = rootx;
        } else{
    // If ranks are the same, make one the root and increment its rank
        parent[rooty] = rootx;
        rank[rootx]++;
        }
    }
    // Check if two elements are in the same set
    bool UnionFind:: sameSet(int x, int y){
        if (x <0 || x>= size || y < 0 || y >= size){
            throw UnionFindException("Element index out of bounds");
        }
        return find(x) == find(y);
    }
    // Get the number of elements
    int UnionFind:: getSize() const{
        return size;
    }
    // Destructor
    UnionFind:: ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }
}