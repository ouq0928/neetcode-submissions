class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int idx;
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        for(int &n : nums){
            minHeap.push(n);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > idx){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
