#include<algorithm>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len ; i++){
            if(nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};