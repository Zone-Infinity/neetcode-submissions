class Solution {
   private:
    int dfs(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int skip = dfs(i + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + dfs(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(skip, take);
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(0, -1, nums, dp);
    }
};
