class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        long long tot = 1;
        int zero_pos = 0;
        int len = nums.size();
        int zero_cnt = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 0) {
                zero_cnt++;
                zero_pos = i;
                continue;
            }
            tot *= (long long)nums[i];
        }
        if(zero_cnt == 0){
            for(int i = 0; i < len; i++){
                ans.push_back(tot / (long long)nums[i]);
            }
        }
        else if(zero_cnt == 1){
            for(int i = 0; i < len; i++){
                if(i == zero_pos) ans.push_back(tot);
                else ans.push_back(0);
            }
        }else{
            for(int i = 0; i < len; i++) ans.push_back(0);
        }        
        return ans;
    }
};
