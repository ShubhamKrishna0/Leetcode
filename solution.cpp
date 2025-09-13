class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> h(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
            maxArea = max(maxArea, largestRect(h));
        }
        return maxArea;
    }
    
private:
    int largestRect(vector<int>& h) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= h.size(); i++) {
            while(!st.empty() && (i == h.size() || h[st.top()] > h[i])) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};