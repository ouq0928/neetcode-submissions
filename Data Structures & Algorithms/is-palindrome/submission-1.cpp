class Solution {
public:
    bool isValid(char &c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0; int r = s.size() - 1;
        while(l <= r){
            while(l < r && !isValid(s[l])) l++;
            while(l < r && !isValid(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++; r--;
        }
        return true;
    }
};
