#include<cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size();
        int l = 1; int r = *max_element(piles.begin(), piles.end());
        int res = r;
        while(l <= r){
            int mid = l + (r - l) / 2;
            long long hour = 0;
            for(int i = 0; i < len; i++){
                hour += (int)ceil((double)piles[i] / (double)mid);
            }
            if(hour <= h) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};
