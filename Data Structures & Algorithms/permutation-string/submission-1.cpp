class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_sz = s1.size();
        int len2 = s2.size();
        if(window_sz > len2) return false;
        vector<int> freq_win(26, 0);
        for(char &c : s1){
            freq_win[c - 'a']++;
        }
        vector<int> freq(26, 0);
        for(int i = 0; i < window_sz; i++){
            freq[s2[i] - 'a']++;
        }
        for(int i = 0; i <= len2 - window_sz; i++){
            for(int j = 0; j < 26; j++){
                if(freq[j] != freq_win[j]){
                    break;
                }
                if(j == 25) return true;
            }
            freq[s2[i + window_sz] - 'a']++;
            freq[s2[i] - 'a']--;
            // cout << "\n\n";
            // for(int i = 0; i < 26; i++){
            // cout << freq_win[i] << " ";
            // }
            // cout << "\n";
            // for(int i = 0; i < 26; i++){
            //     cout << freq[i] << " ";
            // }
        }
        return false;
    }
};
