class Solution {
   private:
    void dfs(int i, int j, vector<vector<bool>>& safe, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) return;
        if (safe[i][j] || board[i][j] == 'X') return;
        safe[i][j] = true;

        dfs(i + 1, j, safe, board);
        dfs(i - 1, j, safe, board);
        dfs(i, j + 1, safe, board);
        dfs(i, j - 1, safe, board);
    }

   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> safe(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, safe, board);
            dfs(i, n - 1, safe, board);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, safe, board);
            dfs(m - 1, j, safe, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!safe[i][j]) board[i][j] = 'X';
            }
        }
    }
};
