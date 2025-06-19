#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    // Function to segragate odd and even indices nodes
    ListNode* oddEvenList(ListNode* head) {
        // Check if list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return head;

        // To store values
        vector<int> array;   
        ListNode* temp = head;

        /*Traverse the list, skipping one node, 
        and store values in the vector*/
        while (temp != NULL && temp->next != NULL) {
            array.push_back(temp->val);
            temp = temp->next->next;
        }

        /*If there's an even number 
        of nodes, add the value
         of the last node*/
        if (temp != NULL)
            array.push_back(temp->val);

        // Reset temp 
        temp = head->next;

        /*Traverse the list again, skipping one node 
       and store values 
        in the vector*/
        while (temp != NULL && temp->next != NULL) {
            array.push_back(temp->val);
            temp = temp->next->next;
        }

       /* If there's an odd number
        of nodes, add the 
        value of the last node*/
        if (temp != NULL)
            array.push_back(temp->val);

        // Reset temp 
        temp = head;
        int i = 0;

        // Update node values 
        while (temp != NULL) {
            temp->val = array[i];
            temp = temp->next;
            i++;
        }

        return head;
    }
};

// Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create a linked list with given values
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    head->next->next->next = new ListNode(arr[3]);
    head->next->next->next->next = new ListNode(arr[4]);
    head->next->next->next->next->next = new ListNode(arr[5]);

    // Rearrange the list and print it
    Solution solution;
    head = solution.oddEvenList(head);
    printLL(head);

    return 0;
}