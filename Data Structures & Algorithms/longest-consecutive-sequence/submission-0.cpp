class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int ans = 0;
        for(auto num : num_set){
            //cout << num << "\n";
            if(num_set.find(num - 1) == num_set.end()){
                int len = 1;
                while(num_set.find(num + len) != num_set.end()) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
