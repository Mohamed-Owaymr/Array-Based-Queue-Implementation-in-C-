# 🟢 Queue Implementation Using Array in C++

## 📋 Project Overview
This project demonstrates how to implement a **Queue** data structure using a static array in C++.  
A Queue is a **FIFO (First-In-First-Out)** data structure where elements are added at the **rear** and removed from the **front**.  
This implementation handles edge cases like empty and full queues and provides simple test cases to practice operations. 🛠️

## ⚡ Features
- ➕ **Enqueue**: Add an element to the rear of the queue.
- ➖ **Dequeue**: Remove the front element from the queue.
- 👀 **Peek**: View the front element without removing it.
- ✅ **isEmpty**: Check if the queue is empty.
- ❌ **isFull**: Check if the queue is full.
- 📏 **getSize**: Get the current number of elements in the queue.
- 🖥️ **display**: Print all elements in the queue in order.

## ⏱️ Complexity
| Operation | Time Complexity |
|-----------|----------------|
| enqueue   | O(1)           |
| dequeue   | O(1)           |
| peek      | O(1)           |
| isEmpty   | O(1)           |
| isFull    | O(1)           |
| getSize   | O(1)           |
| display   | O(n)           |

## 🎨 ASCII + Emoji Representation of Queue

### 🟡 Initial empty queue
```
[Queue is empty] ⚪
```

### 🟢 After enqueue(10)
```
Front -> [10] <- Rear 🔵
```

### 🟡 After enqueue(20, 30)
```
Front -> [10] [20] [30] <- Rear 🔵
```

### 🔴 After dequeue() (removing 10)
```
Front -> [20] [30] <- Rear 🔵
```

💡 Notes:
- `Front` always points to the first element to be dequeued. 🔝
- `Rear` always points to the last element enqueued. 🔚
- Queue grows from front ➡️ rear.
- When the queue is empty ⚪, both front and rear are reset for the next enqueues.

## 🏋️ How to Practice with This Project
1. Study the `MyQueue` class and understand how `frontIndex`, `rearIndex`, and `size` are used.
2. Test adding elements (`enqueue`) and removing elements (`dequeue`) in different scenarios:
   - Empty queue ⚪
   - Partially filled queue 🟡🟢
   - Full queue 🔴
3. Observe the queue behavior using the `display()` method after each operation. 🖥️
4. Try triggering exceptions intentionally:
   - Dequeue or peek from an empty queue. ⚠️
   - Enqueue into a full queue. ⚠️
5. Modify the array size or use different data types using templates to practice generic programming in C++. 🧩

## 🎯 Learning Goals
- Understand how a queue works internally using arrays. 📚
- Learn to manage indexes (`frontIndex` and `rearIndex`) and size correctly. 🧮
- Learn to handle edge cases and exceptions in C++. 🚨
- Practice template usage to implement generic data structures. 🏗️
- Improve debugging and testing skills by writing meaningful test cases in `main()`. 🧑‍💻
