#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode (int data1):val(data1),next(NULL){}
    ListNode(int data1 , ListNode *next1):val(data1),next(next1){}
};

class Solution {
    public:
    ListNode* deleteNodeWithValueX(ListNode* &head, int X )  {
        if(head == NULL)
            return head;

    if(head->val == X) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode *temp = head;
    ListNode *prev = NULL; 

    while (temp != NULL) {
        if(temp->val == X) {
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
    }
};

void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr = {0, 1, 2};
    int X = 1;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    

    cout << "Original List: ";
    printLL(head);
    
 
    Solution sol;
    head = sol.deleteNodeWithValueX(head, X);


    cout << "List after deleting the given value: ";
    printLL(head);

    return 0;
}