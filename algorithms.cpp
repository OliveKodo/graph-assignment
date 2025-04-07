// tomergal40@gmail.com
#include "algorithms.hpp"

namespace graph{
// BFS algorithm implementation
    Graph Algorithms:: bfs(const Graph& g,int source){
    int numVertices = g.getNumVertices();
    
    // Create a new graph with the same number of vertices
    Graph result(numVertices);

    // Array to keep track of visited vertices
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices ; i++){
            visited[i] = false;
        }
    // Create a queue for BFS

    Queue queue;

    // Mark the source as visited and enqueue it
    visited[source] = true;
    queue.enqueue(source);

    while(!queue.isEmpty()) {
        // Dequeue a vertex
        int current = queue.dequeue();
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex is not visited, mark it as visited and enqueue

         Neighbor* neighbor = g.getNeighbors(current); 
           
            while (neighbor != nullptr) {
                int adjVertex = neighbor->dest;

                if(!visited[adjVertex]){
                // Add edge to the BFS tree
                    result.addEdge(current,adjVertex,neighbor -> weight);
                                
                // Mark as visited and enqueue
                visited[adjVertex] = true;
                queue.enqueue(adjVertex);

                }
            neighbor = neighbor -> next;

            }
        }
        delete[] visited;
        return result;


    }
// DFS algorithm implementation
    Graph Algorithms:: dfs(const Graph& g,int start){
    int numVertices = g.getNumVertices();

    // Create a new graph with the same number of vertices
    Graph result(numVertices);

    // Array to keep track of visited vertices
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }
        // Start DFS from the given vertex
        dfsVisit(g,start,visited,result);

        // Check if there are unvisited vertices
        // This creates a forest if the graph is not connected
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfsVisit(g, i, visited, result);
            }
        }
        delete[] visited;
        return result;
    }
// Helper function for DFS
    void Algorithms:: dfsVisit(const Graph& g, int v, bool* visited, Graph& result){
        visited[v] = true;
        Neighbor* neighbor = g.getNeighbors(v);
        while (neighbor != nullptr) {
            int adjVertex = neighbor->dest;
            
            if (!visited[adjVertex]) {
                // Add edge to the DFS tree
                result.addEdge(v, adjVertex, neighbor->weight);
                
                // Recursively visit the adjacent vertex
                dfsVisit(g, adjVertex, visited, result);
            }
            
            neighbor = neighbor->next;
        }
    }
// Dijkstra's algorithm implementation
Graph Algorithms::dijkstra(const Graph& g, int start) {
    int numVertices = g.getNumVertices();
    
    // Create a new graph with the same number of vertices
    Graph result(numVertices);
    
    // Define infinity value
    const int INF = 1000000000;  // A large value to represent "infinity"
    
    // Create a priority queue
    PriorityQueue pq(numVertices);
    
    // Distance array
    int* distance = new int[numVertices];
    
    // Parent array to store the shortest path tree
    int* parent = new int[numVertices];
    
    // Initialize distances and parents
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;  // "Infinity"
        parent[i] = -1;     // No parent initially
    }
    
    // Distance to start vertex is 0
    distance[start] = 0;
    
    // Add all vertices to the priority queue
    for (int i = 0; i < numVertices; i++) {
        pq.insert(i, distance[i]);
    }
    
    // While priority queue is not empty
    while (!pq.isEmpty()) {
        // Extract vertex with minimum distance
        PQNode node = pq.extractMin();
        int u = node.vertex;
        
        // Process all neighbors of u
        Neighbor* neighbor = g.getNeighbors(u);
        
        while (neighbor != nullptr) {
            int v = neighbor->dest;
            int weight = neighbor->weight;
            
            // If there is a shorter path to v through u
            if (distance[u] != INF && 
                distance[u] + weight < distance[v]) {
                
                // Update distance of v
                distance[v] = distance[u] + weight;
                
                // Update parent of v
                parent[v] = u;
                
                // Update priority in queue
                if (pq.contains(v)) {
                    pq.decreasePriority(v, distance[v]);
                }
            }
            
            neighbor = neighbor->next;
        }
    }
    
    // Build the shortest path tree from the parent array
    for (int i = 0; i < numVertices; i++) {
        if (parent[i] != -1) {  // Skip the start vertex
            result.addEdge(parent[i], i, distance[i] - distance[parent[i]]);
        }
    }
    
    delete[] distance;
    delete[] parent;
    
    return result;
    }
Graph Algorithms:: prim(const Graph& g){
     int numVertices = g.getNumVertices();
    
    // Create a new graph with the same number of vertices
    Graph result(numVertices);
    
    // Define infinity value
    const int INF = 1000000000;  // A large value to represent "infinity"
    
    // Create a priority queue
    PriorityQueue pq(numVertices);

    // To keep track of vertices included in MST
    bool* inMST = new bool[numVertices];

    // Key values used to pick minimum weight edge
    int* key = new int[numVertices];

    // Parent array to store the MST
    int* parent = new int[numVertices];

    // Initialize all keys as INFINITE and not in MST
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        inMST[i] = false;
    }
    // Always include first vertex in MST
    // Make key 0 so that this vertex is picked first
    int startVertex = 0;  // Can be any vertex
    key[startVertex] = 0;
    parent[startVertex] = -1; // First node is root of MST

    // Add all vertices to the priority queue
    for (int i = 0; i < numVertices; i++) {
        pq.insert(i, key[i]);
    }
    // While priority queue is not empty
    while(!pq.isEmpty()){
        // Extract minimum key vertex
        PQNode node  = pq.extractMin();
        int u = node.vertex;
    // add to MST
    inMST[u] = true;

    // Process all neighbors of u
    Neighbor* neighbor = g.getNeighbors(u);

     while (neighbor != nullptr) {
            int v = neighbor->dest;
            int weight = neighbor->weight;
     
    // If v is not in MST and weight of (u,v) is less than key of v
            if (!inMST[v] && weight < key[v]) {
                // Update key of v
                key[v] = weight;
                
                // Update parent of v
                parent[v] = u;
                
                // Update priority in queue
                if (pq.contains(v)) {
                    pq.decreasePriority(v, weight);
                }
            }
            
            neighbor = neighbor->next;        
            
            }
    
        }
         // Build the MST from the parent array
        for (int i = 0; i < numVertices; i++) {
            if (parent[i] != -1) {  // Skip the root
                result.addEdge(parent[i], i, key[i]);
            }
        }
        delete[] inMST;
        delete[] key;
        delete[] parent;

        return result;
    }

Graph Algorithms:: kruskal(const Graph& g){
    int numVertices = g.getNumVertices();

    // Create a new graph for the MST
    Graph result(numVertices);

    // Create a list to store all edges
    // Here we'll use a simple array and track the count
    struct Edge{
        int src,dest,weight;
        Edge(): src(0),dest(0),weight(0){}
        Edge(int s, int d, int w) : src(s), dest(d), weight(w){}
    };
    // Count number of edges
    int edgeCount = 0;
    for (int i = 0; i < numVertices; i++) {
    Neighbor* neighbor = g.getNeighbors(i);
    while (neighbor != nullptr){
    // Count only edges where src < dest to avoid duplicates in undirected graph
        if(i<neighbor -> dest){
                edgeCount++;
            }
        neighbor = neighbor -> next;
        }
    
    }
    // Allocate edge array
    Edge* edges = new Edge[edgeCount];

    // Fill the edge array  
    int edgeIndex = 0;
    for (int i = 0; i < numVertices; i++) { 
            Neighbor* neighbor = g.getNeighbors(i);
             while (neighbor != nullptr) {
                // Add only edges where src < dest to avoid duplicates
                if (i < neighbor->dest) {
                    edges[edgeIndex++] = Edge(i, neighbor->dest, neighbor->weight);
                }
                neighbor = neighbor->next;
            }
        }         
    // Sort edges by weight (simple bubble sort for simplicity)
    for(int i = 0; i < edgeCount -1; i++){
        for(int j =0 ; j < edgeCount - 1 - i; j++){
            if(edges[i].weight > edges[j+1].weight){
        
        // Swap
        Edge temp = edges[j];
        edges[j] = edges[j+1];
        edges[j+1] = temp;
            }
        }
    }
    // Create a UnionFind data structure
    UnionFind uf(numVertices);

    // Process edges in order of increasing weight
    for (int i = 0 ; i < edgeCount ; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            
            // If including this edge doesn't cause a cycle 
            if(!uf.sameSet(src,dest)){
            
            // Add to MST
            result.addEdge(src,dest,edges[i].weight);

            //Merge sets
            uf.unionSets(src,dest);
            }

        }
    delete[] edges;
    return result;    



    }
}
