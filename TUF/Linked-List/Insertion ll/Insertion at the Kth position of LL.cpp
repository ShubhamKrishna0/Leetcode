#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

// Solution class
class Solution {
public:
    // Function to insert a new node at the kth position 
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
       /* If the linked list is empty 
       and k is 1, insert the 
       new node as the head*/
        if (head == NULL) {
            if (K == 1)
                return new ListNode(X);
            else
                return head;
        }
    
        /*If K is 1, insert the new
         node at the beginning 
         of the linked list*/
        if (K == 1)
            return new ListNode(X, head);
    
        int cnt = 0;
        ListNode* temp = head;
    
       /* Traverse the linked list 
       to find the node at position k-1*/
        while (temp != NULL) {
            cnt++;
            if (cnt == K-1) {
               /* Insert the new node after the node 
               at position k-1*/
                ListNode* newNode = new ListNode(X, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    
        return head;
    }
};

// Helper Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list from a vector
    vector<int> arr = {10, 30, 40};
    int X = 20, K = 2;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    // Print the original list
    cout << "Original List: ";
    printLL(head);
    
    // Create a Solution object 
    Solution sol;
    head = sol.insertAtKthPosition(head, X, K);

    // Print the modified linked list
    cout << "List after inserting the given value at the Kth position: ";
    printLL(head);

    return 0;
}