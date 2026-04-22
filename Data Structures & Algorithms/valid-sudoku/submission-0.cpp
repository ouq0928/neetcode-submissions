class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++){
            unordered_set<char> seen;
            for(int j = 0; j < 9; j++){
                if(board[row][j] == '.') continue;
                if(seen.count(board[row][j])) return false;
                seen.insert(board[row][j]);
            }
        }
        for(int col = 0; col < 9; col++){
            unordered_set<char> seen;
            for(int j = 0; j < 9; j++){
                if(board[j][col] == '.') continue;
                if(seen.count(board[j][col])) return false;
                seen.insert(board[j][col]);
            }
        }
        for(int square = 0; square < 9; square++){
            unordered_set<char> seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
