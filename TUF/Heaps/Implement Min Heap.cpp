#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> arr; //list to store the min heap
        int count; //to store the current of the elemnts in the minheap

        void heapifyUp(vector <int> &arr , int ind) {
            int parentsInd = (ind - 1) / 2;

            if(ind>0 && arr[ind] <arr[parentsInd]) {
               swap(arr[ind], arr[parentsInd]);

               heapifyUp(arr, parentsInd);
            }
            return;
        }
};