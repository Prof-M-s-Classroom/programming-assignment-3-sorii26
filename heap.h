#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        // initialize all keys as infinite and positions as -1
        for (int i = 0; i < capacity; i++) {
            keyArray[i] = INT_MAX;
            position[i] = -1;
        }
    }

    ~MinHeap(){
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (size == capacity) return;

        // start at the end of the heap
        int i = size;
        heapArray[i] = vertex;
        keyArray[vertex] = key;
        position[vertex] = i;
        size++;

        // fix the min heap property if violated (bubble up)
        while (i && keyArray[heapArray[i]] < keyArray[heapArray[parent(i)]]) {
            // swap i with parent
            position[heapArray[i]] = parent(i);
            position[heapArray[parent(i)]] = i;
            swap(&heapArray[i], &heapArray[parent(i)]);

            // move to parent index
            i = parent(i);
        }
    }

    int extractMin() {
        if (isEmpty()) return -1;

        // store the root which has min key
        int root = heapArray[0];

        // replace root with the last element
        heapArray[0] = heapArray[size - 1];
        position[heapArray[0]] = 0;

        // reduce heap size and heapify root
        size--;
        position[root] = -1;
        minHeapify(0);

        return root;
    }

    void decreaseKey(int vertex, int newKey) {
        // get the index of v in heap array
        int i = position[vertex];

        // update the key
        keyArray[vertex] = newKey;

        // fix the min heap property if violated (bubble up)
        while (i && keyArray[heapArray[i]] < keyArray[heapArray[parent(i)]]) {
            // swap with parent
            position[heapArray[i]] = parent(i);
            position[heapArray[parent(i)]] = i;
            swap(&heapArray[i], &heapArray[parent(i)]);

            // move to parent index
            i = parent(i);
        }
    }

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1;
    }

    bool isEmpty(){
        return size == 0;
    }


private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        int smallest = idx;
        int l = left(idx);
        int r = right(idx);

        if (l < size && keyArray[heapArray[l]] < keyArray[heapArray[smallest]])
            smallest = l;

        if (r < size && keyArray[heapArray[r]] < keyArray[heapArray[smallest]])
            smallest = r;

        if (smallest != idx) {
            // update positions
            position[heapArray[idx]] = smallest;
            position[heapArray[smallest]] = idx;

            // recursively heapify the affected subtree
            minHeapify(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

#endif