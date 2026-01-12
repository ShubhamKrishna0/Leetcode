#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> arr;
        int count;

        //function to recursivly heapify the arrat upward
        void heapifyUp(int ind) {
            int parentInd = (ind - 1) / 2;

            //if current index holds larger value than the parent
            if(ind > 0  && arr[ind] > arr[parentInd]) {
                swap(arr[ind], arr[parentInd]);
                heapifyUp(parentInd);
            }
            return;
        }

        void heapifyDown(int ind) {
            int n = arr.size();
            int largestInd = ind;

            int leftChildren = 2 * ind + 1, rightChildren = 2 * ind + 2;

            if(leftChildren < n && arr[leftChildren] > arr[largestInd])
                largestInd = leftChildren;
            
            if(rightChildren < n && arr[rightChildren] > arr[largestInd])
                largestInd = rightChildren;

            if (largestInd != ind) {
                swap(arr[largestInd], arr[ind]);

                heapifyDown(largestInd);
            }
            return;
        }
        public:
        void initializeHeap() {
            arr.clear();
            count = 0;
        }
        void insert (int key) {
            arr.push_back(key);
            heapifyUp(count);
            count = count + 1;
            return;
        }

        void changeKey(int index , int new_val) {
            if(arr[index] <= new_val) {
                arr[index] = new_val;
                heapifyUp(index);
            }else{
                arr[index] = new_val;
                heapifyDown(index);
            }
            return;
        }

        void extractMax() {
            int ele = arr[0];
            swap(arr[0], arr[count - 1]);
            arr.pop_back();
            count = count - 1;

            heapifyDown(0);
        } 
    bool isEmpty(){
        return (count == 0);
    }
    
    int getMax(){
        return arr[0];
    }
    
    int heapSize(){
        return count;
    }
};