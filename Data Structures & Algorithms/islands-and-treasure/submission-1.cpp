#include<limits.h>
class Solution {
public:
    void bfs(vector<vector<int>> &grid, int m, int n){
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto pos = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int x = pos.first + dir[i].first;
                int y = pos.second + dir[i].second;
                if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != INT_MAX) continue;
                grid[x][y] = grid[pos.first][pos.second] + 1;
                q.push({x, y});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bfs(grid, m, n);
    }
};
