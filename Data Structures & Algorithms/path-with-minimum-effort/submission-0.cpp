class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({0, {0, 0}});
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!minHeap.empty()){
            auto cur = minHeap.top(); minHeap.pop();
            int diff = cur.first;
            int cur_x = cur.second.first;
            int cur_y = cur.second.second;
            if(cur_x == m - 1 && cur_y == n - 1) return diff;
            if(diff > dist[cur_x][cur_y]) continue;
            for(int i = 0; i < 4; i++){
                int x = cur_x + dir[i].first;
                int y = cur_y + dir[i].second;
                if(x < 0 || y < 0 || x >= m || y >= n) continue;
                int next_diff = max(diff, abs(heights[x][y] - heights[cur_x][cur_y]));
                if(next_diff < dist[x][y]){
                    dist[x][y] = next_diff;
                    minHeap.push({next_diff, {x, y}});
                }
            }
        }
        return 0;
    }
};