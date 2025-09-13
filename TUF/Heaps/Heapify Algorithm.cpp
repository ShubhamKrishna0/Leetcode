#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:
    void heapifyDown(vector<int> &arr , int ind) {
        int n = arr.size();
        int smallest_Ind = ind;

        int leftChild_Ind = 2 * ind + 1, rightChild_Ind = 2 * ind + 2;

        if(leftChild_Ind < n && arr[leftChild_Ind] < arr[smallest_Ind])
            smallest_Ind = leftChild_Ind;

        if(rightChild_Ind < n && arr[rightChild_Ind] < arr[smallest_Ind])
            smallest_Ind = rightChild_Ind;

        if(smallest_Ind != ind) {
            swap(arr[smallest_Ind], arr[ind]);

            heapifyDown(arr, smallest_Ind);
        }
        return;
    }
    //function to recursively heapify the array upwards
    void heapifyUp(vector<int> &arr , int ind) {
        int parent_Ind = (ind - 1) / 2;

        //if current index holds 
        if(ind>0 && arr[ind] < arr[parent_Ind]){
            swap(arr[ind], arr[parent_Ind]);
            heapifyUp(arr, parent_Ind);
        }
        return;
    }

    public:
    void heapify (vector<int> &nums , int ind , int val) {
        if(nums[ind] > val) {
            nums[ind] = val;
            heapifyUp(nums, ind);

        }else{
            nums[ind] = val;
            heapifyDown(nums, ind);

        }
        return;
    }
};