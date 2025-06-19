#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int data1) {
        val = data1;
        next = null;
    }
    ListNode(int data1 , ListNode* next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
    public:
    ListNode* addTwoNumber(ListNode* l1 , ListNode* l2) {
        ListNode *dummy = new ListNode();
        listNode *temp = dummy;
        int carry = 0;
        while((l1!=NULL || l2!= NULL)|| carry){
            int sum = 0;

            if(l1 !=NULL) {
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2 !=NULL) {
                sum+= l2->val;
                l2 = l2->next;
            }

            sum += carry;

            carry = sum / 10;

            ListNode *node = new ListNode(sum % 10);
            temp->next = node;

            temp = temp->next;
        }
        return dummy->next;

    }
};

void printList(ListNode* head){
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;

    }
    cout << endl;
    
}