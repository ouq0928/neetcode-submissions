class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        countingsort(nums);
        return nums;
    }
    void countingsort(vector<int> &arr){
        int max_val = *max_element(arr.begin(), arr.end());
        int min_val = *min_element(arr.begin(), arr.end());
        unordered_map<int, int> freq;
        for(int &n : arr){
            freq[n]++;
        }
        int i = 0;
        for(int j = min_val; j <= max_val; j++){
            while(freq[j] > 0){
                arr[i] = j;
                i++; freq[j]--;
            }
        }
    }
};