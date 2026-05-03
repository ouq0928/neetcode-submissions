#include<limits.h>
class Solution {
public:
    void bfs(vector<vector<int>> &grid, int m, int n){
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == INT_MAX){
                    q.push({{i, j}, 0});
                }
                while(!q.empty()){
                    auto pos_dist = q.front(); q.pop();
                    int x = pos_dist.first.first;
                    int y = pos_dist.first.second;
                    int dist = pos_dist.second;
                    if(grid[x][y] == 0){
                        grid[i][j] = dist;
                        while(!q.empty()) q.pop();
                        break;
                    }
                    if((x - 1 >= 0) && grid[x - 1][y] != -1){
                        q.push({{x - 1, y}, dist + 1});
                    }
                    if((x + 1 < m) && grid[x + 1][y] != -1){
                        q.push({{x + 1, y}, dist + 1});
                    }
                    if((y - 1 >= 0) && grid[x][y - 1] != -1){
                        q.push({{x, y - 1}, dist + 1});
                    }
                    if((y + 1 < n) && grid[x][y + 1] != -1){
                        q.push({{x, y + 1}, dist + 1});
                    }
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bfs(grid, m, n);
    }
};
