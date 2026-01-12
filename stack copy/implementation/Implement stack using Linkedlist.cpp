#include <bits/stdc++.h>
using namespace std;
//Node structure
struct Node{
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};
class LinkedListStack{
    private:
        Node *head; //top of the stack
        int size; //stack
        public:
        //constructor 
        LinkedListStack() {
            head = NULL;
            size = 0;
        }

        void push(int x) {
            Node *element = new Node(x);

            element->next = head;
            head = element;
            size++;
        }
        int pop() {
            if(head == NULL) {
                return -1;
            }
            int value = head->val; // get the top value
            Node *temp = head; // store the top temporarily
            head = head->next;
            delete temp;
            size--;

            return value;
        }
        int top() {
            if(head == NULL){
                return -1;
            }
            return head->val; // return the top
        }
        bool isEmpty() {
            return (size == 0);
        }
};