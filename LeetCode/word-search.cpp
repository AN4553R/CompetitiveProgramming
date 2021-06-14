class Solution {
    int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
        
    bool search(vector<vector<char>> &board, string word, int idx, int r, int c) {
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }
        
        if (idx == word.size() - 1) {
            return true;
        }
        
        bool found = false;
        
        char tmp = board[r][c];
        
        board[r][c] = '.';
        
        for(int itr = 0; itr < 4; itr++) {
            found|=search(board, word, idx + 1, r + dx[itr], c + dy[itr]);
        }
        
        board[r][c] = tmp;
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                
                if(board[row][col] == word[0] && search(board, word, 0, row, col)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
