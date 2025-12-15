#include <bits/stdc++.h>
using namespace std;

// definition of singly linked list
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
    // function to segragate odd and even indices nodes
    ListNode *oddEvenList(ListNode *head)
    {
        // check if list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return head;

        // TO store values
        vector<int> array;
        ListNode *temp = head;

        // traverse the list , skipping one node  ,  store value in the vector
        while (temp != NULL && temp->next != NULL)
        {
            array.push_back(temp->val);
            temp = temp->next->next;
        }

        // if the traversal ends on the valid
        //  odd- indexed node , include its value as well
        if (temp != NULL)
            array.push_back(temp->val);

        // reset the temp
        temp = head->next;

        while (temp != NULL && temp->next != NULL)
        {
            array.push_back(temp->val);
            temp = temp->next->next;
        }

        if (temp != NULL)
            array.push_back(temp->val);

        // Reset the temp
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp->val = array[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};

void printLL(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}