#include <bits/stdc++.h>
using namespace std;

// Queue implementation using stack
class StackQueue {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue () {
        
    }
    
    // Method to push elements in the queue
    void push(int x) {
        /* Pop out elements from the first stack 
        and push on top of the second stack */
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Insert the desired element
        st1.push(x);
        
        /* Pop out elements from the second stack 
        and push back on top of the first stack */
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop element from the queue
    int pop() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    
    // Method to get the front element from the queue 
    int peek() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Return the top element
        return st1.top();
    }
    
    // Method to find whether the queue is empty
    bool isEmpty() {
        return st1.empty();
    }
};

int main() {
    StackQueue q;

    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}
//t.c=(o(N))
//s.c= O(2(N))