#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode():val(0),next(nullptr){}
    ListNode(int data1):val(data1),next(nullptr){}
    ListNode(int data1,ListNode *next1):val(data1),next(next1){}
};
/*
Each ListNode contains:

An integer value (val).
A pointer to the next node (next).

There are three constructors:

Default constructor initializes val = 0 and next = nullptr.
Parameterized constructor initializes val with data1 and sets next = nullptr.
Parameterized constructor initializes val with data1 and assigns a given next pointer.
*/

class Solution{
    public:
        ListNode *deleteKthNode(ListNode* head ,int k) {
            if(head == NULL)
                return NULL;

                if(k==1){
                    ListNode *temp = head;
                    head = head->next;
                    delete temp;
                    return head;   
                }
////
                ListNode *temp = head;
                for (int i = 0; temp != NULL && i < k - 2; i++) { // as starting from 0
                    temp = temp->next;
                }
                    if(temp ==NULL || temp->next == NULL ) // for large no it directly show the null ptr
                        return head;

                    ListNode *next = temp->next->next;
                    delete temp->next;
                    temp->next = next;

                    return head;

                }
        };

        void printLL(ListNode* head) {
            ListNode *current = head;
            while(current != nullptr) {
                cout << current->val << " ";
                current = current->next;
            }
            cout << endl;
        }

        int main () {
            vector<int> arr = {12, 5, 8, 7};

            ListNode *head = new ListNode(arr[0]);
            head->next = new ListNode(arr[1]);
            head->next->next = new ListNode(arr[2]);
            head->next->next->next = new ListNode(arr[3]);

            cout << "original List :";
            printLL(head);

            Solution sol;

            int k = 2;
            head = sol.deleteKthNode(head, k);

            cout << "List after deleting the Kth Node : ";
            printLL(head);

            return 0;
        }
