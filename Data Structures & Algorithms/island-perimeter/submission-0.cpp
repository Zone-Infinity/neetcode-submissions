class Solution {
   private:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) return 0;
        if (grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(i + 1, j, grid) + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) +
               dfs(i, j - 1, grid);
    }

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    count = dfs(i, j, grid);
                    break;
                }
            }
        }
        if (count == 0) return 0;
        if (count == 1) return 4;
        return 6 + 2 * (count - 2);
    }
};