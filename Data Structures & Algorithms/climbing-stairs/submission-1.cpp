vector<int> dp(46, 0);
class Solution {
public:
    int cal(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n - 1] > 0 && dp[n - 2] > 0) return dp[n - 1] + dp[n - 2];
        else if(dp[n - 1] == 0 && dp[n - 2] > 0) return cal(n - 1) + dp[n - 2];
        else if(dp[n - 2] == 0 && dp[n - 1] > 0) return cal(n - 2) + dp[n - 1];
        else{
            dp[n] = cal(n - 1) + cal(n - 2);
            return dp[n];
        }
    }
    int climbStairs(int n) {
        return cal(n);
    }
};
