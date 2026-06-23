class Solution {
private:
    int dfs(int i, int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(i == coins.size() || amount < 0) return 0;
        return dfs(i, amount - coins[i], coins) + dfs(i + 1, amount - coins[i], coins);
    }
public:
    int change(int amount, vector<int>& coins) {
        return dfs(0, amount, coins);
    }
};
