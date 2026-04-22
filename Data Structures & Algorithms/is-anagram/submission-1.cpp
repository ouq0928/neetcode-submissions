#include<vector>
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt_s(256, 0);
        vector<int> cnt_t(256, 0);
        int len_s = s.size();
        int len_t = t.size();
        if(len_s != len_t) return false;
        for(int i = 0; i < len_s; i++){
            cnt_s[s[i]]++;
        }
        for(int i = 0; i < len_t; i++){
            cnt_t[t[i]]++;
        }
        for(int i = 0; i < 256; i++){
            if(cnt_s[i] != cnt_t[i]) return false;
        }
        return true;
    }
};
