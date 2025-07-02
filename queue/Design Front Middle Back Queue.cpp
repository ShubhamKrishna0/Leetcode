//https://leetcode.com/problems/design-front-middle-back-queue/description/

/*
design a queue that support push and pop operation in the front and the middle and back
*/

#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
    private:
        vector<int> fmbq;

    public:
    FrontMiddleBackQueue() {}

    void pushFront (int val) {
        fmbq.insert(fmbq.begin(), val);
    }

    void pushMiddle (int val) {
        int middle = fmbq.size() / 2;
        fmbq.insert(fmbq.begin() + middle, val);
    }
    void pushBack (int val) {
        fmbq.push_back(val);
    }
    int popMiddle() {
        if(fmbq.empty())
            return -1;
            
    }
};