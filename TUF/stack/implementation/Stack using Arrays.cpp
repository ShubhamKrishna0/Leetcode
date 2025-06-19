#include<bits/stdc++.h>
using namespace std ;

class ArrayStack{
private :
    //array that hold elements
    int *stackArray;

    //maximum capacity
    int capacity;

    //Index of top elements
    int topindex;

    public:
    //constructor
    ArrayStack(int size=1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }
    ~ArrayStack() {
        delete[] stackArray;
    }
    void push(int x) {
        if(topIndex >= capacity-1){
            cout << "Stack overFlow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    //Removes and returns top elements
    int pop () {
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    //Return top elements
    int top() {
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topindex];
    }

    bool isEmpty() {
        return topIndex == -1;

    }
};

int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < command.size();++i) {
        if(commands[i] == "push"){
            stack.push(inputs[i][0]);
            cout << "null";
        }else if(command[i] =="pop"){
            cout << stack.pop() << " ";
        }else if (commands[i] == "top"){
            cout << stack.top() << " ";
        }else if (command[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        }else if(command[i] =="ArrayStack") {
            cout << "null";
        }
    }
    return 0;
}

//time complexity = O(1)
//space complexity is O(N)