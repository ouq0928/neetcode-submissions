class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //cout << m << " " << n << "\n";
        int top = 0; int bottom = m - 1;
        int row;
        while(top <= bottom){
            row = (top + bottom) / 2; 
            if(target > matrix[row][n - 1]) top = row + 1;
            else if(target < matrix[row][0]) bottom = row - 1;
            else break;
        }
        int l = 0; int r = n - 1;
        int col;
        while(l <= r){
            col = (l + r) / 2;
            cout << col;
            if(matrix[row][col] > target) r = col - 1;
            else if(matrix[row][col] < target) l = col + 1;
            else break;
        }
        //cout << row << " " << col << "\n";
        return matrix[row][col] == target;
    }
};
