class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minP = prices[0];
        for(int &sell : prices){
            ans = max(sell - minP, ans);
            minP = min(minP, sell);
        }
        return ans;
    }
};
