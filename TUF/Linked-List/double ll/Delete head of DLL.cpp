#include <bits/stdc++.h>
using namespace std;

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
    ListNode(int data, ListNode *next1, ListNode *prev1)
    {
        val = data;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    ListNode *deleteHead(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // store current head as prev
        ListNode *prev = head;

        // move head to next node
        head = head->next;

        // set prev pointer
        head->prev = nullptr;

        // set next pointer
        prev->next = nullptr;

        // return new head
        return head;
    }
};

// Helper Function to convert an array to a double linkedlist
ListNode *arrayToLinkedList(vector<int> &nums)
{
    // if array is empty, return nullptr
    if (nums.empty())
        return nullptr;

    // create head node with first elements of the array
    ListNode *head = new ListNode(nums[0]);

    // initialize 'prev' to head node
    ListNode *prev = head;

    for (int i = 1; i < nums.size(); i++)
    {
        // create a new node
        ListNode *temp = new ListNode(nums[i], nullptr, prev);
        // update 'next' pointer
        prev->next = temp;
        // move 'prev' to newly created node
        prev = temp;
    }
    return head;
}

// Helper Function to print the linked list
void printLL(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    // Creating the doubly linked list from given array
    ListNode *head = arrayToLinkedList(nums);

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
