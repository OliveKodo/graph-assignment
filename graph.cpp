#include "graph.hpp"
#include <iostream>

namespace graph {
Graph::Graph(int n) : numVertices(n) {
        if (n <= 0) {
            throw std::invalid_argument("Number of vertices must be positive");
        }
        adjList = new Neighbor*[n];
        for (int i = 0; i < n; i++) {
        adjList[i] = nullptr;
        }
    }
Graph::Graph(const Graph& other) : numVertices(other.numVertices) {

    adjList = new Neighbor*[numVertices];

    for(int i = 0; i< numVertices; i++){
        adjList[i] = nullptr;

        Neighbor* current = other.adjList[i];
        Neighbor** tail = &adjList[i];

        while(current != nullptr) {
            *tail = new Neighbor(current -> dest, current -> weight );
            tail = &((*tail)-> next);
            current = current -> next;

        }
    }
}
Graph& Graph::operator=(const Graph& other){
    if(this != &other){
    for(int i = 0; i< numVertices ; i++){
        Neighbor* current  = adjList[i];
        while(current != nullptr){
                Neighbor* temp = current;
                current = current-> next;
                delete temp;
            }
        }
        delete[] adjList;

        numVertices = other.numVertices;
        adjList = new Neighbor*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;
            Neighbor* current  = other.adjList[i];
            Neighbor** tail = &adjList[i];

            while(current != nullptr){
                *tail = new Neighbor(current-> dest, current -> weight);
                tail = &((*tail) -> next);
                current = current -> next;
            }
         }
    }
    return *this;
}
    void Graph::addEdge(int src, int dest, int weight = 1){
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices){
        throw std:: out_of_range("Vertex index out of range");
        } 
        if (hasEdge(src, dest)) {
        Neighbor* current  = adjList[src];
        while(current -> dest != dest ){
            current = current -> next;
        }
        current-> weight = weight;

        current = adjList[dest];
        while(current->dest != src){
            current = current -> next;  
        }
        current -> weight = weight;
    } else {
        adjList[src] = new Neighbor(dest, weight, adjList[src]);

        adjList[dest] = new Neighbor(dest,weight,adjList[dest]);
    }
    
}
    void Graph:: removeEdge(int src,int dest){
        
    }


    bool Graph::hasEdge(int src, int dest) const {
          if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        
        Neighbor* current = adjList[src];
        while (current != nullptr) {
            if (current->dest == dest) {
                return true;
            }
            current = current->next;
        }
        
        return false;
    }

}