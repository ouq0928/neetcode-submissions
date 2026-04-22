class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0; int maxfreq = 0;
        int ans = 0;
        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;
            maxfreq = max(freq[s[r]], maxfreq);
            while((r - l + 1) - maxfreq > k){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
