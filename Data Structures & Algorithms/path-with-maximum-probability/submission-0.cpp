class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        int len = succProb.size();
        for(int i = 0; i < len; i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> maxHeap;
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        maxHeap.push({1, start_node});
        while(!maxHeap.empty()){
            pair<double, int> cur = maxHeap.top(); maxHeap.pop();
            double curp = cur.first;
            int cur_idx = cur.second;
            if(cur_idx == end_node) return curp;
            for(pair<int, double> &nei : adj[cur_idx]){
                double nextp = nei.second;
                int next = nei.first;
                if(nextp * curp > dist[next]){
                    dist[next] = nextp * curp;
                    maxHeap.push({nextp * curp, next});
                }
            }
        }
        return 0;
    }
};