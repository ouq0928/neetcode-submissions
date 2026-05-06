class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        int sz = 0;
        bool flag = false;
        for(int &n : nums){
            if(sz == k) flag = true;
            if(flag){
                minHeap.push(n);
                minHeap.pop();
            }else{
                minHeap.push(n);
                sz++;
            }
        }
        return minHeap.top();
    }
};
// 5 6