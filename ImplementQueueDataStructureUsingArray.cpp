#include <iostream>
using namespace std;

const size_t MAX_QUEUE_SIZE = 100;

template <typename Type>
class MyQueue {
private:
    Type array[MAX_QUEUE_SIZE];
    int frontIndex;
    int rearIndex;
    size_t size;
    size_t capacity;


    // Reset indecies in Queue if Queue become empty.
    // complexity O(1) : constant time complexity.
    void resetIfEmpty() {
        if(isEmpty()) {
            frontIndex = 0;
            rearIndex  = -1;
        }
    }

public:
    MyQueue() : frontIndex(0) , rearIndex(-1) , size(0) , capacity(MAX_QUEUE_SIZE) {}

    // Check if Queue have no element.
    // complexity O(1) : constant time complexity.
    bool isEmpty() const {
        return size == 0;
    }

    // Check if Queue is full of elements.
    // complexity O(1) : constant time complexity.
    bool isFull() const {
        return size == capacity;
    }

    // Check if Queue is full of elements.
    // complexity O(1) : constant time complexity.
    size_t getSize() const {
        return size;
    }    

    // Add element to Rear of Queue.
    // complexity O(1) : constant time complexity.
    void enqueue(const Type& element) {
        if(isFull()) {
            throw runtime_error("Error! Enqueue on full queue.");
        }
        rearIndex = rearIndex = (rearIndex + 1) % capacity;
        array[rearIndex] = element;
        ++size;
    }

    // Remove element from front of Queue.
    // complexity O(1) : constant time complexity.
    void dequeue() {
        if(isEmpty()) {
            throw runtime_error("Error! Dequeue on empty queue.");
        } 
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        resetIfEmpty();      
    }

    // Return the front element .
    // complexity O(1) : constant time complexity.
    Type peek() const {
        if(isEmpty()) {
            throw runtime_error("Error! Peek on empty queue.");
        }
        return array[frontIndex]; 
    }

    // Display all elements in Queue
    // complexity O(n) : linear time complexity.
    void display() const {
        if (isEmpty()) {
            cout << "[Queue is empty]" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (size_t i = 0; i < size; ++i) {
            cout << array[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }

};







// Test For My Queue
int main() {
    MyQueue<int> q;

    cout << "=== Queue Test Start ===\n";

    // Test 1: Check if the queue is empty initially
    cout << "Test 1: isEmpty() -> " << (q.isEmpty() ? "true" : "false") << endl;

    // Test 2: Try to dequeue from an empty queue -> should throw exception
    try { 
        q.dequeue(); 
    } 
    catch (const exception& e) { 
        cout << "Test 2: dequeue empty -> Exception: " << e.what() << endl; 
    }

    // Test 3: Try to peek at the front element of an empty queue -> should throw exception
    try { 
        q.peek(); 
    } 
    catch (const exception& e) { 
        cout << "Test 3: peek empty -> Exception: " << e.what() << endl; 
    }

    // Test 4: Enqueue a single element
    q.enqueue(10);
    cout << "Test 4: enqueue(10) -> success\n";

    // Check the front element after enqueue
    cout << "Peek after enqueue: " << q.peek() << endl;

    // Display the current queue contents
    q.display();

    // Test 5: Enqueue two more elements
    q.enqueue(20);
    q.enqueue(30);
    cout << "Test 5: enqueue(20,30) -> success\n";

    // Display the current queue contents
    q.display();

    // Test 6: Dequeue one element
    q.dequeue();
    cout << "Test 6: dequeue() -> success\n";

    // Display the queue after dequeue
    q.display();

    // Test 7: Check the current size of the queue
    cout << "Current size: " << q.getSize() << endl;

    cout << "=== Queue Test End ===\n";
    return 0;
}
