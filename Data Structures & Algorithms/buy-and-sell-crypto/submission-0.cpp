#include<limits.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int len = prices.size();
        vector<int> maxval(len, INT_MIN);
        vector<int> minval(len, INT_MAX);
        minval[0] = prices[0];
        maxval[len - 1] = prices[len - 1];
        for(int i = 1; i < len; i++){
            minval[i] = min(minval[i - 1], prices[i]);
            maxval[len - i - 1] = max(maxval[len - i], prices[len - i - 1]);
        }
        for(int i = 0; i < len; i++){
            ans = max(maxval[i] - minval[i], ans);
        }
        return ans;
    }
};
