class Solution {
public:
    bool isValid(string s) {
        std::stack<char> mstack;
        unordered_map<char, char> mmap = {{')', '('}, {']', '['}, {'}', '{'}};
        for(char &c : s){
            if(mmap.count(c)){
                if(!mstack.empty() && mmap[c] == mstack.top()){
                    mstack.pop();
                }else return false;
            }else mstack.push(c);
        }
        if(!mstack.empty()) return false;
        return true;
    }
};
