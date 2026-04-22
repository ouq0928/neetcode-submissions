class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {        
        std::stack<std::pair<int, int>> stk;
        int len = temperatures.size();
        vector<int> ans(len, 0);
        for(int i = 0; i < len; i++){
            int t = temperatures[i];
            while(!stk.empty() && t > stk.top().first){
                auto top = stk.top();
                stk.pop();
                ans[top.second] = i - top.second;
            }
            stk.push({t, i});
        }
        return ans;
    }
};
