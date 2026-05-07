class UF{
public:
    vector<int> parent, size;
    UF(int n) : parent(n + 1), size(n + 1, 1){
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int find(int n){
        if(parent[n] != n){
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }
    bool unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(size[pu] < size[pv]) swap(pu, pv);
        size[pu] += size[pv];
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UF dsu(n);
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        for(pair<int, pair<int, int>> &p : edges){
            if(dsu.unionSet(p.second.first, p.second.second)){
                res += p.first;
            }
        }
        return res;
    }
};
