class Solution {
private:
    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (i == coins.size() || amount < 0) return 0;

        if (memo[i][amount] != -1) return memo[i][amount];

        int take = dfs(i, amount - coins[i], coins, memo);
        int skip = dfs(i + 1, amount, coins, memo);

        return memo[i][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, memo);
    }
};