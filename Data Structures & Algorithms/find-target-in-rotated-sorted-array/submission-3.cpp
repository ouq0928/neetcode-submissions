class Solution {
public:
    int bs(vector<int> &arr, int l, int r, int target){
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m] > target) r = m - 1;
            else if(arr[m] < target) l = m + 1;
            else return m;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while(l < r){
            if(nums[l] < nums[r]) break;
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int pivot = l;
        int res = bs(nums, pivot, nums.size(), target);
        if(nums[res] == target) return res;
        res = bs(nums, 0, pivot - 1, target);
        if(nums[res] == target) return res;
        return -1;
    }
};
