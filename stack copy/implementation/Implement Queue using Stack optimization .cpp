#include<bits/stdc++.h>
using namespace std;

class StackQueue {
    public:
        stack<int> input, output;
        StackQueue() {}

        //Push element x to the back of the queue
        void push(int x) {
            input.push(x);
        }

    // Removes the element from in front of queue and returns that element
        int pop() {
            //shift input to output if output is empty
            if(output.empty()){
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }

            if(output.empty()){
                cout << "Queue is Empty , connot pop ." << endl;
                return -1;
            }

            int x = output.top();
            output.pop();
            return x;
        }
        int peek() {
            if(output.empty()) {
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }

            if(output.empty()){
                cout << "Queue is Empty , cannot peek . " << endl;
                return -1;
            }
            return output.top();
        }
        bool isEmpty() {
            return input.empty() && output.empty();
        }
};

int main() {
    StackQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

//T.c = O(1)
//s.c = O(2N)-----> where N is the total nimber of the elements in the queue. 