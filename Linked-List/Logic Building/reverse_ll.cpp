// 1-> 2 -> 3 -> 4 -> 5
// 5 - > 4 - > 3 -> 2 -> 1

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

class Solution
{
public:
    // function to reverse a linked list using the 3 - pointer approch
    ListNode *reverseList(ListNode *head)
    {
        // Initialize 'temp' at head of linked list
        ListNode *temp = NULL;
        // initialize pointer prev to null representing the previous node
        ListNode *prev = NULL;

        // traverse the list , continue till temp reaches the end (NULL)
        while (temp != NULL)
        {
            // store the next node in front to prevent the reference
            ListNode *front = temp->next;
            // reverse the direction of the current node next pointer to point to prev
            temp->next = prev;
            // move prev to the current node for the nect iteration
            prev = temp;
            // move temp to the front node advancing the traversal
            temp = front;
        }
        // return the new head of the reversed linked list
        return prev;
    }
};