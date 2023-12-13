#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> heap;

    // Helper function to perform "sink down" operation
    void sinkDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int highestPriority = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[highestPriority]) {
            highestPriority = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[highestPriority]) {
            highestPriority = rightChild;
        }

        if (highestPriority != index) {
            std::swap(heap[index], heap[highestPriority]);
            sinkDown(highestPriority);
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
    PriorityQueue() : heap(std::vector<int>()) {}

    // Insert an element with priority into the Priority Queue
    void insert(int value) {
        heap.push_back(value);
        swimUp(heap.size() - 1);
    }

    // Extract and return the element with the highest priority
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Priority Queue is empty!" << std::endl;
            return -1; // Assuming -1 as an invalid value
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        sinkDown(0);

        return maxValue;
    }

    // Display the elements of the Priority Queue
    void display() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue priorityQueue;

    // Insert values into the Priority Queue with priorities
    priorityQueue.insert(10);
    priorityQueue.insert(20);
    priorityQueue.insert(15);
    priorityQueue.insert(25);
    priorityQueue.insert(40);
    priorityQueue.insert(50);

    // Display the Priority Queue
    std::cout << "Priority Queue: ";
    priorityQueue.display();

    // Extract and display the element with the highest priority
    std::cout << "Extracted Max Value: " << priorityQueue.extractMax() << std::endl;

    // Display the Priority Queue after extraction
    std::cout << "Priority Queue after extraction: ";
    priorityQueue.display();

    return 0;
}

