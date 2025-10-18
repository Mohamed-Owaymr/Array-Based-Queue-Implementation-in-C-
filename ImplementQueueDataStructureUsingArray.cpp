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
    cout << "🚀 Starting Circular Queue Tests...\n\n";

    // Test 1️⃣ : Enqueue elements normally
    cout << "🧩 Test 1: Enqueue 3 elements\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front Element 👀: " << q.peek() << endl << endl;

    // Test 2️⃣ : Dequeue one element
    cout << "🧩 Test 2: Dequeue 1 element\n";
    q.dequeue();
    q.display();
    cout << "Front Element 👀: " << q.peek() << endl << endl;

    // Test 3️⃣ : Enqueue again (check circular behavior)
    cout << "🌀 Test 3: Enqueue 2 more elements to test circular wrap\n";
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Queue Size 📏: " << q.getSize() << endl << endl;

    // Test 4️⃣ : Dequeue all to make queue empty
    cout << "🧩 Test 4: Dequeue all elements to test reset\n";
    while (!q.isEmpty()) {
        cout << "Dequeued 🔻: " << q.peek() << endl;
        q.dequeue();
    }
    q.display();
    cout << "Is Empty? 🤔 " << (q.isEmpty() ? "Yes ✅" : "No ❌") << endl << endl;

    // Test 5️⃣ : Try Dequeue on empty queue (expect error)
    cout << "⚠️ Test 5: Dequeue on empty queue (expect exception)\n";
    try {
        q.dequeue();
    } catch (const exception &e) {
        cout << "Caught Exception 💥: " << e.what() << endl << endl;
    }

    // Test 6️⃣ : Fill queue completely to test full condition
    cout << "🧩 Test 6: Fill the queue to its capacity\n";
    for (int i = 0; i < 10; ++i)  // using 10 to avoid long output
        q.enqueue(i + 1);
    q.display();
    cout << "Queue Size 📏: " << q.getSize() << endl;
    cout << "Is Full? 🏋️ " << (q.isFull() ? "Yes ✅" : "No ❌") << endl << endl;

    // Test 7️⃣ : Enqueue when full (expect error)
    cout << "⚠️ Test 7: Enqueue on full queue (expect exception)\n";
    try {
        q.enqueue(999);
    } catch (const exception &e) {
        cout << "Caught Exception 💥: " << e.what() << endl << endl;
    }

    cout << "🏁 All Tests Completed Successfully!\n";
    return 0;
}
