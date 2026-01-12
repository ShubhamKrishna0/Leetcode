#include <bits/stdc++.h>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    /*
val: An integer variable storing the node's value.
next: A pointer to the next node in the linked list (or NULL if it's the last node).
    */
    ListNode(int data1) {
        val = data1;
        next = NULL;
/*
This constructor initializes the node with a value (data1)
and sets next to NULL, making it a standalone node.*/
    }
    ListNode(int data1 , ListNode* next1){
        val = data1;
        next = next1;
        /*
        This constructor initializes the node with a value (data1) and a pointer to the
         next node (next1). This helps when linking nodes while constructing a list.
        */
    }
};

class Solution{
    public:
    ListNode* insertAtTail(ListNode* &head ,int X) {
        if(head==NULL)
            return new ListNode(X);

        ListNode *temp = head;
        while(temp->next!= NULL) {
            temp = temp->next;   
        }
        ListNode *newNode = new ListNode(X);
        temp->next = newNode;
        return head;

    }
};

void printLL(ListNode* head) {
    while(head !=NULL) {
        cout << head->val << " ";
        head = head->next;

    }
    cout << endl;

}

int main() {
    // Create a linked list from a vector
    vector<int> arr = {10, 20, 30};
    int val = 40;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    // Print the original list
    cout << "Original List: ";
    printLL(head);
    
    // Create a Solution object 
    Solution sol;
    head = sol.insertAtTail(head, val);

    // Print the modified linked list
    cout << "List after inserting the given value at the tail:";
    printLL(head);

    return 0;
}