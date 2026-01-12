#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

// Solution class
class Solution {
public:
    // Function to delete the tail of a doubly linked list 
    ListNode* deleteTail(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;  
        }
        
        // Navigate to the tail of the linked list
        ListNode* tail = head;
        while (tail->next != nullptr) 
            tail = tail->next; 
        
        // Update the pointers
        ListNode* newTail = tail->prev;
        newTail->next = nullptr;
        tail->prev = nullptr;
        
        // Free memory 
        delete tail;  
        
        return head; // Return head of modified list
    }
};

// Helper Function to convert an array to a doubly linked list
ListNode* arrayToLinkedList(vector<int> &nums) {
    // If array is empty, return nullptr
    if (nums.empty()) return nullptr; 

    // Create head node with first element of the array
    ListNode* head = new ListNode(nums[0]); 
    // Initialize 'prev' to the head node
    ListNode* prev = head;             

    for (int i=1; i < nums.size(); i++) {
        // Create a new node 
        ListNode* temp = new ListNode(nums[i], nullptr, prev);
        // Update 'next' pointer
        prev->next = temp;    
        // Move 'prev' to newly created node
        prev = temp;         
    }
    
    // Return head
    return head;  
}

// Helper Function to print the linked list
void printLL(ListNode* head) {
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
    
    // Function call to delete the tail of the doubly linked list
    head = sol.deleteTail(head);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}