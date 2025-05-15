#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"
using namespace std;

class Graph {
public:
    Graph(int vertices){
        this->numVertices = vertices;

        // Create 2D array for the adjacency matrix
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];

            // Initialize all edges to INF
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = NULL;
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight){
        // since the graph is undirected, both directions of edge are equal
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    // Must print MST edges and total weight
    void primMST(){
        // array to store constructed MST
        int* parent = new int[numVertices];

        // initialize all keys as INF
        int* key = new int[numVertices];

        // Create a min heap of size numVertices
        MinHeap minHeap(numVertices);

        // initialize min heap
        for (int v = 0; v < numVertices; v++) {
            parent[v] = -1;
            key[v] = INT_MAX;
        }

        // first, make key value 0
        key[0] = 0;

        // insert all vertices into the min heap
        for (int v = 0; v < numVertices; v++) {
            minHeap.insert(v, key[v]);
        }

        // while min heap is not empty
        while (!minHeap.isEmpty()) {
            // extract the vertex with min key value
            int u = minHeap.extractMin();

            // for each adjacent vertex v of u...
            for (int v = 0; v < numVertices; v++) {
                // If v is in min heap and weight of edge u-v is less than current key of v
                if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {

                    key[v] = adjMatrix[u][v];
                    parent[v] = u;

                    // Decrease key value in min heap
                    minHeap.decreaseKey(v, key[v]);
                }
            }
        }

        // print edges of MST
        cout << "Edge   Weight" << endl;
        int totalWeight = 0;

        for (int i = 1; i < numVertices; i++) {
            cout << parent[i] << " - " << i << "    " << adjMatrix[parent[i]][i] << endl;
            totalWeight += adjMatrix[parent[i]][i];
        }
        cout << "Total MST Cost: " << totalWeight << endl;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif