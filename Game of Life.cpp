class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /**
         *
                       this round     next round
         state 0:           0             0
         state 1:           1             1
         state 2:           1             0
         state 3:           0             1
        */
        
        int m = board.size(),
            n = m ? board[0].size() : 0;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int lives = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && 
                        (board[x][y] == 1 || board[x][y] == 2)) {
                        // this round it is 1
                        lives++;
                    }
                }
                
                if (board[i][j] == 1 && (lives < 2 || lives > 3)) {
                    board[i][j] = 2;  // 1 to 0
                }
                else if (board[i][j] == 0 && lives == 3) {
                    board[i][j] = 3;  // 0 to 1
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
