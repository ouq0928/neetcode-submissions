class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size();
        while(l <= r){
            int mid = l + (r - l) / 2;
            cout << mid << "\n";
            if(nums[mid] > target) r = mid - 1;
            else if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] == target) return mid;
        }
        return -1;
    }
};
