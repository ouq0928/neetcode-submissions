class Solution {
public:
    int ans = 0;
    void bfs(vector<vector<char>> &grid, int m, int n){
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool island = false;
        // cout << "m = " << m << ", " << "n = " << n << "\n";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    // cout << "(" << i << "," << j << ")\n";
                    q.push({i, j});
                    visited[i][j] = true;
                    island = true;
                }else continue;
                while(!q.empty()){
                    pair<int, int> pos = q.front(); q.pop();
                    // cout << "(" << pos.first << "," << pos.second << ")\n";
                    if((pos.first - 1 >= 0) && (grid[pos.first - 1][pos.second] == '1') && (!visited[pos.first - 1][pos.second])){
                        q.push({pos.first - 1, pos.second});
                        visited[pos.first - 1][pos.second] = true;
                        // cout << "1\n";
                    }
                    if((pos.first + 1 < m) && (grid[pos.first + 1][pos.second] == '1') && (!visited[pos.first + 1][pos.second])){
                        q.push({pos.first + 1, pos.second});
                        visited[pos.first + 1][pos.second] = true;
                        // cout << "2\n";
                    }
                    if((pos.second - 1 >= 0) && (grid[pos.first][pos.second - 1] == '1') && (!visited[pos.first][pos.second - 1])){
                        q.push({pos.first, pos.second - 1});
                        visited[pos.first][pos.second - 1] = true;
                        // cout << "3\n";
                    }
                    if((pos.second + 1 < n) && (grid[pos.first][pos.second + 1] == '1') && (!visited[pos.first][pos.second + 1])){
                        q.push({pos.first, pos.second + 1});
                        visited[pos.first][pos.second + 1] = true;
                        // cout << "4\n";
                    }
                }
                if(island){
                    // cout << "(" << i << "," << j << ")\n";
                    ans++;
                    island = false;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bfs(grid, m, n);
        return ans;
    }
};
