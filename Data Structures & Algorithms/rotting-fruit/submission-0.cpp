class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt_fresh = 0;
        int res = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) cnt_fresh++;
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        cout << cnt_fresh << "\n";
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int row = cur.first.first;
            int col = cur.first.second;
            int dist = cur.second;
            res = max(res, dist);
            for(int i = 0; i < 4; i++){
                int x = row + dir[i].first;
                int y = col + dir[i].second;
                if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1 || visited[x][y]) continue;
                q.push({{x, y}, dist + 1});
                visited[x][y] = true;
                cnt_fresh--;
            }
        }
        if(cnt_fresh > 0) return -1;
        return res;
    }
};
