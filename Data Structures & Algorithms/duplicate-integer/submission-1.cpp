#include<algorithm>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int &num : nums){
            if(st.count(num)) return true;
            else st.insert(num);
        }
        return false;
    }
};