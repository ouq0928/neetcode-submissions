#include<limits.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0; int r = 1;
        while(r < prices.size()){
            if(prices[r] > prices[l]){
                ans = max(ans, prices[r] - prices[l]);
            }else l = r;
            r++;
        }
        return ans;
    }
};
