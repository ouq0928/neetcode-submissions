class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> indices;
        for(int i = 0; i < len; i++){
            indices[nums[i]] = i;
        }
        for(int i = 0; i < len; i++){
            int diff = target - nums[i];
            if(indices.count(diff) && indices[diff] != i){
                return {i, indices[diff]};
            }
        }
    }
};
