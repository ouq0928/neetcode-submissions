class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &f : flights){
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adj[from].push_back({to, cost});
        }
        dist[src][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({0, {src, -1}});
        while(!minHeap.empty()){
            pair<int, pair<int, int>> cur = minHeap.top(); minHeap.pop();
            int now = cur.second.first;
            int cost = cur.first;
            int passed = cur.second.second;
            if(now == dst){
                return cost;
            }
            for(pair<int, int> &nei : adj[now]){
                int ncost = nei.second;
                int to = nei.first;
                if(passed + 1 <= k && ncost + cost <= dist[to][passed + 1]){
                    dist[to][passed + 1] = ncost + cost;
                    minHeap.push({ncost + cost, {to, passed + 1}});
                }
            }
        }
        return -1;
    }
};
