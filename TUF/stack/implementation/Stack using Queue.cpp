#include<bits/stdc++.h>
using namespace std ;


class ArrayQueue {
    int *arr;
    int start , end;
    int currSize, maxSize;


    public:
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }
    void push(int x ){
        if(currSize == maxSize) {
            cout << "Queue is Full\nExiting ..." << endl;
            exit(1);
        }
        if(end == -1) {
            start = 0;
            end = 0;
        }else{
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize++;
    }
    int pop() {
        if(start ==-1){
            cout << "Queue Empty\nExiting...." << endl;
            exit(1);
        }
        int popped = arr[start];
        if(currSize == 1) {
            start = -1;
            end = -1;
        }else{
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }
    int peek() {
        if(start == -1){
            cout << "Queue is Empty " << endl;
            exit(1);
        }
        return arr[start];
    }
    bool isEmpty() {
        return (currSize == 0);
    }
};
