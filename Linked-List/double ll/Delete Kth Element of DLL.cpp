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
    // Function to remove the Kth element
    ListNode* deleteKthElement(ListNode* head, int k) {
        // If the list is empty, return nullptr
        if (head == nullptr) 
            return nullptr;
    
        int count = 0;
        ListNode* kNode = head;

        // Traverse the list
        while (kNode != nullptr) {
            count++;
            if (count == k) break;
            kNode = kNode->next;
        }

        // If k is larger 
        if (kNode == nullptr) return head; 
        
        // Update the pointers
        ListNode* prev = kNode->prev;
        ListNode* front = kNode->next;

        // If node to be deleted is only node in list
        if (prev == nullptr && front == nullptr) {
            delete kNode;
            return nullptr;
        }
        
        // If node to be deleted is head of list
        else if (prev == nullptr) {
            head = front;
            front->prev = nullptr;
        }
        
        // If node to be deleted is tail of list
        else if (front == nullptr) {
            prev->next = nullptr;
        }
        
        // If node to be deleted is in middle of list
        else {
            prev->next = front;
            front->prev = prev;
        }

        // Free memory of the deleted node
        delete kNode;
        
        // Return modified list head
        return head;
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
    int k = 2;
    
    // Creating the doubly linked list from given array
    ListNode* head = arrayToLinkedList(nums);
    
    // Print the Original list 
    cout << "Original List: ";
    printLL(head);
    
    // Create an instance of Solution class 
    Solution sol;
    
    // Function call to delete the kth Node of the doubly linked list
    head = sol.deleteKthElement(head, k);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}