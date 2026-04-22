class Solution {
public:
    int bs(vector<int> &nums, int nums_size, int from, int target){
        int l = from; int r = nums_size - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target) r = mid - 1;
            else if(nums[mid] < target) l = mid + 1;
            else return mid;
        }
        return 0;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if(len == 2) return {1, 2};
        for(int i = 0; i < len; i++){
            int l = i + 1; int r = len - 1;
            int check = bs(numbers, len, l, target - numbers[i]);
            if(numbers[check] != target - numbers[i]) continue;
            else return {i + 1, check + 1};
        }
        return {};
    }
};
