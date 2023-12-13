#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper function to perform "sink down" operation
    void sinkDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            sinkDown(largest);
        }
    }

    // Helper function to perform "swim up" operation
    void swimUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    // Constructor
    MaxHeap() : heap(std::vector<int>()) {}

    // Insert a value into the Max Heap
    void insert(int value) {
        heap.push_back(value);
        swimUp(heap.size() - 1);
    }

    // Extract and return the maximum value from the Max Heap
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1; // Assuming -1 as an invalid value
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        sinkDown(0);

        return maxValue;
    }

    // Display the elements of the Max Heap
    void display() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert values into the Max Heap
    for(int i = 0; i < 20; i ++)
    {
        maxHeap.insert(i);
    }

    // Display the Max Heap
    std::cout << "Max Heap: ";
    maxHeap.display();

    // Extract and display the maximum value
    std::cout << "Extracted Max Value: " << maxHeap.extractMax() << std::endl;

    // Display the Max Heap after extraction
    std::cout << "Max Heap after extraction: ";
    maxHeap.display();

    return 0;
}

