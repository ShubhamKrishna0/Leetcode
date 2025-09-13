#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void heapifyDown(vector<int> &arr , int ind) {
        int n = arr.size();

        int smallest_Ind = ind;

        int leftChild_Ind = 2 * ind + 1, rightChild_Ind = 2 * ind + 2;

        if(leftChild_Ind < n && arr[leftChild_Ind] <arr[smallest_Ind])
            smallest_Ind = leftChild_Ind;
        
        if(rightChild_Ind < n && arr[rightChild_Ind]  < arr[smallest_Ind])
            smallest_Ind = rightChild_Ind;
        
        if(smallest_Ind != ind){
            swap(arr[smallest_Ind], arr[ind]);
            heapifyDown(arr, smallest_Ind);
        }
        return;
    }
    public:
    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(nums, i);
        }
        return;
    }
};