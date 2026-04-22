class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        for(auto &s : strs){
            sizes.push_back(s.size());
        }
        string res = "";
        for(int &len : sizes){
            res += to_string(len) + ",";
        }
        res += "@";
        for(auto &ss : strs){
            res += ss;
        }
        return res;
    }
    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> res;
        vector<int> sizes;
        int i = 0;
        while(s[i] != '@'){
            string cur = "";
            while(s[i] != ','){
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }
        i++;
        for(int &len : sizes){
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
