//https://leetcode.com/problems/design-circular-queue/description/
/*
MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
*/
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        arraysize = k;
        cq.resize(k);
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            head = tail = 0;
            cq[tail] = value;
        } else {
            tail = (tail + 1) % arraysize;
            cq[tail] = value;
        }

        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % arraysize;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : cq[head];
    }

    int Rear() {
        return isEmpty() ? -1 : cq[tail];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == arraysize;
    }

private:
    int head = 0, tail = 0, size = 0, arraysize = 0;
    vector<int> cq;
};

int main() {
    MyCircularQueue q(3);
    cout << boolalpha;
    cout << q.enQueue(1) << endl; // true
    cout << q.enQueue(2) << endl; // true
    cout << q.enQueue(3) << endl; // true
    cout << q.enQueue(4) << endl; // false
    cout << q.Rear() << endl;     // 3
    cout << q.isFull() << endl;   // true
    cout << q.deQueue() << endl;  // true
    cout << q.enQueue(4) << endl; // true
    cout << q.Rear() << endl;     // 4
}

