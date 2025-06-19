#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    
    // Constructors for easy initialization
    ListNode(): val(0), next(nullptr) {}
    ListNode(int data): val(data), next(nullptr) {}
    ListNode(int data, ListNode *nextNode): val(data), next(nextNode) {}
};

class Solution {
public:
    // Function to delete the head node of the linked list
    ListNode* deleteHead(ListNode* head) {
        if (!head) return nullptr; // If list is empty, return null
        
        ListNode* temp = head;  // Store current head
        head = head->next;      // Move head to next node
        delete temp;            // Delete old head node
        return head;            // Return new head
    }
};

// Function to print the linked list   
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the beginning of the linked list
ListNode* insertAtHead(ListNode* head, int data) {
    return new ListNode(data, head); // Create new node with head as next
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> NULL
    ListNode* head = nullptr;
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);

    cout << "Original list: ";
    printList(head);
    
    Solution sol;
    
    // Delete the head node
    head = sol.deleteHead(head);

    cout << "List after deleting head: ";
    printList(head);

    return 0;
}
