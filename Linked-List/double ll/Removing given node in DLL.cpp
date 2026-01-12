#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    listNode(){
        val = 0;
        next = NULL;
        prev = NULL;

    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        prev = NULL;

    }
    ListNode(int data1 , listNode* next1 , ListNode* prev1){
        val = data1;
        next = next1;
        prev = prev1;

    }
};

class Solution {
    public:
    void deleteGivenNode(ListNode* node) {
        ListNode *prev = node->prev;
        ListNode *front = node->next;

        if(front == nullptr) {
            prev->next = nullptr;
            node->prev = nullptr;
            delete node;
            return;
        }

        prev->next = front;
        front->prev = prev;

        node->prev = nullptr;
        node->prev = nullptr;

        delete node;
    }
};

