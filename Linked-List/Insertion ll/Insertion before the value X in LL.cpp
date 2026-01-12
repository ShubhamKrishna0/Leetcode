#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next; 
    ListNode (int data1){
        val = data1;
        next = NULL;
    }
    ListNode(int data1 ,ListNode* next1) {
        val = data1;
        next = next1;

    }
};

class Solution {
    public:
    ListNode* insertBeforeX(ListNode* &head , int X , int val){
        if(head ==NULL){
            return NULL;
        }
        //insert at  the beginning of the  of the 
        if(head->val==X)
            return new ListNode(val, head);

        ListNode *temp = head;
        while(temp->next!=NULL){
            if(temp->next->val == X){
                ListNode *newNode = new ListNode(val, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

void printLL(ListNode* head) {
    while(head!= NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    vector<int> arr = {1, 2, 4, 5};
    int X = 4, val = 3;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    

    cout << "Original List: ";
    printLL(head);
    

    Solution sol;
    head = sol.insertBeforeX(head, X, val);

  
    cout << "List after inserting a new node before the given node: ";
    printLL(head);

    return 0;
}