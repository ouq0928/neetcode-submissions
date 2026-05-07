#include<limits.h>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 5, INT_MAX));
        for(auto &v : flights){
            adj[v[0]].push_back({v[1], v[2]});
        }
        dist[src][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0, src, -1);
        while(!minHeap.empty()){
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();
            if(node == dst) return cost;
            if(k == stops || dist[node][stops + 1] < cost) continue;
            for(auto &p : adj[node]){
                int nxt_cost = cost + p.second;
                int nxt_stops = stops + 1;
                if(dist[p.first][nxt_stops + 1] > nxt_cost){
                    dist[p.first][nxt_stops + 1] = nxt_cost;
                    minHeap.emplace(nxt_cost, p.first, nxt_stops);
                }
            }
        }
        return -1;
    }
};
