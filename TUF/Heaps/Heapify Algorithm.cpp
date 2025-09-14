#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:
        vector<int> arr; //list to store the min heap
        int count; //to store the current of the elements in the minheap

        void heapifyUp(vector <int> &arr , int ind) {
            int parentsInd = (ind - 1) / 2;

            if(ind>0 && arr[ind] <arr[parentsInd]) {
               swap(arr[ind], arr[parentsInd]);

               heapifyUp(arr, parentsInd);
            }
            return;
        }

        void heapifyDown(vector<int> &arr , int ind) {
            int n = arr.size();

            int smallestInd = ind;
            int leftChildInd = 2 * ind + 1, rightChildInd = 2 * ind + 2;

            if(leftChildInd < n &&  arr[leftChildInd] <arr[smallestInd])
                smallestInd = leftChildInd;
            
            if(rightChildInd < n && arr[rightChildInd] < arr[smallestInd])
                smallestInd = rightChildInd;


                if(smallestInd != ind) {
                    swap(arr[smallestInd], arr[ind]);

                    heapifyDown(arr, smallestInd);
                }

                return;
        }

        public:
        void initializeHeap() {
            arr.clear();
            count = 0;
        }

        void insert(int key) {
            arr.push_back(key);
            heapifyUp(arr, count);
            count = count + 1;
            return;
        }
        
        void changeKey(int index , int new_val) {
            if(arr[index] > new_val) {
            arr[index] = new_val;
            heapifyUp(arr, index);
            }else{
                arr[index] = new_val;
                heapifyDown(arr, index);
            }
            return;
        }
// method to extract the minimum value from the min-heap
        void extractMin() {
            int ele = arr[0] ;
            swap(arr[0], arr[count - 1]);

            arr.pop_back();
            count = count - 1;

            heapifyDown(arr, 0);
        }

        bool isEmpty() {
            return (count == 0);
        }

        int getMin() {
            return arr[0];
        }
        int heapSize() {
            return count;
        }
};