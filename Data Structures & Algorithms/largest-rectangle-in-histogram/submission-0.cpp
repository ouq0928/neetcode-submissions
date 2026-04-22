class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> leftmost(len, -1);
        vector<int> rightmost(len, len);
        stack<int> stk;
        for(int i = 0; i < len; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                leftmost[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i = len - 1; i >= 0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rightmost[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < len; i++){
            ans = max(ans, (rightmost[i] - leftmost[i] - 1) * heights[i]);
        }
        return ans;
    }
};
