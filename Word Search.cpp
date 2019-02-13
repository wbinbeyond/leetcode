class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int d, int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size()) {
            return false;
        }
        if (visited[x][y] || board[x][y] != word[d]) return false;
        if (d == word.size() - 1) {
            return true;
        }
        visited[x][y] = true;
        bool found = dfs(board, word, d+1, x+1, y, visited) 
                  || dfs(board, word, d+1, x-1, y, visited)
                  || dfs(board, word, d+1, x, y+1, visited)
                  || dfs(board, word, d+1, x, y-1, visited);
        visited[x][y] = false;
        return found;
    }
};
