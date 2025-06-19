#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
    private:
        Node *start;
        Node *end;
        int size;

    public:
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }

    void push(int x) {
        //create a node
        Node *element = new Node(x);
        //if it is the first element being pushed
        if(start == NULL) {
            start = end = element;
        }
        else{
            end->next = element;
            end = element;
        }
        size++;
    }
    int pop() {
        if(start == NULL) {
            return -1;
        }
        int value = start->value;  //get the front value
        Node *temp = start;
        start = start->next;
        delete temp;
        size--;

        return value;
    }

    int peek() {
        if(start == NULL) {
            return -1;
        }
        return start->val; // return the top
    }

    bool isEmpty() {
        return (size == 0);

    }
};