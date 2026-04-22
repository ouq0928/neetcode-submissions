class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int max_vol = 0;
        while(l != r){
            int cur_vol = (nums[l] < nums[r] ? nums[l] : nums[r]) * (r - l);
            max_vol = max(max_vol, cur_vol);
            if(nums[l] < nums[r]) l++;
            else r--;
        }
        return max_vol;
    }
};
