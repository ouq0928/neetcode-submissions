class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> orig = nums;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(i > 1 && nums[i - 1] == nums[i - 2]){
                    dp[i][j] = dp[i - 1][j];
                }
                else if(nums[i - 1] == orig[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // for(int i = 1; i <= len; i++){
        //     for(int j = 1; j <= len; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[len][len];
    }
};
