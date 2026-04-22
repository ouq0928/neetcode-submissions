class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ans = 0;
        int l = 0;
        unordered_set<char> seen;
        for(int r = 0; r < len; r++){
            while(seen.find(s[r]) != seen.end()){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            ans = max(ans, r - l + 1);            
        }
        return ans;
    }
};