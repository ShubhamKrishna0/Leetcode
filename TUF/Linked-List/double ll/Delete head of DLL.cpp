#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1) { //Creates a node with a given val (data1) but next and prev are set to NULL.
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1 , ListNode* next1 , ListNode* prev1){
        val = data1;
        next = next1;
        prev = prev1;

    }
};

class Solution {
    public:
    ListNode* deleteHead(ListNode* head) {
        if(head == nullptr || head-> next == nullptr)
            return nullptr;
        ListNode *prev = head;
        head = head->next;
        head->prev = nullptr;
        prev->next = nullptr;
        return head;
    }
};


ListNode* arrayToLinkedList(vector<int> &nums){
    if(nums.empty())
    return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *prev = head;

    for (int i = 1; i <nums.size();i++){
        ListNode *temp = new ListNode(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void printLL (ListNode* head ) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // Creating the doubly linked list from given array
    ListNode* head = arrayToLinkedList(nums);
    
    // Print the Original list 
    cout << "Original List: ";
    printLL(head);
    
    // Create an instance of Solution class 
    Solution sol;
    
    // Function call to delete the head of the doubly linked list
    head = sol.deleteHead(head);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}