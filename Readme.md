[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Isabella Soriano

## Description
This project uses Prim's Algorithm to find the Minimum Spanning Tree (MST) of a graph, which means it connects all points with the smallest total edge weight. It uses a a Min Heap to manage connections efficiently, and stores the graph as an adjacency matrix.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis

| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log n)        |
| Extract Min          | O(log n)        |
| Decrease Key         | O(log n)        |
| Prim’s MST Overall   | O(v^2)          |

_Explain why your MST implementation has the above runtime._

When a new item is inserted into the heap, it might need to move up the structure to stay in the right order. This is often called “bubbling up,” and it takes about log(n) steps, where n is the number of items in the heap.

The operation extractMin, also takes about log(n) time. That’s because after removing the top of the heap, it has to replaced and then be reorganized to keep everything in order.

When decreasing a key, this also takes around log(n) steps because it uses the same process "bubbling up" like inserting a element.

Overall, Prim’s algorithm in this program runs in about O(n²) time. That’s because we use an adjacency matrix, which means for every vertex (n), we check its connection to every other vertex (therefore, n times n equaling n^2).


## Test Case Description

**Input: the graph provided has 5 vertices and the following edges --**

Edge (0,1) with weight 2

Edge (0,3) with weight 6

Edge (1,2) with weight 3

Edge (1,3) with weight 8

Edge (1,4) with weight 5

Edge (2,4) with weight 7

Edge (3,4) with weight 9

**Output: After the program is executed, the expected MST is --**

Edge 0-1 with weight 2

Edge 1-2 with weight 3

Edge 0-3 with weight 6

Edge 1-4 with weight 5

Total MST Cost: 16