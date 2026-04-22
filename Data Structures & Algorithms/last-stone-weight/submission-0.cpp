class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxheap;
        for(int &n : stones){
            maxheap.push(n);
        }
        while(maxheap.size() > 1){
            int x = maxheap.top(); maxheap.pop();
            int y = maxheap.top(); maxheap.pop();
            if(x < y){
                maxheap.push(y - x);
            }else if(x > y){
                maxheap.push(x - y);
            }else continue;
        }
        if(maxheap.empty()) return 0;
        else return maxheap.top();
    }
};
