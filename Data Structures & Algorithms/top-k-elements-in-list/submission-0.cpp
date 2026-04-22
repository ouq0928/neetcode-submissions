class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int &n : nums){
            freq[n]++;
        }
        vector<vector<int>> bucket(nums.size() + 1, vector<int>());
        for(const auto &idx_cnt : freq){
            bucket[idx_cnt.second].push_back(idx_cnt.first);
        }
        vector<int> ans;
        for(int i = bucket.size() - 1; i >= 0; --i){
            for(int &val : bucket[i]){
                ans.push_back(val);
                k--;
                if(k == 0) return ans;
            }
        }
        return {};
    }
};
