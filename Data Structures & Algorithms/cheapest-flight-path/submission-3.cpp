class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> temp = dist;
            for(vector<int> &f : flights){
                int from = f[0];
                int to = f[1];
                int price = f[2];
                if(dist[from] == INT_MAX) continue;
                if(price + dist[from] < temp[to]){
                    temp[to] = price + dist[from];
                }
            }
            dist = temp;
        }   
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
