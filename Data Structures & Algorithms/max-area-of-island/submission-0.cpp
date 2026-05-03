class Solution {
public:
    int bfs(vector<vector<int>> &grid, int res, int m, int n){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cur = 0;
                if(grid[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = true;
                    q.push({i, j});
                    cur += 1;
                }else continue;
                while(!q.empty()){
                    pair<int, int> pos = q.front(); q.pop();
                    if((pos.first - 1) >= 0 && (grid[pos.first - 1][pos.second] == 1) && (!visited[pos.first - 1][pos.second])){
                        q.push({pos.first - 1, pos.second});
                        visited[pos.first - 1][pos.second] = true;
                        cur += 1;
                    }
                    if((pos.first + 1) < m && (grid[pos.first + 1][pos.second] == 1) && (!visited[pos.first + 1][pos.second])){
                        q.push({pos.first + 1, pos.second});
                        visited[pos.first + 1][pos.second] = true;
                        cur += 1;
                    }
                    if((pos.second - 1) >= 0 && (grid[pos.first][pos.second - 1] == 1) && (!visited[pos.first][pos.second - 1])){
                        q.push({pos.first, pos.second - 1});
                        visited[pos.first][pos.second - 1] = true;
                        cur += 1;
                    }
                    if((pos.second + 1) < n && (grid[pos.first][pos.second + 1] == 1) && (!visited[pos.first][pos.second + 1])){
                        q.push({pos.first, pos.second + 1});
                        visited[pos.first][pos.second + 1] = true;
                        cur += 1;
                    }
                }
                res = max(res, cur);
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return bfs(grid, 0, m, n);
    }
};
