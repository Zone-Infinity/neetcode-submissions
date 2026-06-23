class Solution {
    private:
    void bfs(vector<vector<int>>& grid) {

    }
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<pair<int, int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;

                if (ni < 0 || ni >= grid.size() ||
                    nj < 0 || nj >= grid[0].size() ||
                    grid[ni][nj] != INT_MAX) {
                    continue;
                }

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
};
