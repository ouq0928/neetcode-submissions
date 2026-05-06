class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct cmp{
            bool operator()(const vector<int> &a, const vector<int> &b){
                return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]); 
            }
        };
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, cmp> minHeap;
        for(vector<int> &v : points){
            minHeap.push(v);
        }
        while(k--){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};
