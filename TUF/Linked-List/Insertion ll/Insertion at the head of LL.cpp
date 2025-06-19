#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }//for the partwhich we have to add
    ListNode(int data1, ListNode *next1){
        val = data1;
        next = next1;   
    }
};
class Solution {
    public:
    ListNode* insertAtHead(ListNode* head ,int X) {
        ListNode *newnode = new ListNode(X);

        newnode->next = head;
        head = newnode;
        return head;

    }
};

void printLL(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {20, 30, 40};
    int X = 10;
    ListNode *head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);

    cout << "Original List ";
    printLL(head);

    Solution sol;
    head = sol.insertAtHead(head, X);

    cout << "List after inserting the given value at head :";
    printLL(head);
    return 0;
}