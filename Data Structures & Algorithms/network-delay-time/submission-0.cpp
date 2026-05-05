class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for(auto &t : times){
            edges[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});
        set<int> visited;
        int t = 0;
        while(!minHeap.empty()){
            auto cur = minHeap.top(); minHeap.pop();
            int time = cur.first;
            int node = cur.second;
            if(visited.count(node)){
                continue;
            }
            visited.insert(node);
            t = time;
            if(edges.count(node)){
                for(auto &next : edges[node]){
                    int next_node = next.first;
                    int next_w = next.second;
                    if(!visited.count(next_node)){
                        minHeap.push({next_w + time, next_node});
                    }
                }
            }
        }
        if(visited.size() == n) return t;
        return -1;
    }
};
