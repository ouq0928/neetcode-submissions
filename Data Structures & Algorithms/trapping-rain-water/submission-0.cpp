class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> prefix(len, 0);
        prefix[0] = height[0];
        vector<int> suffix(len, 0);
        suffix[len - 1] = height[len - 1];
        for(int i = 1; i < len; i++){
            prefix[i] = max(prefix[i - 1], height[i]);
            suffix[len - i - 1] = max(suffix[len - i], height[len - i - 1]);
        }
        int ans = 0;
        for(int i = 0; i < len; i++){
            ans += min(prefix[i], suffix[i]) - height[i];
        }
        return ans;
    }
};
