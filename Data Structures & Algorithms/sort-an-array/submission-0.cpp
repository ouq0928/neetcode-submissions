class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergesort(vector<int> &arr, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    void merge(vector<int> &arr, int l, int m, int r){
        int i = l; int j = m + 1;
        vector<int> temp;
        while(i <= m && j <= r){
            if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while(i <= m) temp.push_back(arr[i++]);
        while(j <= r) temp.push_back(arr[j++]);
        for(int k = l; k <= r; k++){
            arr[k] = temp[k - l];
        }
    }
};